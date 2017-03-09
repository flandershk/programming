#ifndef __ITERATOR_PERSON_H__
#define __ITERATOR_PERSON_H__

#include <vector>
#include <string>
using namespace std;

class Person;
typedef Person* Object;
class IIterator
{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool is_done() = 0;
    virtual Object current_item() = 0;
    virtual void initialize_preorder_iterator() = 0;
    virtual void initialize_postorder_iterator() = 0;
    virtual ~IIterator(){};
};

class Iterator:public IIterator
{
private:
    vector<Object>* m_array;
    Object m_root;
    int m_index;
private:
    void create_preorder_iterator(Object root);
    void create_postorder_iterator(Object root);
public:
    Iterator(Object r);
    ~Iterator();
    void initialize_preorder_iterator();
    void initialize_postorder_iterator();
    void first();
    void next();
    bool is_done();
    Object current_item();
};
#endif
