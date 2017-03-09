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

    cout << endl << endl << "Visitor 3 - Interpreter" << endl;
    Interpreter* visitor3 = new Interpreter();
    int values[3][10] = {{80, 0, 100, 100, 85, 51, 52, 50, 57, 56},
                         {87, 95, 100, 100, 77, 70, 99, 100, 75, 94},
                         {0, 55, 100, 65, 55, 75, 73, 74, 71, 72}};
    for (int i = 0; i < 3; i++)
    {
        cout << "[";
        for (int j = 0; j < 10; j++)
        {
            cout << values[i][j] << " ";
        }
        cout << "]";
        visitor3->setup(context, values[i]);
        visitor3->interpreter(course);
        cout << " = " << context->m_output/100 << endl;
    }
    return 0;
}
