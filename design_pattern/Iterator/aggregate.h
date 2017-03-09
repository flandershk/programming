#ifndef __AGGREGATE_H__
#define __AGGREGATE_H__

typedef int Object;
class IIterator;
class IAggregate
{
public:
    virtual IIterator* create_iterator() = 0;
    virtual Object get_item(int index) = 0;
    virtual int get_size() = 0;
};

class Aggregate: public IAggregate
{
public:
    enum {SIZE = 5};
    Aggregate();
    IIterator* create_iterator();
    Object get_item(int index);
    int get_size();
private:
    Object m_objects[SIZE];
};

#endif
