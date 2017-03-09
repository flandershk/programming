#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

class Adaptee
{
public:
    double Precise(double a, double b)
    {
        return a/b;
    }
};

class Target
{
public:
    string Estimate(int i)
    {
        cout << "call Target::Estimate" << endl;
        char buf[100];
        sprintf(buf, "%d", (int)round(i/3));
        return string("Estimage is ") + buf;
    }
};

class Adapter: private Adaptee
{
public:
    typedef string (Adapter::*Func)(int);
    Func m_request; 
    //string (Adapter::m_request)(int);

    Adapter(Adaptee* adaptee)
    {
        m_request = &Adapter::func;
    }

    Adapter(Target* target)
    {
        m_request = reinterpret_cast<Func>(&Target::Estimate);
    }

    string Request(int i)
    {
        return (this->*m_request)(i);
    }
private:
    string func(int i)
    {
        char buf[100];
        sprintf(buf, "%d", (int)round(Precise(i, 3)));
        return string("Estimate based on precise is ") + buf;
    }
};

int main()
{
    //string (Adapter::*Request)(int);
    //typedef string (Adapter::*Func)(int);
    //Func Request; 
    //Request = &Adapter::func;
    Adapter* adapter1 = new Adapter(new Adaptee());
    cout << adapter1->Request(5) << endl;
    //Request = reinterpret_cast<Func>(&Target::Estimate);
    //cout << (adapter1->*Request)(5) << endl;

    Adapter* adapter2 = new Adapter(new Target());
    cout << adapter2->Request(5) << endl;
    return 0;
}
