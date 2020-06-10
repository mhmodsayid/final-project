#pragma once

#ifndef Equevilance_H
#define Equevilance_H

#include"Automaton.h"
#include <string>

class Equevilance
{
public:
	Automaton cross;
	string result;
	Equevilance(Automaton default_Automaton, Automaton lerner_Automaton);
	string execute_Equevilance();
	void extend_LAutomaton(Automaton *leanrer_Automaton, Automaton default_Automaton);
	string emptiness(Automaton crossA);
	
	void complement(Automaton extended_Learner);
	Automaton crossA(Automaton default_Automaton, Automaton* lerner_Automaton);

	Automaton get_default_Automaton();
	Automaton get_leanrer_Automaton();
private:
	Automaton default_Automaton;
	Automaton leanrer_Automaton;
	void set_default_Automaton(Automaton automaton);
	void set_leanrer_Automaton(Automaton automaton);

};

#endif // !Automaton_H