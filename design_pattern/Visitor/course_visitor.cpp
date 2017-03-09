#include "course_visitor.h"
#include "course_element.h"
#include <iostream>
using namespace std;

void PrintVisitor::print(Element* element)
{
    element->accept(this);
    if (element->m_part != NULL)
    {
        cout << " [";
        print(element->m_part);
        cout << "] ";
    }
    if (element->m_next != NULL)
        print(element->m_next);
}
void PrintVisitor::visit(Element* element)
{
    cout << " " << element->m_weight; 
}
void PrintVisitor::visit(Lab* element)
{
    cout << " " << element->m_weight;
}
void PrintVisitor::visit(Test* element)
{
    cout << " " << element->m_weight;
}
void PrintVisitor::visit(Midterm* element)
{
    cout << " " << element->m_weight;
}
void PrintVisitor::visit(Exam* element)
{
    cout << " " << element->m_weight;
}

StructureVisitor::StructureVisitor()
{
    m_lab = 0;
    m_test = 0;
}
void StructureVisitor::summarize(Element* element)
{
    element->accept(this);
    if (element->m_part != NULL)
        summarize(element->m_part->m_next);
    if (element->m_next != NULL)
        summarize(element->m_next);

}
void StructureVisitor::visit(Lab* element)
{
    m_lab += element->m_weight;
}
void StructureVisitor::visit(Test* element)
{
    m_test += element->m_weight;
}
void StructureVisitor::visit(Midterm* element)
{
    if (element->m_part == NULL)
        m_test += element->m_weight;
}
void StructureVisitor::visit(Exam* element)
{
    if (element->m_part == NULL)
        m_test += element->m_weight;
}
void StructureVisitor::visit(Element* element)
{
    cout << "visit Element ";
}
