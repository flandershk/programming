#include <iostream>
using namespace std;
#include "iterator_person.h"
#include "person.h"

int main()
{
    FamilyTree * tree = new FamilyTree();
    IIterator* preorder = tree->create_iterator_preorder();
    IIterator* postorder = tree->create_iterator_postorder();

    cout << "begin..." << endl;
    for (preorder->first(); !preorder->is_done(); preorder->next())
    {
        cout << "<<" << preorder->current_item()->get_name() << ":" 
            << preorder->current_item()->get_birth() << ">>" << "  ";
    }
    cout << endl;

    for (postorder->first(); !postorder->is_done(); postorder->next())
    {
        cout << "<<" << postorder->current_item()->get_name() << ":" 
            << postorder->current_item()->get_birth() << ">>" << "  ";
    }
    cout << endl;

    delete preorder;
    delete postorder;
    delete tree;
    return 0;
};
