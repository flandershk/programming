#include <iostream>
using namespace std;

class IPrimitives
{
public:
    virtual string operation1() = 0;
    virtual string operation2() = 0;
};

class ClassA: public IPrimitives
{
public:
    string operation1()
    {
        return "ClassA:Op1 ";
    }
    string operation2()
    {
        return "ClassA:Op2 ";
    }
};

class ClassB: public IPrimitives
{
public:
    string operation1()
    {
        return "ClassB:Op1 ";
    }
    string operation2()
    {
        return "ClassB:Op2 ";
    }
};

class Algorithm
{
public:
    void TemplateMethod(IPrimitives* a)
    {
        string s = a->operation1() + a->operation2();
        cout << s << endl;
        delete a;
    }
};

int main()
{
    Algorithm* m = new Algorithm();

    m->TemplateMethod(new ClassA());
    m->TemplateMethod(new ClassB());

    delete m;
    return 0;
}
