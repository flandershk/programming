#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

static sig_atomic_t sigusr1_count = 0;

void handler( int signal_number )
{
    ++sigusr1_count;
    printf("sigusr1_count++\n");
}

int main()
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &handler;
    sigaction(SIGUSR1, &sa, NULL);

    pid_t child_pid;
    child_pid = fork();
    if( child_pid == 0 )
    {
        printf("this is child process!!!\n");
    }
    else
    {
        kill(child_pid, SIGUSR1);
        wait(NULL);
    }
    kill(getpid(), SIGUSR1);
    printf("SIGUSR1 was raised %d times\n", sigusr1_count);
    return 0;
}
