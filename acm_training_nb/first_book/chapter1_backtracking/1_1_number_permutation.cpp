/*****************************************************************
 *description: list permutation of digit 1~n, no repeated digit
 *      input: n (1<=n<=9)
 *     output: permutation of 1~n
 *****************************************************************/

#include <iostream>
using namespace std;
int perm[10];
int repeat[10];

int permutation_recursive(int step_i, int n)
{
    if (step_i > n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            cout << perm[i] << ' ';
        }
        cout << perm[n-1] << endl;
        return 0;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (repeat[i-1] == 0)
            {
                perm[step_i-1] = i;
                repeat[i-1] = 1;
                permutation_recursive(step_i+1, n);
                repeat[i-1] = 0;
            }
        }
        return 0;
    }
}

int permutation_iteration(int n)
{
    int step_i = 1;
    int branch_i = 1;
    perm[0] = 1;
    repeat[1] = 1;
    while (step_i <= n)
    {
        if (branch_i == n)
        {
            for (int i = 0; i < n - 1; i++)
            {
                cout << perm[i] << ' ';
            }
            cout << perm[n-1] << endl;
            repeat[perm[step_i]] = 0;
            step_i--;
            branch_i++;
        }
        else
        {
            for (int i = branch_i; i <= n; i++)
            {
                if (repeat[i-1] == 0)
                {
                    perm[step_i-1] = i;
                    repeat[i-1] = 1;
                    step_i++;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int n;
    while (cin >> n)
    {
        permutation_recursive(1, n);
    }

    return 0;
}
