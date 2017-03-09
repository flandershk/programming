#include "aggregate.h"
#include "iterator.h"
#include <iostream>
using namespace std;

int main()
{
    IAggregate* ag = new Aggregate();
    IIterator* it = ag->create_iterator();
    
    for (it->first(); !it->is_done(); it->next())
    {
        cout << it->current_item() << " ";
    }
    cout << endl;

    delete it;
    delete ag;
    return 0;
}
