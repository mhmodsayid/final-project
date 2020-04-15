
#include "Automaton.h"//implantation of the header

Automaton::Automaton():y(0)//default constructor
{
	
}

Automaton::Automaton(int x):y(x)//overload constructor//initial y before the constructor block
{

}


Automaton::~Automaton() {//destructor

}
Automaton Automaton::operator ++()
{
	return 0;
}

Automaton Automaton::operator++(int)
{
	return Automaton();
}

Automaton Automaton::operator~()
{
    return Automaton();
}

Automaton Automaton::operator*(Automaton In)
{
	return Automaton();
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


int Automaton::getY() const
{
    return y;
}

void Automaton::setY(int y)
{
    this->y = y;
}



vector<char> Automaton::getAlphabetList() const
{
    return vector<char>();
}

void Automaton::setAlphabetList(vector<char> alphabetList)
{
    this->alphabetList = alphabetList;
}


node* Automaton::getPointerarray(int index) const
{
    return pointer_array[index];
}

void Automaton::setPointerarray(vector<node*> pointerarray)
{
    pointer_array = pointerarray;
}

