#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include <list>
#include <string>
using namespace std;

class IObserver;
class Subject
{
private:
    list<IObserver*>* subscribes;
    string subject_state;
public:
    Subject();
    ~Subject();
    void attach(IObserver* observer);
    void detach(IObserver* observer);
    void notify();
    void set_subject_state(string s);
    string get_subject_state();
};
#endif
