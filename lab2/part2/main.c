#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sched.h>

#include "threads/threads.h"

pthread_t thread_id1;
pthread_t thread_id2;

struct sched_param param1 = {10};
struct sched_param param2 = {8};

#define PTHREADS_NUM 2

int wait_threads(pthread_t *pthreads, int pthreads_num)
{
    int ret;
    int i;
    for (i=0; i<pthreads_num; i++) {
        ret = pthread_join(pthreads[i], NULL);
        if (ret) {
            return ret;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int ret;
    pthread_t *pthreads_to_wait;
    printf("Prog threads PID %d\n", getpid());

    ret = pthread_setschedparam(thread_id1, SCHED_RR, &param1);
    if (!ret) {
        printf("setschedprio thread 1 error: %d\n", ret);
        return -1;
    }
    ret = pthread_setschedparam(thread_id2, SCHED_FIFO, &param2);
    if (!ret) {
        printf("setschedprio thread 2 error: %d\n", ret);
        return -1;
    }

    pthread_create(&thread_id1, NULL, long_thread1, NULL);
    pthread_create(&thread_id2, NULL, long_thread2, NULL);

    pthreads_to_wait = (pthread_t*) malloc(PTHREADS_NUM*sizeof(pthread_t));
    pthreads_to_wait[0] = thread_id1;
    pthreads_to_wait[1] = thread_id2;

    ret = wait_threads(pthreads_to_wait, PTHREADS_NUM);
    if (ret) {
        printf("wait_threads error: %d\n", ret);
        return -1;
    }

    return 1;
}
