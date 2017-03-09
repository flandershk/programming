#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

sig_atomic_t child_exit_status = 1;

void clean_up_child_process(int signal_number)
{
    printf("clean_up_child_process called\n");
    int status;
    wait( &status );
    printf("status:%d\n", status);
    child_exit_status = status;
}   

int main()
{
    struct sigaction sigchld_action;
    memset( &sigchld_action, 0, sizeof(sigchld_action));
    sigchld_action.sa_handler = &clean_up_child_process;
    sigaction(SIGCHLD, &sigchld_action, NULL);
    pid_t child_pid;
    child_pid = fork();
    if(child_pid == 0)
    {
        printf("this is child process...\n");
        printf("child_exit_status is %d\n", child_exit_status);
        exit(0);
    }
    else
    {
        int i;
        for (i = 0; i < 10000000; i++);
        printf("this is parent process...\n");
        printf("child_exit_status is %d\n", child_exit_status);
    }
    /*sleep(10);*/
    return 0;
}
