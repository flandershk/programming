#include "course_element.h"
#include "course_visitor.h"
#include <string>
#include <stdlib.h>
using namespace std;

Element::Element()
{
    m_next = NULL;
    m_part = NULL;
}
void Element::accept(IVisitor* visitor)
{
    visitor->visit(this);
}
void Lab::accept(IVisitor* visitor)
{
    visitor->visit(this);
}
void Midterm::accept(IVisitor* visitor)
{
    visitor->visit(this);
}
void Test::accept(IVisitor* visitor)
{
    visitor->visit(this);
}
void Course::accept(IVisitor* visitor)
{
    visitor->visit(this);
}
void Exam::accept(IVisitor* visitor)
{
    visitor->visit(this);
}
void Element::parse(Context* context)
{
    if (context->m_input.length() > 0 && context->m_input[0] == ')')
    {
        context->m_input = context->m_input.substr(2);
        return;
    }
    if (context->m_input.length() > 0 && 
        (context->m_input.find('L') != string::npos || 
         context->m_input.find('M') != string::npos || 
         context->m_input.find('T') != string::npos ||
         context->m_input.find('E') != string::npos))
    {
        switch (context->m_input[0])
        {
        case 'L':
            m_next = new Lab();
            break;
        case 'T':
            m_next = new Test();
            break;
        case 'M':
            m_next = new Midterm();
            break;
        case 'E':
            m_next = new Exam();
            break;
        }
        m_next->m_weight = context->get_number();
        //cout << context->m_input << endl;
        if (context->m_input.length() > 0 && context->m_input[0] == '(')
        {
            context->m_input = context->m_input.substr(1);
            m_next->m_part = new Element();
            //cout << "----" << context->m_input << endl;
            m_next->m_part->parse(context);
            //cout << "world" << endl;
            Element* e = m_next->m_part;
            while (e != NULL)
            {
                e->m_weight = e->m_weight * m_next->m_weight / 100;
                e = e->m_next;
            }
            //cout << "----" << context->m_input << endl;
            //context->m_input = context->m_input.substr(2);
            //cout << "----" << context->m_input << endl;
        }
        //cout << context->m_input << endl;
        m_next->parse(context);
    }
}

Course::Course(Context* context)
{
    m_name = context->m_input.substr(0, 6);
    context->m_input = context->m_input.substr(7);
}

Context::Context(string c)
{
    m_input = c;
    m_output = 0;
}
int Context::get_number()
{
    int space = m_input.find(' ');
    string n = m_input.substr(1, space);
    int number = atoi(n.c_str());
    m_input = m_input.substr(space + 1);
    return number;
}
