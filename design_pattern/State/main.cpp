#include <iostream>
#include <stdlib.h>
using namespace std;
#include "context.h"

int main()
{
    Context* context = new Context();
    for (int i = 5; i <= 25; i++)
    {
        srandom(random());
        int r = random() % 3;
        //cout << r << " ";
        cout << context->request(r) << " ";
    }
    cout << endl;
    delete context;
    return 0;
}
