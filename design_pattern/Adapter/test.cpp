#include <iostream>
#include <math.h>
#include <stdio.h>
#include <list>
using namespace std;

template<typename T> 
class A
{
private:
    typedef int (T::*delegateFun)(int);
    T* _This;
    delegateFun _delegate;

public:
    A(T *This, delegateFun func)
    {
        _This = This;
        _delegate = func;
    }

    int execute(int c)
    {
        return (_This->*_delegate)(c);
    }
};

class B
{
public:
    int func_a(int a)
    {
        return a + 10;
    }

    int func_b(int a)
    {
        return a - 10;
    }
};

void func(list<int> a)
{
}

int main()
{
    B* objB = new B();

    A<B> delegateObj1(objB, (&B::func_a));
    A<B> delegateObj2(objB, (&B::func_b));

    cout << delegateObj1.execute(20) << endl;
    cout << delegateObj2.execute(20) << endl;

    func({1,3,3});

    return 0;
}
