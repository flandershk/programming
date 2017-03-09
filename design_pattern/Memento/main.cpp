#include "memento.h"

#include <iostream>
using namespace std;

int main()
{
    Orignator* o = new Orignator();
    o->set_state("old");
    o->print_state();
    Memento* m = o->create_memento();
    o->set_state("new");
    o->print_state();
    o->restore_to_memento(m);
    o->print_state();
    return 0;
}
