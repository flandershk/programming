#include <iostream>
using namespace std;

class IProduct
{
public:
    virtual string shipfrom() = 0;
};

class ProductA: public IProduct
{
public:
    string shipfrom()
    {
        return " from South Africa";
    }
};

class ProductB: public IProduct
{
public:
    string shipfrom()
    {
        return " from Spain";
    }
};

class DefaultProduct: public IProduct
{
public:
    string shipfrom()
    {
        return " not available";
    }
};

class Creator
{
public:
    IProduct* FactoryMethod(int month)
    {
        if (month >= 4 && month <= 11)
            return new ProductA();
        else if (month == 1|| month == 2 || month == 12)
            return new ProductB();
        else
            return new DefaultProduct();
    }
};


int main()
{
    Creator *c = new Creator();
    IProduct* product;

    for (int i = 1; i <= 12; i++)
    {
        product = c->FactoryMethod(i);
        cout << "Avocados " + product->shipfrom() << endl;
        delete product;
    }
    delete c;
    return 0;
}
