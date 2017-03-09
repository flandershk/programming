#include "person.h"
#include "iterator_person.h"
#include <iostream>
using namespace std;

Person::Person(string name, string birth, Person* left, Person* right)
{
    m_name = name;
    m_birth = birth;
    m_left = left;
    m_right = right;
}

string Person::get_name()
{
    return m_name;
}

string Person::get_birth()
{
    return m_birth;
}

FamilyTree::FamilyTree()
{
    Person* tom = new Person("Tom", "1950");
    Person* perter = new Person("Peter", "1976");
    Person* robert = new Person("Robert", "1978");
    Person* sarah = new Person("Sarah", "2000");
    Person* james = new Person("James", "2002");
    Person* carrie = new Person("Carrie", "2005");
    m_root = tom;
    tom->m_left = perter;
    tom->m_right = robert;
    perter->m_left = sarah;
    perter->m_right = james;
    robert->m_left = carrie;
}

FamilyTree::~FamilyTree()
{
    cout << "FamilyTree Destroy..." << endl;
    destroy(m_root);
}

void FamilyTree::destroy(Person* root)
{
    if (root != NULL)
    {
        destroy(root->m_left);
        destroy(root->m_right);
        delete root;
    }
}
IIterator* FamilyTree::create_iterator_preorder()
{
    IIterator* it = new Iterator(m_root);
    it->initialize_preorder_iterator();
    return it;
}
IIterator* FamilyTree::create_iterator_postorder()
{
    IIterator* it = new Iterator(m_root);
    it->initialize_postorder_iterator();
    return it;
}
