#include <iostream>
using namespace std;

int A[1024];
int binary_search(int A[], int p, int r, int x)
{
    if (p <= r)
    {
        int q = (p+r)/2;
        if (x == A[q])
            return q;
        else if (x > A[q])
            binary_search(A, q+1, r, x);
        else
            binary_search(A, p, q-1, x);
    }
    return -1;
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        cout << binary_search(A, 0, n, m) << endl;
    }
    return 0;
}
