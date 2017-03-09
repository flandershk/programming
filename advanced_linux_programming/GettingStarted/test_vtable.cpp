#include <iostream>
using namespace std;

class Base
{
public:
    virtual void f()
    {
        cout << "Base::f" << endl;
    }
    virtual void g()
    {
        cout << "Base::g" << endl;
    }
    virtual void h()
    {
        cout << "Base::h" << endl;
    }
};

int main( int argc, char** argv )
{
    typedef void (*Fun)(void);
    Base b;
    Fun pFun = NULL;
    cout << "the address of vtable: " << (int*)(&b) << endl;
    cout << "the address of the first function: " << (int*)*(int*)(&b) << endl;
    pFun = (Fun)*((int*)*(int*)((&b))+1);
    pFun();
    return 0;
}
