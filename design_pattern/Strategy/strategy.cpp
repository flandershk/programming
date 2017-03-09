#include <iostream>
#include <stdlib.h>
using namespace std;

class IStrategy
{
public:
    virtual int move(int* c) = 0;
};

class Strategy1: public IStrategy
{
public:
    int move(int* c)
    {
        return ++(*c);
    }
};

class Strategy2: public IStrategy
{
public:
    int move(int* c)
    {
        return --(*c);
    }
};

class Context
{
public:
    static const int start = 5;
    int counter;
public:
    Context()
    {
        counter = 5;
    }
    int algorithm(IStrategy* strategy)
    {
        return strategy->move(&counter);
    }
};

int main()
{
    IStrategy* strategy1 = new Strategy1();
    IStrategy* strategy2 = new Strategy2();
    IStrategy* strategy = strategy1;
    Context* context = new Context();
    int r = random() % 37;
    int s = 1;
    for (int i = Context::start; i <= Context::start + 15; i++)
    {
        r = random() % 3;
        if ( r == 2)
        {
            cout << "|| ";
            if (s % 2 == 1)
                strategy = strategy2;
            else
                strategy = strategy1;
            s++;
        }
        cout << context->algorithm(strategy) << " ";
    }
    cout << endl;
    delete strategy1;
    delete strategy2;
    delete context;
    return 0;
};
