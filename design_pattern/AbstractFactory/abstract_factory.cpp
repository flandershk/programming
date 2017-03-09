#include <iostream>
using namespace std;

class IBag
{
public:
    virtual string get_material() = 0;
};

class IShoes
{
public:
    virtual int get_price() = 0;
};

template<class Brand>
class IFactory
{
public:
    virtual IBag* create_bag() = 0;
    virtual IShoes* create_shoes() = 0;
};

template<class Brand>
class Bag;
template<class Brand>
class Shoes;

template<class Brand>
class Factory: public IFactory<Brand>
{
public:
    IBag* create_bag()
    {
        return new Bag<Brand>();
    }
    IShoes* create_shoes()
    {
        return new Shoes<Brand>();
    }
};


//all products/*{{{*/

template<class Brand>
class Bag: public IBag
{
private:
    Brand* myBrand;
public:
    Bag()
    {
        myBrand = new Brand();
    }
    ~Bag()
    {
        delete myBrand;
    }
    string get_material()
    {
        return myBrand->get_material();
    }
};

template<class Brand>
class Shoes: public IShoes
{
private:
    Brand* myBrand;
public:
    Shoes()
    {
        myBrand = new Brand();
    }
    ~Shoes()
    {
        delete myBrand;
    }
    int get_price()
    {
        return myBrand->get_price();
    }
};/*}}}*/

//all brands/*{{{*/
class IBrand
{
public:
    virtual int get_price() = 0;
    virtual string get_material() = 0;
};

class Gucci : public IBrand
{
public:
    int get_price()
    {
        return 1000;
    }
    string get_material()
    {
        return "Crocodile skin";
    }
};

class Poochy: public IBrand
{
public:
    int get_price()
    {
        Gucci* gucci = new Gucci();
        int price = gucci->get_price() / 3;
        delete gucci;
        return price;
    }
    string get_material()
    {
        return "Plastic";
    }
};

class Groundcover: public IBrand
{
public:
    int get_price()
    {
        return 2000;
    }
    string get_material()
    {
        return "Souch african leather";
    }
};/*}}}*/

template<class Brand>
class Client
{
public:
    void client_main()
    {
        IFactory<Brand>* factory = new Factory<Brand>();

        IBag* bag = factory->create_bag();
        IShoes* shoes = factory->create_shoes();

        cout << "I bought a Bag which is made from " << bag->get_material() << endl;
        cout << "I bought some shoes which cost " << shoes->get_price() << endl;

        delete factory;
        delete bag;
        delete shoes;
    }
};

int main()
{
    Client<Poochy>* poochy = new Client<Poochy>();
    poochy->client_main();
    
    Client<Gucci>* gucci = new Client<Gucci>();
    gucci->client_main();

    Client<Groundcover>* groundcover = new Client<Groundcover>();
    groundcover->client_main();

    delete poochy;
    delete gucci;
    delete groundcover;
    return 0;
}
