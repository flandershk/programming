//#include "facade_library.h"
//using namespace library;
//

#include <iostream>
using namespace std;

class A
{
public:
    void print()
    {
        cout << "Hello World!" << endl;
    }
};

class B
{
public:
    static void display()
    {
        static A a;
        a.print();
    }
};

int main()
{
    B::display();
    return 0;
}
