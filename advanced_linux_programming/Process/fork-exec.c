#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int spawn( char* program, char** arg_list )
{
    pid_t child_pid;
    child_pid = fork();
    if( child_pid != 0 )
    {
        /*wait(NULL);*/
        printf("child process teminated!!!\n");
        return child_pid;
    }
    else
    {
        execvp(program, arg_list);
        fprintf( stderr, "an error occurred in execvp\n");
        abort();
    }
}

int main()
{
    int child_status;
    char* arg_list[] = {"lsl", "-l", "/", NULL};
    spawn(arg_list[0], arg_list);
    wait(&child_status);
    if (WIFEXITED(child_status))
    {
        printf("the child process exited normally, with exit code %d\n", WIFEXITED(child_status));
    }
    else
    {
        printf("the child process exited abnormally, with exit code %d\n", WIFEXITED(child_status));
    }
    printf("done with main program\n");
    return 0;
}
