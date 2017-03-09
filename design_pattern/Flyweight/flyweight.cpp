#include <iostream>
#include <vector>
using namespace std;

class IFlyweight
{
public:
    virtual string display() = 0;
};

class Flyweight: public IFlyweight
{
public:
    Flyweight(string s)
    {
        m_name = s;
    }
    string display()
    {
        return m_name;
    }
private:
    string m_name;    
};

class FlyweightFactory
{
public:
    FlyweightFactory()
    {
        flyweights = new vector<IFlyweight*>();
    }
    ~FlyweightFactory()
    {
        vector<IFlyweight*>::iterator it;
        for (it = flyweights->begin(); it != flyweights->end(); it++)
        {
            cout << "delete " << (*it)->display() << endl;
            delete (*it);
        }
        delete flyweights;
    }
    IFlyweight* get_flyweight(string s)
    {
        vector<IFlyweight*>::iterator it;
        for (it = flyweights->begin(); it != flyweights->end(); it++)
        {
            if (s == (*it)->display())
                return *it;
        }
        IFlyweight* fly = new Flyweight(s);
        flyweights->push_back(fly);
        return fly;
    }
private:
    vector<IFlyweight*> *flyweights; 
};

int main()
{
    string dictionary[4][6] = {{"Garden", "pot.jpg", "spring.jpg", "barbeque.jpg", "flowers.jpg", ""},
                             {"Italy", "cappucino.jpg", "pasta.jpg", "restaurant.jpg", "church.jpg", ""},
                             {"Food", "pasta.jpg", "veggies.jpg", "barbeque.jpg", "cappucino.jpg", "lemonade.jpg"},
                             {"Friends", "restaurant.jpg", "dinner.jpg", "", "", ""}};
    FlyweightFactory *album = new FlyweightFactory();
    for (int r = 0; r < 4; r++)
    {
        for (int c = 1; c < 6; c++)
        {
            if (dictionary[r][c] != "")
                album->get_flyweight(dictionary[r][c]);
        }
    }

    for (int r = 0; r < 4; r++)
    {
        for (int c = 0; c < 6; c++)
        {
            if (c == 0)
                cout << "<<" << dictionary[r][c] << ">>" << endl;
            else if (dictionary[r][c] != "")
                cout << album->get_flyweight(dictionary[r][c])->display() << "  ";
        }
        cout << endl;
    }

    delete album;
    return 0;
}
