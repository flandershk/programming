#include <iostream>
#include <map>
using namespace std;

class IPrototype
{
public:
    virtual IPrototype* clone() const = 0;
    virtual IPrototype* deep_copy() const = 0;
};

class DeeperData
{
public:
    DeeperData(string s)
    {
        m_data = s;
    }
    string get_data()
    {
        return m_data;
    }
    void set_data(string s)
    {
        m_data = s;
    }
private:
    string m_data;
};

class Prototype:public IPrototype
{/*{{{*/
public:
    Prototype()
    {
        cout << "default construct...." << endl;
        m_language = NULL;
    }
    Prototype(string country, string capital, string language)
    {
        m_country = country;
        m_capital = capital;
        m_language = new DeeperData(language);
    }
    Prototype(const Prototype& cp, bool flag = true)
    {
        
        cout << "Deep copy..." << endl;
        m_country = cp.m_country;
        m_capital = cp.m_capital;
        if (flag)
        {
            m_language = new DeeperData(cp.m_language->get_data());
        }
        else
        {
            m_language = cp.m_language;
        }
    }
    ~Prototype()
    {
        cout << "deconstruct..." << m_country << endl;
        if (m_language != NULL)
        {
            delete m_language;
        }
    }
    Prototype& operator=(const Prototype& cp)
    {
        cout << "Shallow copy..." << endl;
        m_country = cp.m_country;
        m_capital = cp.m_capital;
    }
    string to_string()
    {
        return string(m_country + "\t\t" + m_capital + "\t\t->" + m_language->get_data());
    }
    Prototype* clone() const
    {
        return new Prototype(*this, false);
    }
    Prototype* deep_copy() const
    {
        return new Prototype(*this);
    }
    string get_country()
    {
        return m_country;
    }
    string get_capital()
    {
        return m_capital;
    }
    DeeperData& get_language()
    {
        return (*m_language);
    }
    void set_country(string s)
    {
        m_country = s;
    }
    void set_capital(string s)
    {
        m_capital = s;
    }
    void set_language(string s)
    {
        m_language->set_data(s);
    }

private:
    string m_country;
    string m_capital;
    DeeperData* m_language;
};/*}}}*/

class PrototypeManager
{
public:
    map<string, Prototype*> prototypes;
    PrototypeManager()
    {
        prototypes["Germany"] = new Prototype("Germany", "Berlin", "German");
        prototypes["Italy"] = new Prototype("Italy", "Rome", "Italian");
        prototypes["Australia"] = new Prototype("Australia", "Canberra", "English");
    }
    ~PrototypeManager()
    {
        cout << "~PrototypeManager..." << endl;
        map<string, Prototype*>::iterator it;
        for (it = prototypes.begin(); it != prototypes.end(); it++)
        {
            cout << "delete " << it->first << endl;
            delete it->second;
        }
    }
};

void report(string s, Prototype& a, Prototype& b)
{
    cout << endl << s << endl << "Prototype " << a.to_string() << endl << "Clone    " << b.to_string() << endl;
}

int main()
{
    PrototypeManager *manager = new PrototypeManager();
    Prototype *c2;
    Prototype *c3;

    c2 = manager->prototypes["Australia"]->clone();
    report("Shallow cloneing Australia\n=============", *manager->prototypes["Australia"], *c2);

    c2->set_capital("Sydney");
    report("Altered Clone's shallow state, prototype unaffected ", *manager->prototypes["Australia"], *c2);

    c2->set_language("Chinese");
    report("Altering clone deep state:prototype affected *****", *manager->prototypes["Australia"], *c2);

    c3 = manager->prototypes["Germany"]->deep_copy();
    report("Deep cloning Germany\n=============", *manager->prototypes["Germany"], *c3);

    c3->set_capital("Munich");
    report("Altering Clone shallow state, prototype unaffected ", *manager->prototypes["Germany"], *c3);

    c3->set_language("Turkish");
    report("Altering Clone deep state, prototype unaffected", *manager->prototypes["Germany"], *c3);

    cout << "test..." << endl;

    Prototype c4;
    c4 = (*c3);
    
    //delete c2;
    delete c3;
    delete manager;
    return 0;
}
