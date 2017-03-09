#include <iostream>
#include <map>
using namespace std;

#include <stdio.h>

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

class Bridge
{
public:
    virtual void add(string message) = 0;
    virtual void add(string friends, string message) = 0;
    virtual void poke(string who) = 0;
};

class Portal
{
private:
    Bridge* bridge;
public:
    Portal(Bridge* aSpaceBook)
    {
        bridge = aSpaceBook;
    }

    void add(string message)
    {
        bridge->add(message);
    }

    void add(string friends, string message)
    {
        bridge->add(friends, message);
    }

    void poke(string who)
    {
        bridge->poke(who);
    }
};

class MyOpenBook: public Bridge
{/*{{{*/
private:
    SpaceBook* myOpenBook;
    string name;
    static int user;
public:
    MyOpenBook(string n)
    {
        name = n;
        user++;
        char strUser[100];
        sprintf(strUser, "%d", user);
        myOpenBook = new SpaceBook(name + "-" + string(strUser));
    }

    void add(string message)
    {
        myOpenBook->add(message);
    }

    void add(string friends, string message)
    {
        myOpenBook->add(friends, name + " : " + message);
    }

    void poke(string who)
    {
        myOpenBook->poke(who, name);
    }
};/*}}}*/

int MyOpenBook::user = 0;

int main()
{
    Portal* me = new Portal(new MyOpenBook("Judith"));
    me->add("Hello World!");
    me->add("Today I worked 18 hours");

    Portal* tom = new Portal(new MyOpenBook("Tom"));
    tom->poke("Judith-1");
    tom->add("Judith-1", "Poor you");
    tom->add("Hey, I'm on OpenBook - it's cool!");
    return 0;
}
