#include "threads.h"

void* long_thread1(void *notused)
{
    int n;
    for (n=0; n<5; n++) {
        printf("First thread, TID %ld - N of repeat %d\n", pthread_self(), n);
        sleep(2);
    }

    return NULL;
}

void* long_thread2(void *notused) 
{
    int m;
    for (m=0; m<5; m++) {
        printf("Second thread, TID %ld - N of repeat %d\n", pthread_self(), m);
        sleep(1);
    }

    return NULL;
}