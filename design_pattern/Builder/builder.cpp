#include <iostream>
#include <list>
using namespace std;

class Product
{
private:
    list<string>* parts;
public:
    Product()
    {
        parts = new list<string>;
    }
    ~Product()
    {
        delete parts;
    }
    void add(string part)
    {
        parts->push_back(part);
    }
    void display()
    {
        cout << endl << "Product Parts -------" << endl;
        list<string>::iterator it;
        for (it = parts->begin(); it != parts->end(); it++)
        {
            cout << *it << "    ";
        }
        cout << endl;
    }
};

class IBuilder
{
public:
    virtual void build_parta() = 0;
    virtual void build_partb() = 0;
    virtual Product* get_result() = 0;
};

class Builder1 :public IBuilder
{
private:
    Product* product;
public:
    Builder1()
    {
        product = new Product();
    }
    ~Builder1()
    {
        delete product;
    }
    void build_parta()
    {
        product->add("PartA ");
    }
    void build_partb()
    {
        product->add("PartB ");
    }
    Product* get_result()
    {
        return product;
    }
};

class Builder2: public IBuilder
{
private:
    Product* product;
public:
    Builder2()
    {
        product = new Product();
    }
    ~Builder2()
    {
        delete product;
    }
    void build_parta()
    {
        product->add("PartX ");
    }
    void build_partb()
    {
        product->add("PartY ");
    }
    Product* get_result()
    {
        return product;
    }
};

class Director
{
public:
    void construct(IBuilder* builder)
    {
        builder->build_parta();
        builder->build_partb();
        builder->build_partb();
    }
};

int main()
{
    Director* director = new Director();
    IBuilder* b1 = new Builder1();
    IBuilder* b2 = new Builder2();

    director->construct(b1);
    Product* p1 = b1->get_result();
    p1->display();

    director->construct(b2);
    Product* p2 = b2->get_result();
    p2->display();

    delete p2;
    delete p1;
    delete b1;
    delete b2;
    delete director;
    return 0;
}
