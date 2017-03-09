#ifndef __PERSON_H__
#define __PERSON_H__
#include <string>
using namespace std;

class IIterator;
class Person
{
private:
    string m_name, m_birth;
public:
    Person* m_left;
    Person* m_right;
public:
    Person(string name, string birth, Person* left = NULL, Person* right = NULL);
    string get_name();
    string get_birth();
};

class FamilyTree
{
private:
    Person* m_root;
public:
    FamilyTree();
    ~FamilyTree();
    void destroy(Person*);
    IIterator* create_iterator_preorder();
    IIterator* create_iterator_postorder();
};
#endif
