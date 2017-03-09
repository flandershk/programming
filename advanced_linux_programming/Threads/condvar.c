#include <pthread.h>
#include <stdio.h>
int thread_flag;
pthread_cond_t thread_flag_cv;
pthread_mutex_t thread_flag_mutex;

void initialize_flag ()
{
    pthread_mutex_init (&thread_flag_mutex, NULL);
    pthread_cond_init(&thread_flag_cv, NULL);
    thread_flag = 0;
}

void do_work()
{
    printf("do work...\n");
}

void* thread_function (void* thread_arg)
{
    /* Loop infinitely. */
    while (1) {
        printf("wait...\n");
        sleep(3);
        /* Lock the mutex before accessing the flag value. */
        pthread_mutex_lock (&thread_flag_mutex);
        while (!thread_flag)
        {
            /* The flag is clear. Wait for a signal on the condition
               variable, indicating that the flag value has changed. When the
               signal arrives and this thread unblocks, loop and check the
               flag again. */
            pthread_cond_wait (&thread_flag_cv, &thread_flag_mutex);
        }
        /* When we’ve gotten here, we know the flag must be set. Unlock
           the mutex. */
        pthread_mutex_unlock (&thread_flag_mutex);
        /* Do some work. */
        do_work ();
    }
    return NULL;
}

/*Sets the value of the thread flag to FLAG_VALUE.*/
void set_thread_flag (int flag_value)
{
    /*Protect the flag with a mutex lock. */
    pthread_mutex_lock (&thread_flag_mutex);
    thread_flag = flag_value;
    pthread_cond_signal(&thread_flag_cv);
    pthread_mutex_unlock (&thread_flag_mutex);
}

int main()
{
    initialize_flag();
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, &thread_function, NULL);
    printf("flag not set...\n");
    sleep(10);
    set_thread_flag(1);
    printf("flag alredey set...\n");
    pthread_join(thread_id, NULL);
    return 0;
}
