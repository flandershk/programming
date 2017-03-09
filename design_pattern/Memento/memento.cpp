#include "memento.h"

#include <iostream>
using namespace std;

typedef string State;

Orignator::Orignator()
{
    m_state = "";
    m_memento = NULL;
}

Orignator::Orignator(const State& sdt)
{
    m_state = sdt;
    m_memento = NULL;
}

Orignator::~Orignator()
{
}

Memento* Orignator::create_memento()
{
    return new Memento(m_state);
}

State Orignator::get_state()
{
    return m_state;
}

void Orignator::set_state(const State& sdt)
{
    m_state = sdt;
}

void Orignator::print_state()
{
    cout << "Now State: " << m_state << "..." << endl;
}

void Orignator::set_memento(Memento* men)
{
    m_memento = men;
}

void Orignator::restore_to_memento(Memento* men)
{
    m_state = men->get_state();
}

Memento::Memento()
{
    m_state = "";
}

Memento::Memento(const State& sdt)
{
    m_state = sdt;
}

State Memento::get_state()
{
    return m_state;
}

void Memento::set_state(const State& sdt)
{
    m_state = sdt;
}
