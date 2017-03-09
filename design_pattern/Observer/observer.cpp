#include "observer.h"
#include "subject.h"
#include <iostream>

Observer::Observer(Subject* s, string n, string g)
{
    subject = s;
    name = n;
    gap = g;
    subject->attach(this);
}

void Observer::update(string subject_state)
{
    state = subject_state;
    cout << gap << name << ": " << state << endl;
}
