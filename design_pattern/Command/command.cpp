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
    virtual void redo() = 0;
    virtual void undo() = 0;
};

class Command: public ICommand
{
private:
    Receiver* receiver;
public:
    Command(Receiver* r)
    {
        receiver = r;
    }
    void execute()
    {
        receiver->action();
    }
    void redo()
    {
        receiver->action();
    }
    void undo()
    {
        receiver->reverse();
    }
};

class Invoker
{
public:
    Invoker(ICommand* cmd)
    {
        command = cmd;
    }
    void invoke()
    {
        command->execute();
        command->redo();
        command->undo();
        command->execute();
    }
private:
    ICommand* command;
};

int main()
{
    Receiver* receiver = new Receiver();
    ICommand* command = new Command(receiver);
    Invoker* invoke = new Invoker(command);

    invoke->invoke();

    delete invoke;
    delete command;
    delete receiver;
    return 0;
}
