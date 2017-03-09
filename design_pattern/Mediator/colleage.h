#ifndef __COLLEAGE_H__
#define __COLLEAGE_H__

#include <string>
using namespace std;

class Mediator;
class IColleage
{
protected:
    Mediator* mediator;
    string name;
public:
    IColleage(Mediator* m, string name)
    {
        this->mediator = m;
        this->name = name;
    }
    virtual void send(string message) = 0;
    virtual void receive(string message, string from) = 0;
};

class CollageA: public IColleage
{
public:
    CollageA(Mediator* m, string name);
    void send(string message);
    void receive(string message, string from);
};

class CollageB: public IColleage
{
public:
    CollageB(Mediator* m, string name);
    void send(string message);
    void receive(string message, string from);
};
#endif
