#include "subject.h"
#include "observer.h"
#include <iostream>

Subject::Subject()
{
    subscribes = new list<IObserver*>();
}
Subject::~Subject()
{
    delete subscribes;
}
void Subject::attach(IObserver* observer)
{
    subscribes->push_back(observer);
}
void Subject::detach(IObserver* observer)
{
    subscribes->remove(observer);
}
void Subject::notify()
{
    list<IObserver*>::iterator it;
    for (it = subscribes->begin(); it != subscribes->end(); it++)
    {
        (*it)->update(subject_state);
    }
}
void Subject::set_subject_state(string s)
{
    subject_state = s;
}
string Subject::get_subject_state()
{
    return subject_state;
}
