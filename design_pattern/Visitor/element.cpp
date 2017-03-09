#include "element.h"
#include "visitor.h"
#include <string>
using namespace std;

Element::Element()
{
    m_next = NULL;
    m_link = NULL;
}
Element::Element(Element* next)
{
    m_next = next; 
}
void Element::accept(IVisitor* visitor)
{
    visitor->visit(this);
}

ElementWithLink::ElementWithLink(Element* link, Element* next)
{
    m_link = link;
    m_next = next;
}
void ElementWithLink::accept(IVisitor* visitor)
{
    visitor->visit(this);
}
