#ifndef __STATE_H__
#define __STATE_H__

class Context;
class IState
{
public:
    virtual int move_up(Context* context) = 0;
    virtual int move_down(Context* context) = 0;
};

class NormalState: public IState
{
public:
    int move_up(Context* context);
    int move_down(Context* context);
};

class FastState: public IState
{
public:
    int move_up(Context* context);
    int move_down(Context* context);
};

#endif

