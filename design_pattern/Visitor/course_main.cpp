#include "course_element.h"
#include "course_visitor.h"
#include <iostream>
using namespace std;

int main()
{
    string rules = "COS333 L2 L2 L2 L2 L2 M25 (L40 T60 ) L10 E55 (L28 T73 ) ";

    cout << rules << endl;
    Context* context = new Context(rules);
    Element* course = new Course(context);
    course->parse(context);
    
    PrintVisitor* visitor = new PrintVisitor();
    cout << "Visitor 1 - Course Structure" << endl;
    visitor->print(course);

    StructureVisitor* visitor2 = new StructureVisitor();
    visitor2->summarize(course);
    cout << endl << endl << "Visitor 2 - Summing the weight\nLabs " << visitor2->m_lab
        << "% and Tests " << visitor2->m_test << "%" << endl;
    return 0;
}
