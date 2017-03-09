#include <iostream>
#include <auto_ptr.h>
using namespace std;

class Singleton
{
protected:
    Singleton()
    {
    }

public:
    static auto_ptr<Singleton>& getInstance()
    {
        static auto_ptr<Singleton> instance(new Singleton());
        return  instance;
    }

    ~Singleton()
    {
        cout << "~Singleton" << endl;
    }
    void print()
    {
        cout << "Hello World" << endl;
    }
};

int main()
{
    auto_ptr<Singleton> s1 = Singleton::getInstance();
    auto_ptr<Singleton> s2 = Singleton::getInstance();
    s1->print();
    cout << "s1" << &s1 << endl;
    cout << "s2" << &s2 << endl;
    cout << &(Singleton::getInstance()) << endl;
    cout << &(Singleton::getInstance()) << endl;
    return 0;
}
