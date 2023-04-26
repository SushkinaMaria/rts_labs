#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sched.h>

#include "threads/threads.h"

pthread_t thread_id1;
pthread_t thread_id2;

pthread_attr_t thread_attr1;
pthread_attr_t thread_attr2;

#define PTHREADS_NUM 2

int wait_threads(pthread_t *pthreads, int pthreads_num)
{
    for (int i=0; i<pthreads_num; i++) {
        int ret = pthread_join(pthreads[i], NULL);
        if (ret) {
            return ret;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int ret;
    printf("Prog threads PID %d\n", getpid());

    pthread_attr_init(&thread_attr1);
    pthread_attr_init(&thread_attr2);

    ret = pthread_attr_setschedpolicy(&thread_attr1, SCHED_RR);
    if (ret) {
        perror("setschedpolicy thread 1 error");
        return -1;
    }
    ret = pthread_attr_setschedpolicy(&thread_attr2, SCHED_FIFO);
    if (ret) {
        perror("setschedpolicy thread 2 error");
        return -1;
    }
    ret = pthread_setschedprio(thread_id1, 10);
    if (!ret) {
        printf("setschedprio thread 1 error: %d\n", ret);
        return -1;
    }
    ret = pthread_setschedprio(thread_id2, 8);
    if (!ret) {
        printf("setschedprio thread 2 error: %d\n", ret);
        return -1;
    }

    pthread_create(&thread_id1, &thread_attr1, long_thread1, NULL);
    pthread_create(&thread_id2, &thread_attr2, long_thread2, NULL);

    pthread_t *pthreads_to_wait = (pthread_t*) malloc(PTHREADS_NUM*sizeof(pthread_t));
    pthreads_to_wait[0] = thread_id1;
    pthreads_to_wait[1] = thread_id2;

    ret = wait_threads(pthreads_to_wait, PTHREADS_NUM);
    if (ret) {
        printf("wait_threads error: %d\n", ret);
        return -1;
    }

    return 1;
}
