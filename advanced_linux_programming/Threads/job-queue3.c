#include <malloc.h>
#include <pthread.h>
#include <semaphore.h>

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

/*A semaphore counting the number of jobs in the queue.*/
sem_t job_queue_count;

/* Perform one-time initialization of the job queue.
*/
void initialize_job_queue ()
{
    /* The queue is initially empty. */
    job_queue = NULL;
    /* Initialize the semaphore which counts jobs in the queue.
     * initial value should be zero. */
    sem_init (&job_queue_count, 0, 0);
}

void process_job(struct job* job)
{
    printf("now thread: %d finish the job: %d\n", (int)pthread_self(), job->value);
}

/* Process queued jobs until the queue is empty.
 * Its
 * */
void* thread_function (void* arg)
{
    printf("Thread %d start...\n", (int) pthread_self());
    while (1) {
        struct job* next_job;
        /* Wait on the job queue semaphore. If its value is positive,
         * indicating that the queue is not empty, decrement the count by
         * 1. If the queue is empty, block until a new job is enqueued. */
        sem_wait (&job_queue_count);
        /* Lock the mutex on the job queue. */
        pthread_mutex_lock (&job_queue_mutex);
        /* Because of the semaphore, we know the queue is not empty. Get
         * the next available job. */
        next_job = job_queue;
        /* Remove this job from the list. */
        job_queue = job_queue->next;
        /* Unlock the mutex on the job queue because we’re done with the
         * queue for now. */
        pthread_mutex_unlock (&job_queue_mutex);
        /* Carry out the work. */
        process_job (next_job);
        /* Clean up. */
        free (next_job);
    }
    return NULL;
}

/* Add a new job to the front of the job queue.
 * */
void enqueue_job (struct job* new_job, int value)
{
    /* Allocate a new job object. */
    new_job = (struct job*) malloc (sizeof (struct job));
    /* Set the other fields of the job struct here... */
    new_job->value = value;
    /*Lock the mutex on the job queue before accessing it.*/
    pthread_mutex_lock (&job_queue_mutex);
    /*Place the new job at the head of the queue. */
    new_job->next = job_queue;
    job_queue = new_job;

    /* Post to the semaphore to indicate that another job is available.
     * threads are blocked, waiting on the semaphore, one will become
     * unblocked so it can process the job. */
    sem_post (&job_queue_count);
    /* Unlock the job queue mutex. */
    pthread_mutex_unlock (&job_queue_mutex);
}

int main()
{
    int job_size = 1000;
    int thread_num = 5;
    int i;
    pthread_t thread_id[thread_num];
    for (i = 0; i < thread_num; i++)
        pthread_create(&thread_id[i], NULL, &thread_function, NULL);

    struct job* jobs;
    for (i = 1; i < job_size; i++)
    {
        enqueue_job(jobs, i);
    }

    for (i = 0; i < thread_num; i++)
        pthread_join(thread_id[i], NULL);
    return 0;
}
