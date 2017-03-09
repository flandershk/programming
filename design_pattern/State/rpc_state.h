#ifndef __RPC_STATE_H__
#define __RPC_STATE_H__
#include <string>
using namespace std;

class Context;
class IState
{
public:
    virtual string move(Context* context) = 0;
    virtual string attack(Context* context) = 0;
    virtual string stop(Context* context) = 0;
    virtual string run(Context* context) = 0;
    virtual string panic(Context* context) = 0;
    virtual string calmdown(Context* context) = 0;
};

class RestingState: public IState
{
public:
    string move(Context*);
    string attack(Context*);
    string stop(Context*);
    string run(Context*);
    string panic(Context*);
    string calmdown(Context*);
};

class AttackingState: public IState
{
public:
    string move(Context*);
    string attack(Context*);
    string stop(Context*);
    string run(Context*);
    string panic(Context*);
    string calmdown(Context*);
};

class PanickingState: public IState
{
public:
    string move(Context*);
    string attack(Context*);
    string stop(Context*);
    string run(Context*);
    string panic(Context*);
    string calmdown(Context*);
};

class MovingState: public IState
{
public:
    string move(Context*);
    string attack(Context*);
    string stop(Context*);
    string run(Context*);
    string panic(Context*);
    string calmdown(Context*);
};
#endif
