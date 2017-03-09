#include "rpc_context.h"
#include "rpc_state.h"
#include <iostream>
using namespace std;

void Context::request(char c)
{
    string result;
    switch (tolower(c))
    {
    case 'm':
        result = state->move(this);
        break;
    case 'a':
        result = state->attack(this);
        break;
    case 's':
        result = state->stop(this);
        break;
    case 'r':
        result = state->run(this);
        break;
    case 'p':
        result = state->panic(this);
        break;
    case 'c':
        result = state->calmdown(this);
        break;
    case 'e':
        result = "Thank you for playing \"The RPC Game\"";
        break;
    default:
        result = "Error, try again";
        break;
    }
    cout << result << endl;
}
