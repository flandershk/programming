#include "rpc_state.h"
#include "rpc_context.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

string RestingState::move(Context* context)
{
    delete context->state;
    context->state = new MovingState();
    return "You start moving";
}

string RestingState::attack(Context* context)
{
    delete context->state;
    context->state = new AttackingState();
    return "You start attacking the darkness";
}

string RestingState::stop(Context* context)
{
    return "You are already stopped";
}

string RestingState::run(Context* context)
{
    return "You cann't run unless you are moving";
}

string RestingState::panic(Context* context)
{
    delete context->state;
    context->state = new PanickingState();
    return "You start Panicking and begin seeing things";
}

string RestingState::calmdown(Context* context)
{
    return "You are already relaxed";
}

string AttackingState::move(Context* context)
{
    return "You need to stop attacking first";
}

string AttackingState::attack(Context* context)
{
    int r = random() % 20;
    char buf[1024];
    sprintf(buf, "%d", r);
    return string("You attack the darkness for " + string(buf) + " damage");
}

string AttackingState::stop(Context* context)
{
    delete context->state;
    context->state = new RestingState();
    return "You are caml down and come to rest";
}

string AttackingState::run(Context* context)
{
    delete context->state;
    context->state = new MovingState();
    return "You run away from the fray";
}

string AttackingState::panic(Context* context)
{
    delete context->state;
    context->state = new PanickingState();
    return "You start Panickinig and begin seeing things";
}

string AttackingState::calmdown(Context* context)
{
    delete context->state;
    context->state = new RestingState();
    return "You fall down and sleep";
}

string PanickingState::move(Context* context)
{
    return "You move around randomly in a blind panic";
}

string PanickingState::attack(Context* context)
{
    return "You start attacking the darkness, but keep on missing";
}

string PanickingState::stop(Context* context)
{
    delete context->state;
    context->state = new MovingState();
    return "You are start to relaxing, but keep on moving";
}

string PanickingState::run(Context* context)
{
    return "You run around in your panic";
}

string PanickingState::panic(Context* context)
{
    return "You are already in a panic";
}

string PanickingState::calmdown(Context* context)
{
    delete context->state;
    context->state = new RestingState();
    return "You relax and calm down";
}

string MovingState::move(Context* context)
{
    return "You move around randomly";
}

string MovingState::attack(Context* context)
{
    return "You need to stop moving first";
}

string MovingState::stop(Context* context)
{
    delete context->state;
    context->state = new RestingState();
    return "You stand still in a dark room";
}

string MovingState::run(Context* context)
{
    return "You run around in cirles";
}

string MovingState::panic(Context* context)
{
    delete context->state;
    context->state = new PanickingState();
    return "You start panicking and begin seeing things";
}

string MovingState::calmdown(Context* context)
{
    delete context->state;
    context->state = new RestingState();
    return "You stand still and relax";
}
