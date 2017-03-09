#include "element.h"
#include "visitor.h"
#include <iostream>
using namespace std;

int main()
{
    Element* object_structure = 
        new Element(
            new Element(
                new ElementWithLink(
                    new Element(
                        new Element(
                            new ElementWithLink(
                                new Element(NULL),
                                new Element(NULL)))),
                    new Element(
                        new Element(
                            new Element(NULL))))));
    cout << "Count the Elements" << endl;
    CountVisitor* visitor = new CountVisitor();
    visitor->count_elements(object_structure);
    cout << "Number of Elements is: " << visitor->get_count() << endl;
    return 0;
}
