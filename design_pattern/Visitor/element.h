#ifndef __ELEMENT_H__
#define __ELEMENT_H__

class IVisitor;
class IElement
{
public:
    virtual void accept(IVisitor* visitor) = 0;
};

class Element: public IElement
{
public:
    Element* m_next;
    Element* m_link; 
public:
    Element();
    Element(Element* next);
    void accept(IVisitor* visitor);
};

class ElementWithLink: public Element
{
public:
    ElementWithLink(Element* link, Element* next);
    void accept(IVisitor* visitor);
};

#endif
