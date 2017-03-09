#include <iostream>
using namespace std;
#include "state.h"
#include "context.h"

int NormalState::move_up(Context* context)
{
    context->counter += 2;
    return context->counter;
}
int NormalState::move_down(Context* context)
{
    if (context->counter < context->limit)
    {
        delete context->state;
        context->state = new FastState();
        cout << "|| ";
    }
    context->counter -= 2;
    return context->counter;
}
int FastState::move_up(Context* context)
{
    context->counter += 5;
    return context->counter;
}
int FastState::move_down(Context* context)
{
    if (context->counter < context->limit)
    {
        delete context->state;
        context->state = new NormalState();
        cout << "|| ";
    }
    context->counter -= 5;
    return context->counter;
}
