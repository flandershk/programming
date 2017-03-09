#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

class IAdaptee
{
public:
    virtual double specificRequest(double a, double b) = 0;
};

class ITarget
{
public:
    virtual string Request(int i) = 0;
};

class Adapter: public IAdaptee, public ITarget
{
public:
    double specificRequest(double a, double b)
    {
        return a/b;
    }

    string Request(int i)
    {
        char buf[100];
        sprintf(buf, "%d", (int)round(specificRequest(i, 3)));
        return string("Rough estimage is ") + buf;
    }
};

int main()
{
    //Adaptee first;
    //cout << "Before the new standard\nPrecise reading:";
    //cout << first.specificRequest(5, 3) << endl;

    ITarget* second = new Adapter();
    cout << "\nMoving to the new standard" << endl;
    cout << second->Request(5) << endl;

    IAdaptee* third = new Adapter();
    cout << "\nTwo way adapter" << endl;
    cout << third->specificRequest(5.1, 3.2) << endl;
    return 0;
}
