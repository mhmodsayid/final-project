
#include "Automaton.h"//implantation of the header



void Automaton::restore_states()
{
    for (int i = 0; i <statesNumbe; i++)
    {
        pointer_array[i]->is_accept = temp_accept_states[i];
        
    }
}

int Automaton::getBoundVSize() const
{
    return boundVSize;
}

void Automaton::setBoundVSize(int boundVSize)
{
    this->boundVSize = boundVSize;
}

int Automaton::getAlphabetSize() const
{
    return alphabetSize;
}

void Automaton::setAlphabetSize(int alphabetSize)
{
    this->alphabetSize = alphabetSize;
}

int Automaton::getStatesNumbe() const
{
    return statesNumbe;
}

void Automaton::setStatesNumbe(int statesNumbe)
{
    this->statesNumbe = statesNumbe;
}

int Automaton::getAcceptStateNum() const
{
    return acceptStateNum;
}

void Automaton::setAcceptStateNum(int acceptStateNum)
{
    this->acceptStateNum = acceptStateNum;
}

int Automaton::getTransNum() const
{
    return transNum;
}

void Automaton::setTransNum(int transNum)
{
    this->transNum = transNum;
}

vector<string> Automaton::getAlphabetList() const
{
    return alphabetList;
}

void Automaton::setAlphabetList(vector<string> alphabetList)
{
    this->alphabetList = alphabetList;
}


node* Automaton::getPointerarray(int index) const
{
    return pointer_array[index];
}

vector<node*> Automaton::getPointerarray() const
{
    return pointer_array;
}

void Automaton::setPointerarray(vector<node*> pointerarray)
{
    pointer_array = pointerarray;
}

