#include <iostream>
using namespace std;

int main()
{
    double sum = 0;
    while (cin >> sum)
    {
        if (sum < 0.01)
        {
            break;
        }
        double temp = 0;
        double i = 2;
        while (temp < sum)
        {
            temp = temp + 1/i;
            i++;
        }
        cout << i - 2 << " card(s)" << endl;
    }
    return 0;
}
