#include <iostream>
using namespace std;

class IComponent
{
public:
    virtual string Operation() = 0;
};

class Component:public IComponent
{
public:
    string Operation()
    {
        return "I am walking ";
    }
};

class DecoratorA:public IComponent
{
public:
    DecoratorA(IComponent* c)
    {
        component = c;
    }

    string Operation()
    {
        string s = component->Operation();
        s += "and listening to Classic FM ";
        return s;
    }

private:
    IComponent* component;
};


class DecoratorB:public IComponent
{
public:
    DecoratorB(IComponent* c)
    {
        //cout << "Construting DecoratorB..." << endl;
        addedState = "past the Coffee shop ";
        component = c;
    }

    string Operation()
    {
        string s = component->Operation();
        s += "to school ";
        return s;
    }

    string AddedBehavior()
    {
        return "and I bought a cappuccino ";
    }

public:
    string addedState;

private:
    IComponent* component;
};

class Client
{
public:
    static void Display(string s, IComponent* c)
    {
        cout << s + c->Operation() << endl;
    }
};

int main()
{
    cout << "Decorator Pattern" << endl;
    IComponent *component = new Component();
    Client::Display("1. Basic component:", component);
    Client::Display("2. A-decorated:", new DecoratorA(component));
    Client::Display("3. B-decorated:", new DecoratorB(component));
    Client::Display("4. B-A-decorated:", new DecoratorB(new DecoratorA(component)));
    delete component;

    DecoratorB *b = new DecoratorB(new Component());
    Client::Display("3. B-decorated:", b);
    Client::Display("5. A-B-decorated:", new DecoratorA(b));
    cout << b->addedState + b->AddedBehavior() << endl;
    delete b;
    return 0;
}
