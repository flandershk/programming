#include <iostream>
#include <unistd.h>
#include <time.h>
using namespace std;

class IBag
{
protected:
    string properties;
public:
    virtual string get_properties() = 0;
    virtual void set_properties(string s) = 0;
};

template<class Brand>
class IBuilder
{
public:
    virtual IBag* create_bag() = 0;
};

class Bag;

template<class Brand>
class Builder: public IBuilder<Brand>
{
private:
    Brand* myBrand;
public:
    Builder()
    {
        myBrand = new Brand();
    }
    ~Builder()
    {
        delete myBrand;
    }
    IBag* create_bag()
    {
        return myBrand->create_bag();
    }
};


//all products/*{{{*/

class Bag: public IBag
{
public:
    Bag()
    {
        properties = "";
    }
    string get_properties()
    {
        return properties;
    }
    void set_properties(string s)
    {
        properties = s;
    }
};/*}}}*/

class Program
{
public:
    static void do_work(string workitem, int time)
    {
        cout << workitem << ":0%" << flush;
        sleep(time);
        cout << "....25%" << flush;
        sleep(time);
        cout << "....50%" << flush;
        sleep(time);
        cout << "....100%" << endl;
    }
};

//dirctors/*{{{*/
class IBrand
{
public:
    virtual IBag* create_bag() = 0;
};

class Gucci : public IBrand
{
public:
   IBag* create_bag()
   {
       Bag* b = new Bag();
       Program::do_work("Cut Leather", 1);
       Program::do_work("Sew Leather", 1);
       b->set_properties(b->get_properties() + "Leather");
       Program::do_work("Create Lining", 1);
       Program::do_work("Attach Lining", 1);
       b->set_properties(b->get_properties() + " lined");
       Program::do_work("Add Label", 1);
       b->set_properties(b->get_properties() + " with label");
       return b;
   }
};

class Poochy: public IBrand
{
public:
    IBag* create_bag()
    {
        Bag* b = new Bag();
        Program::do_work("Hire cheap labour", 1);
        Program::do_work("Cut Plastic", 1);
        Program::do_work("Sew Plastic", 1);
        b->set_properties(b->get_properties() + "Plastic");
        Program::do_work("Add label", 1);
        b->set_properties(b->get_properties() + " with label");
        return b;
    }
};/*}}}*/

template<class Brand>
class Client
{
public:
    void client_main()
    {
        IBuilder<Brand>* factory = new Builder<Brand>();

        cout << "I want to buy a bag!" << endl;
        time_t begin, end;
        //cout << ctime(&begin) << endl;
        time(&begin);
        IBag* bag = factory->create_bag();
        time(&end);
        cout << "I got my Bag which took " << (int)(end - begin);
        cout <<" days with the following properties " << bag->get_properties() << endl;

        delete factory;
        delete bag;
    }
};

int main()
{
    Client<Poochy>* poochy = new Client<Poochy>();
    poochy->client_main();
    
    Client<Gucci>* gucci = new Client<Gucci>();
    gucci->client_main();

    delete poochy;
    delete gucci;
    return 0;
}
