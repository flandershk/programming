#include <iostream>
using namespace std;

template <class T>
class Singleton
{
protected:
    Singleton()
    {
    }

public:
    static T* instance;
    static T* getInstance()
    {
        if (instance == NULL)
        {
            //cout << "first instantion..." << endl;
            instance = new T();
        }
        return instance;
    }

    void print()
    {
        cout << "Hello World" << endl;
    }
private:
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
};

template <class T>
T* Singleton<T>::instance = NULL;

class Test1{};
class Test2{};

int main()
{
    Test1* t1a = Singleton<Test1>::getInstance();
    Test1* t1b = Singleton<Test1>::getInstance();
    Test2* t2 = Singleton<Test2>::getInstance();

    //Singleton<Test1>* s1 = new Singleton<Test1>();

    cout << "t1a:" << t1a << endl;
    cout << "t1b:" << t1b << endl;
    if (t1a == t1b)
    {
        cout << "Objects are the same instance" << endl;
    }
    return 0;
}
