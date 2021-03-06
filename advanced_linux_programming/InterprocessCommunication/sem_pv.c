#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#define KEY (1492)

/* Wait on a binary semaphore.
 * decrement it by 1. */
/*Block until the semaphore value is positive, then*/
int binary_semaphore_wait (int semid)
{
    struct sembuf operations[1];
    /*Use the first (and only) semaphore.*/
    operations[0].sem_num = 0;
    /*Decrement by 1. */
    operations[0].sem_op = -1;
    /* Permit undo’ing. */
    operations[0].sem_flg = SEM_UNDO;
    return semop (semid, operations, 1);
}

/* Post to a binary semaphore: increment its value by 1.
 * This returns immediately. */
int binary_semaphore_post (int semid)
{
    struct sembuf operations[1];
    /*Use the first (and only) semaphore.*/
    operations[0].sem_num = 0;
    /*Increment by 1. */
    operations[0].sem_op = 1;
    /*Permit undo’ing.*/
    operations[0].sem_flg = SEM_UNDO;
    return semop (semid, operations, 1);
}

union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
    struct seminfo *__buf;
};

/* Initialize a binary semaphore with a value of 1.
 * */
int binary_semaphore_initialize (int semid)
{
    union semun argument;
    unsigned short values[1];
    values[0] = 0;
    argument.array = values;
    return semctl (semid, 0, SETALL, argument);
}

/* Obtain a binary semaphore’s ID, allocating if necessary.
 * */
int binary_semaphore_allocation (key_t key, int sem_flags)
{
    return semget (key, 1, sem_flags);
}

/* Deallocate a binary semaphore. All users must have finished their
 * use. Returns -1 on failure. */
int binary_semaphore_deallocate (int semid)
{
    union semun ignored_argument;
    return semctl (semid, 1, IPC_RMID, ignored_argument);
}

int main()
{
    int semid = binary_semaphore_allocation(KEY, IPC_CREAT|0666);
    fprintf(stderr, "binary_semaphore_allocation success! semid: %d\n", semid);
    
    if (binary_semaphore_initialize(semid) < 0)
    {
        fprintf( stderr, "Cannot set semaphore value. \n");
    }
    else
    {
        fprintf(stderr, "Semaphore %d initialized. \n", KEY);
    }

    binary_semaphore_wait(semid);
    fprintf(stderr, "success\n");
    binary_semaphore_deallocate(semid);
    return 0;
}
