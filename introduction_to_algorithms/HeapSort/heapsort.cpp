#include <iostream>
using namespace std;

int A[1024];
int heap_size;

void max_heapify(int A[], int i)
{
    int l = (i << 1) + 1;
    int r = l + 1;
    int largest;
    if (l < heap_size && A[l] > A[i])
        largest = l;
    else 
        largest = i;
    if (r < heap_size && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        int temp;
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        max_heapify(A, largest);
    }
}

void build_heap(int A[], int n)
{
    heap_size = n;
    for (int i = n/2-1; i >= 0; --i)
    {
        max_heapify(A, i);
    }
}

void heap_sort(int A[], int n)
{
    build_heap(A, n);
    for (int i = n-1; i >= 1; --i)
    {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        heap_size--;
        max_heapify(A, 0);
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            cin >> A[i];
        heap_sort(A, n);
        for (int i = 0; i < n; i++)
            cout << A[i] << " ";
        cout << endl;
    }
    return 0;
}
