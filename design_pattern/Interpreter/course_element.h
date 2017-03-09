#ifndef __COURSE_ELEMENT_H__
#define __COURSE_ELEMENT_H__

#include <string>
using namespace std;

class IVisitor;
class Context;
class IElement
{
public:
    virtual void accept(IVisitor* visitor) = 0;
};

class Element: public IElement
{
public:
    int m_weight;
    Element* m_next;
    Element* m_part; 
public:
    Element();
    void accept(IVisitor* visitor);
    void parse(Context* context);
};

class Course: public Element
{
public:
    string m_name;
public:
    Course(Context* context);
    void accept(IVisitor* visitor);
};

class Lab: public Element
{
public:
    void accept(IVisitor* visitor);
};

class Test: public Element
{
public:
    void accept(IVisitor* visitor);
};

class Midterm: public Element
{
public:
    void accept(IVisitor* visitor);
};

class Exam: public Element
{
public:
    void accept(IVisitor* visitor);
};

class Context
{
public:
    string m_input;
    double m_output;
public:
    Context(string c);
    int get_number();
};
#endif
