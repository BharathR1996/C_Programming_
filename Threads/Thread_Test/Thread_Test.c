#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/*
 * POSIX thread API declarations provided by <pthread.h>:
 * int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
 *                    void *(*start_routine)(void *), void *arg);
 * int pthread_join(pthread_t thread, void **retval);
 *
 * pthread_create starts start_routine in a new thread. The routine must
 * accept and return void pointers; arg is passed to it, and attr may be NULL
 * to use the default thread attributes. pthread_join waits for the specified
 * thread to finish; retval may be NULL when its return value is not needed.
 * Both functions return 0 on success or an error number on failure.
 *
 * Reference: https://randu.org/tutorials/threads/
 */

/* Thread entry point: receives the argument supplied to pthread_create. */
void *myFun1(void *arg)
{
    (void)arg;

    for(int i = 0; i < 8; i++)
    {
        sleep(1);
        printf("My function 1 = %d\n", i);
    }
    return NULL;
}

void myFun2(void * arg)
{
    (void)arg;

    for(int i = 0; i < 3; i++)
    {
        sleep(2);
        printf("My function 2 = %d\n", i);
    }
}

int main(void)
{
    pthread_t myThread;

    /* Start myFun1 on a new thread, using default attributes and no argument. */
    pthread_create(&myThread, NULL, myFun1, NULL);

    /* Run myFun2 on the main thread while myFun1 runs concurrently. */
    myFun2(NULL);    
    
    /* Wait for myFun1 to finish; its return value is not needed. */
    pthread_join(myThread, NULL);
    return 0;
}