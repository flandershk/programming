#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

class Adaptee
{
public:
    double specificRequest(double a, double b)
    {
        return a/b;
    }
};

class ITarget
{
public:
    virtual string Request(int i) = 0;
};

class Adapter: private Adaptee, public ITarget
{
public:
    string Request(int i)
    {
        char buf[100];
        sprintf(buf, "%d", (int)round(specificRequest(i, 3)));
        return string("Rough estimage is ") + buf;
    }
};

class test
{
};
int main()
{
    Adaptee first;
    cout << "Before the new standard\nPrecise reading:";
    cout << first.specificRequest(5, 3) << endl;

    ITarget* second = new Adapter();
    cout << "\nMoving to the new standard" << endl;
    cout << second->Request(5) << endl;
    cout << sizeof(ITarget) << endl;
    cout << sizeof(test) << endl;
    return 0;
}
