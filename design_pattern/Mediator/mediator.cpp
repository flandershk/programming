#include "mediator.h"
#include "colleage.h"

void Mediator::sign_on(IColleage* colleage)
{
    m_maillist.push_back(colleage);
}
void Mediator::send(string message, string from)
{
    list<IColleage*>::iterator it;
    for (it = m_maillist.begin(); it != m_maillist.end(); it++)
    {
        (*it)->receive(message, from);
    }
}
void Mediator::block(IColleage* colleage)
{
    m_maillist.remove(colleage);
}
void Mediator::unblock(IColleage* colleage)
{
    m_maillist.push_back(colleage);
}
