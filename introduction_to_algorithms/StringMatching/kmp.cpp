#include <iostream>
#include <string.h>
using namespace std;

int pi[1024];

void compute_prefix_function(char P[])
{
    int m = strlen(P);
    pi[1] = 0;
    int k = 0;
    for (int q = 1; q < m; q++)
    {
        while (k > 0 && P[k] != P[q])
            k = pi[k];
        if (P[k] == P[q])
            k++;
        pi[q+1] = k;
    }
    //cout << "pi={";
    //for (int i = 1; i <=m; i++)
        //cout << pi[i] << " ";
    //cout << "}" << endl;
}

void kmp_matcher(char T[], char P[])
{
    int n = strlen(T);
    int m = strlen(P);
    compute_prefix_function(P);
    int q = 0;
    for (int i = 0; i < n; i++)
    {
        while (q > 0 && P[q] != T[i])
            q = pi[q];
        if (P[q] == T[i])
            q++;
        if (q == m)
        {
            cout << i - m + 1 << " ";
            q = pi[q];
        }
    }
    cout << endl;
}

int main()
{
    char text[1024];
    char pattern[1024];
    while (cin >> text >> pattern)
    {
        kmp_matcher(text, pattern);
    }
    return 0;
}
