#include <iostream>
using namespace std;

class ISubject
{
public:
    virtual string Request() = 0;
};

class Subject
{
public:
    string Request()
    {
        return "Subject Request Choose left door\n";
    }
};

class Proxy: public ISubject
{
public:
    string Request()
    {
        if (subject == NULL)
        {
            cout << "Subject inactive" << endl;
            subject = new Subject();
        }
        cout << "Sueject active" << endl;
        return "Proxy Call to " + subject->Request();
    }
private:
    Subject *subject;
};

class ProtectionProxy: public ISubject
{
public:
    ProtectionProxy()
    {
        password = "password";
    }
    string Authenticate(string supplied)
    {
        if (supplied != password)
        {
            return "Protection Proxy: No access";
        }
        else 
        {
            subject = new Subject();
            return "Protection Proxy: Authenticated";
        }
    }

    string Request()
    {
        if (subject == NULL)
        {
            return "Protection Proxy:Authenticate first";
        }
        else
        {
            return "Protection Proxy:Call to " + subject->Request(); 
        }
    }
private:
    Subject* subject;
    string password;
};


int main()
{
    cout << "Proxy Pattern" << endl;

    ISubject* subject0 = new Proxy();
    cout << subject0->Request();
    cout << subject0->Request();

    ProtectionProxy* subject = new ProtectionProxy();
    cout << subject->Request() << endl;
    cout << subject->Authenticate("secret") << endl;
    cout << subject->Authenticate("password") << endl;
    cout << subject->Request();
    
    delete subject;
    delete subject0;

    return 0;
}
