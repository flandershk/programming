#include <iostream>
#include <list>
#include <vector>
#include <fstream>
using namespace std;

template<class T> 
class IComponent
{/*{{{*/
public:
    T Name;
    virtual void add(IComponent<T>* c) = 0;    
    virtual IComponent<T>* remove(T& s) = 0;
    virtual IComponent<T>* find(T& s) = 0;
    virtual T& get_name() = 0;
    virtual void set_name(T& c) = 0;
    virtual string display(int depth) = 0;
};/*}}}*/


char sep[100] = "-------------------------------------------------------------------";
template<class T>
class Component: public IComponent<T>
{/*{{{*/
public:
    T& get_name()
    {
        return this->Name;
    }

    void set_name(T& c)
    {
        this->Name = c;
    }

    Component(T name)
    {
        this->Name = name;
    }

    void add(IComponent<T>* c)
    {
        cout << "Cannot add to an item" << endl;
    }

    IComponent<T>* remove(T& s)
    {
        cout << "Cannot remove directly" << endl;
        return  this;
    }

    string display(int depth)
    {
        return string(sep, depth) + get_name() + '\n';
    }

    IComponent<T>* find(T& s)
    {
        if (s == get_name())
        {
            return this;
        }
        else 
        {
            return NULL;
        }
    }
};/*}}}*/

template<class T>
class Composite: public IComponent<T>
{/*{{{*/
private:
    typedef typename list< IComponent<T>* >::iterator iterator;
    IComponent<T>* holder;
    list< IComponent<T>* >* lst;
public:
    T& get_name()
    {
        return this->Name;
    }

    void set_name(T& c)
    {
        this->Name = c;
    }
    
    Composite(T name)
    {
        holder = NULL;
        this->Name = name;
        lst = new list< IComponent<T>* >();
    }

    //~Composite()
    //{
        //cout << "delete lst" << endl;
        //iterator ptr;
        //for (ptr = lst->begin(); ptr != lst->end(); ptr++)
        //{
            //cout << "delete " + (*ptr)->Name << endl;
            //delete (*ptr);
        //}
        //delete lst;
    //}

    void add(IComponent<T>* c)
    {
        lst->push_back(c);
    }

    IComponent<T>* remove(T& s)
    {
        holder = this;
        IComponent<T>* p = holder->find(s);
        if (holder != NULL)
        {
            (dynamic_cast< Composite<T>* >(holder))->lst->remove(p);
            return holder;
        }
        else
        {
            return this;
        }
    }

    IComponent<T>* find(T& s)
    {
        holder = this;
        if (get_name() == s)
        {
            return this;
        }
        IComponent<T>* found = NULL;
        iterator ptr;
        for (ptr = lst->begin(); ptr!= lst->end(); ptr++)
        {
            found = (*ptr)->find(s);
            if (found != NULL)
                break;
        }
        return found;
    }

    string display(int depth)
    {
        string s(sep, depth);
        char len[100];
        sprintf(len, "%d", lst->size());
        s += "Set " + this->Name + " length:" + string(len) + "\n";
        iterator ptr;
        for (ptr = lst->begin(); ptr != lst->end(); ptr++)
        {
            if ((*ptr) != this)
                s += (*ptr)->display(depth + 2);
        }
        return s;
    }
};/*}}}*/

template<class T>
class FlyweightFactory
{
public:
    typedef typename vector<IComponent<T>*>::iterator ITERATOR;
    FlyweightFactory()
    {
        flyweights = new vector<IComponent<T>*>();
    }
    ~FlyweightFactory()
    {
        ITERATOR it;
        for (it = flyweights->begin(); it != flyweights->end(); it++)
        {
            cout << "delete " << (*it)->get_name() << endl;
            delete (*it);
        }
        delete flyweights;
    }
    IComponent<T>* get_flyweight(T& index, bool isdir)
    {
        ITERATOR it;
        for (it = flyweights->begin(); it != flyweights->end(); it++)
        {
            if (index == (*it)->get_name())
                return *it;
        }
        IComponent<T>* fly = NULL;
        if (isdir)
            fly = new Composite<T>(index);
        else
            fly = new Component<T>(index);
        flyweights->push_back(fly);
        return fly;
    }
private:
    vector<IComponent<T>*> *flyweights;
};

int main()
{
    IComponent<string>* album = new Composite<string>(string("Album"));
    IComponent<string>* point = album;
    FlyweightFactory<string>* dictonary = new FlyweightFactory<string>();
    string command, parameter;
    FILE* fin;
    if ((fin = fopen("composite.dat", "r")) == NULL)
    {
        cout << "composite.dat not exist" << endl;
        return 1;
    }
    string t;
    char buf[100];
    do
    {
        t = fgets(buf, 100, fin);
        cout << "\t\t\t\t" + t;
        int pos = t.find(" ");
        if (pos == string::npos)
        {
            command = t.substr(0, t.size()-1);
        }
        else
        {
            command = t.substr(0, pos);
            parameter = t.substr(pos+1, t.size() - pos - 2);
            //cout << parameter << endl;
        }
        if (command == "AddSet")
        {
            IComponent<string>* c = dictonary->get_flyweight(parameter, true);
            point->add(c);
            point = c;
        }
        else if (command == "AddPhoto")
        {
            IComponent<string>* c = dictonary->get_flyweight(parameter, false);
            point->add(c);
        }
        else if (command == "Remove")
        {
            point = point->remove(parameter);
        }
        else if (command == "Find")
        {
            point = album->find(parameter);
        }
        else if (command == "Display")
        {
            cout << album->display(0) << endl;
        }
        else if (command == "Quit")
        {
            break;
        }
    }while (command != "Quit");

    delete album;
    delete dictonary;
    fclose(fin);
    return 0;
}
