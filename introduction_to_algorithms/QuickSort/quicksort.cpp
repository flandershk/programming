#include <iostream>
using namespace std;

int PARTITION(int A[], int p, int r)
{
    int x = A[r];
    int i = p-1;
    int temp;
    for (int j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;
    return i+1;
}

void QUICKSORT(int A[], int p, int r)
{
    if (p < r)
    {
        int q = PARTITION(A, p, r);
        PARTITION(A, p, q-1);
        PARTITION(A, q+1, r);
    }
}

int main(int argc, char* argv[])
{
    int c;
    int A[1024];
    while (cin>>c)
    {
        for (int i = 0; i < c; i++)
        {
            cin >> A[i];
        }
        QUICKSORT(A, 0, c-1);
        for (int i = 0; i < c; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
