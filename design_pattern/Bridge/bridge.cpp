#include <iostream>
using namespace std;

class Test
{
    class IBridge
    {
    private:
    public:
        virtual string OperationImp() = 0;
    };

    class ImplementationA : public IBridge
    {
    private:
    public:
        string OperationImp()
        {
            return "ImplementationA";
        }
    };

    class ImplementationB : public IBridge
    {
    private:
    public:
        string OperationImp()
        {
            return "ImplementationB";
        }
    };

    class Abstraction
    {
    private:
        IBridge* bridge;
    public:
        Abstraction(IBridge* implementation)
        {
            bridge = implementation;
        }
        string Operation()
        {
            return string("Abstraction") + string(" <<< BRIDGE >>> ") + bridge->OperationImp();
        }
    };

public:
    void test()
    {
        cout << "Bridge Pattern" << endl;
        cout << (new Abstraction(new ImplementationA()))->Operation() << endl;
        cout << (new Abstraction(new ImplementationB()))->Operation() << endl;
    }
};

int main()
{
    Test t;
    t.test();
    return 0;
}
