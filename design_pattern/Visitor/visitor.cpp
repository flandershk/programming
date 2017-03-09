#include "visitor.h"
#include "element.h"
#include <iostream>
using namespace std;

int CountVisitor::get_count()
{
    return m_count;
}
void CountVisitor::count_elements(Element* element)
{
    element->accept(this);
    if (element->m_link != NULL)
        count_elements(element->m_link);
    if (element->m_next != NULL)
        count_elements(element->m_next);
}
void CountVisitor::visit(ElementWithLink* element)
{
    cout << "Not counting" << endl;
}
void CountVisitor::visit(Element* element)
{
    m_count++;
}
