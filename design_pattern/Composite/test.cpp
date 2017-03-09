#include <iostream>
#include <list>
#include <assert.h>
using namespace std;
template <class T> 
class base
{
};

template <class T>
class test: public base<T>
{
public:
    list< T >* lst;
    typedef typename list<T>::iterator iterator;
    void add(T a)
    {
        lst->push_back(a);
    }
    test()
    {
        lst = new list< T >;
        iterator it;
    }
};

char* str_copy(char* strDest, const char* strSrc)
{
    assert(strDest != NULL && strSrc != NULL);
    char* strAddress = strDest;
    while ((*strDest++ = *strSrc++) != '\0');
    return strAddress;
}

int main()
{
    test<string> t;
    test<string>* t2 = new test<string>;
    t.add("aa");
    char a[] = "hello world";
    char *b = new char[100];
    str_copy(b, a);
    cout << a << endl << b << endl;

    return 0;
}
