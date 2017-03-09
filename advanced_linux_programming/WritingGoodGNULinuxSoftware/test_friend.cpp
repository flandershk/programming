#include "test_friend.h"

girl::girl(string name)
{
    this->name = name;
}
void girl::display(boy& b)
{
    cout << "boy's name is: " << b.name << endl;
    cout << "girl's name is: " << name << endl;
}

boy::boy(string name)
{
    this->name = name;
}

void show(boy& b, girl& g)
{
    cout << "boy's name is: " << b.name << endl;
    cout << "girl's name is: " << g.name << endl;
}

int main()
{
    girl g("Lily");
    boy b("flanders");
    g.display(b);
    show(b, g);
    return 0;
}
