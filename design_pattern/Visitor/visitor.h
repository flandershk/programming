#ifndef __VISITOR_H__
#define __VISITOR_H__

class Element;
class ElementWithLink;
class IVisitor
{
public:
    virtual void visit(Element* element) = 0;
    virtual void visit(ElementWithLink* element) = 0;
};

class CountVisitor: public IVisitor
{
private:
    int m_count;
public:
    int get_count();
    void count_elements(Element* element);
    void visit(ElementWithLink* element);
    void visit(Element* element);
};
#endif
