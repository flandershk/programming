#include "facade_library.h"
using namespace library;

string Facade::SubsystemA::A1()
{
    return "Subsystem A, Method A1\n";
}

string Facade::SubsystemA::A2()
{
    return "SubsystemA, Method A2\n";
}

string Facade::SubsystemB::B1()
{
    return "SubsystemB, Method B1\n";
}

string Facade::SubsystemC::C1()
{
    return "SubsystemC, Method C1\n";
}

void Facade::Operation1()
{
    static SubsystemA a;
    static SubsystemB b;
    cout << "Operation1\n" << a.A1() << a.A2() << b.B1();
}

void Facade::Operation2()
{
    static SubsystemB b;
    static SubsystemC c;
    cout << "Operation2\n" << b.B1() << c.C1();
}
