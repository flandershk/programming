#include <iostream>
using namespace std;

class ReceiverA
{
private:
    string build, oldbuild;
    string s;
public:
    ReceiverA()
    {
        s = "some string ";
    }
    void action()
    {
        oldbuild = build;
        build += s;
        cout << "Receiver is adding:" << build << endl;
    }
    void reverse()
    {
        build = oldbuild;
        cout << "Receiver is reversing to:" << build << endl;
    }
};

class ReceiverB
{
private:
    string build, oldbuild;
    string s;
public:
    void set_data(string s)
    {
        this->s = s;
    }
    void do_it()
    {
        oldbuild = build;
        build += s;
        cout << "Receiver is building:" << build << endl;
    }
};

class ICommand
{
public:
    virtual void execute() = 0;
    virtual void execute(string s) = 0;
};

template<class Receiver>
class Command: public ICommand
{
public:
    typedef void (Receiver::*Action)();
    typedef void (Receiver::*Action2)(string);
public:
    Command(Receiver* r, Action act)
    {
        m_receiver = r;
        m_action = act;
    }
    Command(Receiver* r, Action2 act)
    {
        m_receiver = r;
        m_action2 = act;
    }
    void execute()
    {
        (m_receiver->*m_action)();
    }
    void execute(string s)
    {
        (m_receiver->*m_action2)(s);
    }
private:
    Receiver* m_receiver;
    Action m_action;
    Action2 m_action2;
};

int main()
{
    ReceiverA* receivera = new ReceiverA();
    ReceiverB* receiverb = new ReceiverB();
    ICommand* redo = new Command<ReceiverA>(receivera, &ReceiverA::action);
    ICommand* undo = new Command<ReceiverA>(receivera, &ReceiverA::reverse);
    ICommand* set = new Command<ReceiverB>(receiverb, &ReceiverB::set_data);
    ICommand* doit = new Command<ReceiverB>(receiverb, &ReceiverB::do_it);

    redo->execute();
    redo->execute();
    undo->execute();
    redo->execute();
    set->execute("houses ");
    doit->execute();
    set->execute("castles ");
    doit->execute();
    doit->execute();

    delete redo;
    delete undo;
    delete receivera;
    delete receiverb;
    delete set;
    delete doit;
    return 0;
}
