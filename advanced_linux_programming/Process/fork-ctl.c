#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int stdout;
    pid_t pid_b, pid_c, pid_d;
    pid_b = fork();
    pid_c = fork();
    if( pid_b > 0 && pid_c > 0 )
    {
        wait(NULL);
        wait(NULL);
        lockf(stdout, 1, 0);
        printf("this is process a\n");
        printf("pid = %d, ppid = %d\n", getpid(), getppid());
        lockf(stdout, 0, 0);
    }
    else if( pid_b > 0 && pid_c == 0 )
    {
        wait(NULL);
        lockf(stdout, 1, 0);
        printf("this is process c\n");
        printf("pid = %d, ppid = %d\n", getpid(), getppid());
        lockf(stdout, 0, 0);
    }
    else if( pid_b == 0 && pid_c > 0 )
    {
        wait(NULL);
        lockf(stdout, 1, 0);
        printf("this is process b\n");
        printf("pid = %d, ppid = %d\n", getpid(), getppid());
        lockf(stdout, 0, 0);
    }
    else
    {
        wait(NULL);
        lockf(stdout, 1, 0);
        printf("this is process d\n");
        printf("pid = %d, ppid = %d\n", getpid(), getppid());
        lockf(stdout, 0, 0);
    }
    return 0;
}
