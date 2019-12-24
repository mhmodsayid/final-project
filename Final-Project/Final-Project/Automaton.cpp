
#include "Automaton.h"//implantation of the header

Automaton::Automaton():y(0)//default constructor
{
	
}

Automaton::Automaton(int x):y(x)//overload constructor//initial y before the constructor block
{

}

void Automaton::getx()
{
}

void Automaton::setx()
{
}

Automaton::~Automaton() {//destructor

}
Automaton Automaton::operator ++()
{
}

Automaton Automaton::operator++(int)
{
	return Automaton();
}

Automaton Automaton::operator*(Automaton In)
{
	return Automaton();
}
