#ifndef __CONTEXT_H__
#define __CONTEXT_H__

class IState;
class Context
{
public:
    static const int limit = 10;
    IState* state;
    int counter;
public:
    Context();
    ~Context();
    int request(int);
};
#endif
