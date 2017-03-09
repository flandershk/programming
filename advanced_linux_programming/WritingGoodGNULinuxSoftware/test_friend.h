#include <iostream>
using namespace std;

class boy;
class girl
{
private:
    string name;
public:
    girl(string name);
    void display(boy& b);
    friend void show(boy& b, girl& g);
};

class boy
{
private:
    string name;
public:
    boy(string name);
    friend void show(boy& b, girl& g);
    friend class girl;
};
