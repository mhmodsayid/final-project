#pragma once

#ifndef Equevilance_H
#define Equevilance_H

#include"Automaton.h"
#include <string>

class Equevilance
{
public:
	Equevilance(Automaton default_Automaton, Automaton lerner_Automaton);
	Equevilance();
	string execute_Equevilance();
	Automaton extend_LAutomaton(Automaton lerner_Automaton);
	Automaton crossA(Automaton default_Automaton, Automaton lerner_Automaton);
	string emptiness(Automaton crossA);
	Automaton get_default_Automaton();
	Automaton get_leanrer_Automaton();
private:
	Automaton default_Automaton;
	Automaton leanrer_Automaton;
	void set_default_Automaton(Automaton automaton);
	void set_leanrer_Automaton(Automaton automaton);

};

#endif // !Automaton_H