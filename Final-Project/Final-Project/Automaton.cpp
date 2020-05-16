
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


Automaton& Automaton::operator*(Automaton& A)
{
    // TODO: insert return statement here
    *this = A;
    pointer_array.clear();
    for (node* node: A.pointer_array)
    {
        Node* tmp = new Node;
        tmp->Constant_Trans_list = node->Constant_Trans_list;
        tmp->Variable_Trans_list = node->Variable_Trans_list;
        pointer_array.push_back(tmp);
    }
  
    return *this;
    


}

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


int Automaton::getY() const
{
    return y;
}

void Automaton::setY(int y)
{
    this->y = y;
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

