#ifndef __RPC_CONTEXT_H__
#define __RPC_CONTEXT_H__

class IState;
class Context
{
public:
    IState* state;
public:
    void request(char);
};
#endif
