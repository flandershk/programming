#ifndef __MEDIATOR_H__
#define __MEDIATOR_H__
#include <string>
#include <list>
using namespace std;

class IColleage;
class Mediator
{
public:
    void sign_on(IColleage* colleage);
    void send(string message, string from);
    void block(IColleage* colleage);
    void unblock(IColleage* colleage);
private:
    list<IColleage*> m_maillist;
};

#endif
