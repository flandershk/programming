#ifndef __MEMENOR_H__
#define __MEMENOR_H__

#include <string>
using namespace std;

class Memento;
class Orignator
{
public:
    typedef string State;
    Orignator();
    Orignator(const State& sdt);
    ~Orignator();
    Memento* create_memento();
    void set_memento(Memento* mt);
    void restore_to_memento(Memento* mt);
    State get_state();
    void set_state(const State& sdt);
    void print_state();
private:
    State m_state;
    Memento* m_memento;
};

class Memento
{
private:
    friend class Orignator;
    typedef string State;
    Memento();
    Memento(const State& sdt);
    ~Memento();
    void set_state(const State& sdt);
    State get_state();
private:
    State m_state;
};
#endif
