#include "mediator.h"
#include "colleage.h"
#include <iostream>
using namespace std;

int main()
{
    Mediator* m = new Mediator();

    IColleage* c1 = new CollageA(m, "John");
    IColleage* c2 = new CollageB(m, "David");
    IColleage* c3 = new CollageA(m, "Lucy");

    c1->send("Meeting on Tuesday, please all ack");
    c2->send("ACK");
    m->block(c2);
    c1->send("Still waitting some acks");
    c3->send("ACK");
    m->unblock(c2);
    c1->send("Thands all");

    delete c1;
    delete c2;
    delete c3;
    delete m;
    return 0;
}
