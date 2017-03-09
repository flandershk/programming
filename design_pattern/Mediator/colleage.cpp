#include "colleage.h"
#include "mediator.h"
#include <iostream>

CollageA::CollageA(Mediator* m, string name): IColleage(m, name)
{
    this->mediator->sign_on(this);
}
void CollageA::send(string message)
{
    cout << "Send (From " << name << "): " << message << endl;
    mediator->send(message, name);
}
void CollageA::receive(string message, string from)
{
    cout << name << " received from " << from << ": " << message << endl;
}

CollageB::CollageB(Mediator* m, string name):IColleage(m, name)
{
    this->mediator->sign_on(this);
}
void CollageB::send(string message)
{
    cout << "Send (From " << name << "): " << message << endl;
    mediator->send(message, name);
}
void CollageB::receive(string message, string from)
{
    if (from != name)
        cout << name << " received from " << from << ": " << message << endl;
}
