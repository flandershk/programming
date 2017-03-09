#include <iostream>
using namespace std;

void insertition_sort(int A[], int length)
{
    int i;
    int key; 
    for (int j=1; j<length; j++)
    {
        key = A[j];
        i = j - 1;
        while (i>=0 && A[i] > key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

int main(int argc, char* argv[])
{
    int A[100];
    int length;
    int i;
    while (cin >> length)
    {
        i = length;
        while (i--)
        {
            cin >> A[i];
        }
        insertition_sort(A, length);
        for (i = 0; i < length; i++)
        {
            cout << A[i] << ' ';
        }
        cout << endl;
    }
}
