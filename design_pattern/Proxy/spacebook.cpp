#include <iostream>
#include <map>
using namespace std;

class SpaceBook
{/*{{{*/
public:
    static map<string, SpaceBook*> *community;

private:
    string pages;
    string name;
    string gap;

public:
    static bool is_unique(string name)
    {
        community->find(name) == community->end() ? true : false;
    }

    SpaceBook()
    {
        //cout << "Default Construct..." << endl;
    }

    SpaceBook(string n)
    {
        name = n;
        gap = "\n\t\t\t\t";
        (*community)[n] = this;
        //cout << "Construct..." << endl;
    }

    void add(string s)
    {
        //cout << community << endl;
        pages += gap + s;
        cout << gap + "============= " + name +"'s SpaceBook ======================" << endl;
        cout << pages << endl;
        cout << gap + "=====================================================" << endl;
        //print_map();
    }

    void add(string friends, string message)
    {
        (*community)[friends]->add(message);
        //print_map();
    }

    void poke(string who, string friends)
    {
        //cout << who << endl;
        (*community)[who]->pages += gap + friends + " poked you";
        //print_map();
    }

    void print_map()
    {
        map<string, SpaceBook*>::iterator it = (*community).begin();
        for (; it!=(*community).end(); it++)
        {
            cout << gap + "************* " + it->first +"'s SpaceBook **********************" << endl;
            cout << (it->second)->pages << endl;
            cout << gap + "*****************************************************" << endl;
        }
    }
};/*}}}*/

class MySpaceBook
{/*{{{*/
private:
    SpaceBook *mySpaceBook;
    string password;
    string name;
    bool isLogin;

public:
    MySpaceBook()
    {
        isLogin = false;
        mySpaceBook = NULL;
        name = "";
        password = "";
    }
    
    void regist()
    {
        cout << "Let's register you for SpaceBook" << endl;
        do 
        {
            cout << "All SpaceBook names must be unique" << endl;
            cout << "Type in a user name: ";
            cin >> name;
        }while (!SpaceBook::is_unique(name));
        cout << "Type in a password: ";
        cin >> password;
        cout << "Thanks for registering with SpaceBook" << endl;
    }

    bool authenticate()
    {
        cout << "Welcome " + name + ". Please type in your password: ";
        string supplied;
        cin >> supplied;
        if (supplied == password)
        {
            isLogin = true;
            cout << "Logged into SpaceBook" << endl;
            if (mySpaceBook == NULL)
            {
                mySpaceBook = new SpaceBook(name);
                return true;
            }
        }
        cout << "Incorrect password" << endl;
        return false;
    }

    void add(string message)
    {
        check();
        if (isLogin)
        {
            mySpaceBook->add(message);
        }
    }

    void add(string friends, string message)
    {
        check();
        if (isLogin)
        {
            mySpaceBook->add(friends, name + " said: " + message);
        }
    }

    void poke(string who)
    {
        check();
        if (isLogin)
        {
            mySpaceBook->poke(who, name);
        }
    }

    void check()
    {
        if (!isLogin)
        {
            if (password == "")
            {
                regist();
            }
            if (mySpaceBook == NULL)
            {
                authenticate();
            }
        }
    }
};/*}}}*/

map<string, SpaceBook*>* SpaceBook::community = new map<string, SpaceBook*>();

int main()
{
    MySpaceBook me;
    me.add("Hello world");
    me.add("Today I worked 18 hours");
    MySpaceBook tom;
    tom.poke("Judith");
    tom.add("Judith", "Poor you");
    tom.add("Off to see the Lion King tonight");
    //me.add("test");
    delete SpaceBook::community;
    return 0;
}
