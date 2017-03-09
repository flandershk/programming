#include "aggregate.h"
#include "iterator.h"

Aggregate::Aggregate()
{
    for (int i = 0; i < SIZE; i++)
    {
        m_objects[i] = i;
    }
}
IIterator* Aggregate::create_iterator()
{
    return new Iterator(this);
}
Object Aggregate::get_item(int index)
{
    if (index < this->get_size())
    {
        return m_objects[index];
    }
    else 
    {
        return -1;
    }
}
int Aggregate::get_size()
{
    return SIZE;
}
