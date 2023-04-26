#ifndef THREADS_H
#define THREADS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h> 
#include <unistd.h> 

extern void* long_thread1(void *notused);
extern void* long_thread2(void *notused);

#endif