#ifndef __OBSERVER_H__
#define __OBSERVER_H__
#include <string>
using namespace std;

class Subject;
class IObserver
{
public:
    virtual void update(string state) = 0;
};

class Observer: public IObserver
{
private:
    string name;
    string state;
    string gap;
    Subject* subject;
public:
    Observer(Subject* s, string n, string g);
    void update(string subject_state);
};
#endif
