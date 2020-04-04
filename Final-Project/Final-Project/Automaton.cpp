
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

string Automaton::getTransList() const
{
    return transList;
}

void Automaton::setTransList(string transList)
{
    this->transList = transList;
}

string Automaton::getAutomataList() const
{
    return automataList;
}

void Automaton::setAutomataList(string automataList)
{
    this->automataList = automataList;
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
    return alphabetList;
}

void Automaton::setAlphabetList(vector<char> alphabetList)
{
    this->alphabetList = alphabetList;
}

