#include <malloc.h>
#include <pthread.h>
struct job {
    /*Link field for linked list.*/
    struct job* next;

    /* Other fields describing work to be done... */
    int value;
};

/*A linked list of pending jobs.*/
struct job* job_queue;

/* A mutex protecting job_queue. */
pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;

void process_job(struct job* job)
{
    printf("now thread: %d finish the job: %d\n", (int)pthread_self(), job->value);
}

/* Process queued jobs until the queue is empty.
 * Synchronization and Critical Sections
 * */
void* thread_function (void* arg)
{
    while (1) {
        struct job* next_job;
        /* Lock the mutex on the job queue. */
        pthread_mutex_lock (&job_queue_mutex);
        /* Now it’s safe to check if the queue is empty. */
        if (job_queue == NULL)
            next_job = NULL;
        else {
            /* Get the next available job. */
            next_job = job_queue;
            /* Remove this job from the list. */
            job_queue = job_queue->next;
        }
        /* Unlock the mutex on the job queue because we’re done with the
         * queue for now. */
        pthread_mutex_unlock (&job_queue_mutex);
        /*Was the queue empty?*/
        if (next_job == NULL)
            break;
        /*If so, end the thread.*/

        /* Carry out the work. */
        process_job (next_job);
        /* Clean up. */
        free (next_job);
    }
    return NULL;
}

int main()
{
    int job_size = 1000;
    int thread_num = 5;
    int i;
    struct job* jobs_pre = (struct job*) malloc(sizeof(struct job));
    jobs_pre->value = 0;
    jobs_pre->next = NULL;
    job_queue = jobs_pre;
    for (i = 1; i < job_size; i++)
    {
        struct job* jobs = (struct job*)malloc(sizeof(struct job));
        jobs->value = i;
        jobs_pre->next = jobs;
        jobs_pre = jobs;
        jobs->next = NULL;
    }

    pthread_t thread_id[thread_num];
    for (i = 0; i < thread_num; i++)
        pthread_create(&thread_id[i], NULL, &thread_function, NULL);
    for (i = 0; i < thread_num; i++)
        pthread_join(thread_id[i], NULL);
    return 0;
}
