#include <malloc.h>
#include <pthread.h>
#include <stdio.h>
/*The key used to associate a log file pointer with each thread.*/
static pthread_key_t thread_log_key;

/*Write MESSAGE to the log file for the current thread.*/
void write_to_thread_log (const char* message)
{
    FILE* thread_log = (FILE*) pthread_getspecific (thread_log_key);
    fprintf (thread_log, "%s\n", message);
}

/* Close the log file pointer THREAD_LOG.
 * */
void close_thread_log (void* thread_log)
{
    printf("begin clean file description...\n");
    fclose ((FILE*) thread_log);
}

void* thread_function (void* args)
{
    char thread_log_filename[50];
    FILE* thread_log;
    printf("thread_id:%ld\n", (long)pthread_self());
    /* Generate the filename for this thread’s log file. */
    sprintf (thread_log_filename, "thread%ld.log", (long) pthread_self());
    /* Open the log file. */
    thread_log = fopen (thread_log_filename, "w");
    /*Store the file pointer in thread-specific data under thread_log_key.*/
    pthread_setspecific (thread_log_key, thread_log);

    write_to_thread_log ("Thread starting...");
    /* Do work here... */
    printf("all right here...\n");
    sleep(2);
    return 0;
}

int main ()
{
    int i;
    int thread_num = 5;
    pthread_t threads[thread_num];

    /* Create a key to associate thread log file pointers in
     * thread-specific data. Use close_thread_log to clean up the file
     * pointers. */
    pthread_key_create (&thread_log_key, close_thread_log);

    /* Create threads to do the work. */
    for (i = 0; i < thread_num; ++i)
        pthread_create (&(threads[i]), NULL, thread_function, NULL);

    /* Wait for all threads to finish. */
    for (i = 0; i < thread_num; ++i)
        pthread_join (threads[i], NULL);
    return 0;
}
