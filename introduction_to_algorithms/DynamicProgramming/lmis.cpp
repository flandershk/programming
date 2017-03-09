#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int A[1024];
int c[1024];
int lmis(int A[], int n)
{
    for (int i = 0; i < n; i++)
        c[i] = 1;
    for (int i = 1; i < n; i++)
    {
        int max = -1;
        for (int j = 0; j <= i-1; j++)
        {
            if (A[i] > A[j] && max < c[j] + 1 )
                max = c[j] + 1;
        }
        c[i] = max;
    }
    return c[n-1];
}

int main()
{
    //int fd_cin = open("./in.dat", O_RDONLY);
    //int fd_result = open("./result.dat", O_WRONLY|O_CREAT, S_IRUSR);
    //ofstream result("result.dat");
    //int fd_cout = fileno(cout);
    //dup2(fd_cin, STDIN_FILENO);
    //cout.rdbuf(result.rdbuf());
    //cout << "hello" << endl;
    //dup2(fd_result, fd_cout);
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> A[i];
        cout << lmis(A, n) << endl;
    }
    //close(fd_cin);
    //close(fd_cout);
    return 0;
}
