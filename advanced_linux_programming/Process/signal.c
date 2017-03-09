#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int wait_mask;

void waitting()
{
    while(wait_mask != 0);
}

void stop()
{
    printf("function stop called...\n");
    wait_mask = 0;
}

int main()
{
    pid_t p1, p2;
    int stdout;
    while( (p1=fork())==-1 );
    if( p1 > 0 )
    {
        while(( p2 = fork()) == -1);
        if( p2 > 0 )
        {
            wait_mask = 1;
            signal(SIGINT, stop);
            waitting();
            kill(p1, SIGUSR1);
            kill(p2, SIGUSR2);
            wait(NULL);
            wait(NULL);
            printf("parent process is killed\n");
            exit(0);
        }
        else
        {
            printf("child process 1 invoked...\n");
            wait_mask = 1;
            signal(SIGINT, SIG_IGN);
            signal(SIGUSR2, stop);
            waitting();
            lockf(stdout, 1, 0);
            printf("child process 2 is killed by parent\n");
            lockf(stdout, 0, 0);
            exit(0);
        }
    }
    else
    {
        printf("child process 2 invoked...\n");
        wait_mask = 1;
        signal(SIGINT, SIG_IGN);
        signal(SIGUSR1, stop);
        waitting();
        lockf(stdout, 1, 0);
        printf("child process 1 is killed by parent\n");
        lockf(stdout, 0, 0);
        exit(0);
    }
}
