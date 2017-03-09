#ifndef __COURSE_VISITOR_H__
#define __COURSE_VISITOR_H__

#include <iostream>
using namespace std;
class Element;
class Lab;
class Test;
class Midterm;
class Exam;
class IVisitor
{
public:
    virtual void visit(Element* element) = 0;
    virtual void visit(Lab* element) = 0;
    virtual void visit(Test* element) = 0;
    virtual void visit(Midterm* element) = 0;
    virtual void visit(Exam* element) = 0;
};

class PrintVisitor: public IVisitor
{
public:
    void print(Element* element);
    void visit(Element* element);
    void visit(Lab* element);
    void visit(Test* element);
    void visit(Midterm* element);
    void visit(Exam* element);
};

class StructureVisitor: public IVisitor
{
public:
    int m_lab;
    int m_test;
    StructureVisitor();
    void summarize(Element* element);
    void visit(Lab* element);
    void visit(Test* element);
    void visit(Midterm* element);
    void visit(Exam* element);
    void visit(Element* element);
};
#endif
