#include "context.h"
#include "state.h"

Context::Context()
{
    state = new NormalState();
    counter = limit;
}
Context::~Context()
{
    delete state;
}
int Context::request(int n)
{
    if (n == 2)
    {
        return state->move_up(this);
    }
    else
    {
        return state->move_down(this);
    }
}
