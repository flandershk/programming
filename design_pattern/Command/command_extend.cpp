#include <iostream>
using namespace std;

class Receiver
{
private:
    string build, oldbuild;
    string s;
public:
    Receiver()
    {
        s = "some string ";
    }
    void action()
    {
        oldbuild = build;
        build += s;
        cout << "Receiver is adding:" + build << endl;
    }
    void reverse()
    {
        build = oldbuild;
        cout << "Receiver is reversing to:" + build << endl;
    }
};

class ICommand
{
public:
    virtual void execute() = 0;
};

template<class Receiver>
class Command: public ICommand
{
public:
    typedef void (Receiver::*Action)();
public:
    Command(Receiver* r, Action act)
    {
        m_receiver = r;
        m_action = act;
    }
    void execute()
    {
        (m_receiver->*m_action)();
    }
private:
    Receiver* m_receiver;
    Action m_action;
};

int main()
{
    Receiver* receiver = new Receiver();
    ICommand* command = new Command<Receiver>(receiver, &Receiver::action);
    ICommand* command1 = new Command<Receiver>(receiver, &Receiver::reverse);

    command->execute();
    command->execute();
    command1->execute();
    command->execute();

    delete command;
    delete command1;
    delete receiver;
    return 0;
}
