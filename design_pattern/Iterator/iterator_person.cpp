#include "iterator_person.h"
#include "person.h"
#include <iostream>
using namespace std;

Iterator::Iterator(Object r)
{
    m_root = r;
    m_array = new vector<Object>();
}
Iterator::~Iterator()
{
    cout << "Iterator destroy..." << endl;
    delete m_array;
}
void Iterator::create_preorder_iterator(Object root)
{
    if (root != NULL)
    {
        m_array->push_back(root);
        create_preorder_iterator(root->m_left);
        create_preorder_iterator(root->m_right);
    }
}
void Iterator::create_postorder_iterator(Object root)
{
    if (root != NULL)
    {
        create_postorder_iterator(root->m_left);
        create_postorder_iterator(root->m_right);
        m_array->push_back(root);
    }
}
void Iterator::initialize_preorder_iterator()
{
    m_array->clear();
    create_preorder_iterator(m_root);
}
void Iterator::initialize_postorder_iterator()
{
    m_array->clear();
    create_postorder_iterator(m_root);
}
void Iterator::first()
{
   m_index = 0; 
}
void Iterator::next()
{
    if (m_index < m_array->size())
    {
        m_index++;
    }
}
bool Iterator::is_done()
{
    return m_index == m_array->size();
}
Object Iterator::current_item()
{
    return (*m_array)[m_index];
}
