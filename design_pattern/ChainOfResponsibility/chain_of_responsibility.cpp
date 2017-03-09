#include <iostream>
#include <string>
using namespace std;

class NoAvailableHandler
{
private:
    string m_error_message;
public:
    NoAvailableHandler(string s)
    {
        m_error_message = s;
    }
    string get_error_message()
    {
        return m_error_message;
    }
};

class IHandler
{
public:
    IHandler()
    {
        m_successor = NULL;
    }
    IHandler(IHandler* succ)
    {
        m_successor = succ;
    }
    virtual ~IHandler()
    {
        cout << "Hander Deconstructing..." << endl;
        if (m_successor != NULL)
            delete m_successor;
    }
    virtual void handle_request() = 0;
    IHandler* get_successor()
    {
        return m_successor;
    }
protected:
    IHandler* m_successor;
};

class HandlerA: public IHandler
{
public:
    HandlerA()
    {
        m_successor = NULL;
    }
    HandlerA(IHandler* succ):IHandler(succ) 
    {
    }
    void handle_request()
    {
        if (get_successor() != NULL)
        {
            cout << "HandlerA:I cannot handle this event; I give it to the successor!" << endl;
            get_successor()->handle_request();
        }
        else
        {
            throw new NoAvailableHandler("no available handler for this event");
        }
    }
};

class HandlerB: public IHandler
{
public:
    HandlerB()
    {
        m_successor = NULL;
    }
    HandlerB(IHandler* succ):IHandler(succ) 
    {
    }
    void handle_request()
    {
        if (get_successor() != NULL)
        {
            cout << "HandlerB:I cannot handle this event; I give it to the successor!" << endl;
            get_successor()->handle_request();
        }
        else
        {
            throw NoAvailableHandler("no available handler for this event");
        }
    }
};

int main()
{
    IHandler* h2 = new HandlerB();
    IHandler* h1 = new HandlerA(h2);
     
    try
    {
        h1->handle_request();
    }
    catch (NoAvailableHandler& e)
    {
        cout << e.get_error_message() << endl;
    }
}
