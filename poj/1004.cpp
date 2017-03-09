#include <iostream>

using namespace std;

int main()
{
    float input;
    int i = 12;
    float sum = 0.0;
    while (i--)
    {
        cin >> input;
        sum += input;
    }
    cout << '$' << sum / 12.0 << endl;
    return 0;
}
