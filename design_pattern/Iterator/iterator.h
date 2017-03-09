#ifndef __ITERATOR_H__
#define __ITERATOR_H__
typedef int Object;
class IAggregate;

class IIterator
{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool is_done() = 0;
    virtual Object current_item() = 0;
};

class Iterator: public IIterator
{
public:
    Iterator(IAggregate* ag, int index = 0);
    void first();
    void next();
    bool is_done();
    Object current_item();
private:
    IAggregate* m_aggregate;
    int m_index;
};

#endif
