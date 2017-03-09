#include "iterator.h"
#include "aggregate.h"

Iterator::Iterator(IAggregate* ag, int index)
{
    m_aggregate = ag;
    m_index = index;
}
void Iterator::first() 
{
    m_index = 0;
}
void Iterator::next()
{
    if (m_index < m_aggregate->get_size())
    {
        m_index++;
    }
}
bool Iterator::is_done()
{
    return m_index == m_aggregate->get_size();
}
Object Iterator::current_item()
{
    return m_aggregate->get_item(m_index);
}
