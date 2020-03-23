#pragma once
using namespace std;
#include "Automaton.h"
#include"FileManager.h"
#include "Equevilance.h"
#include "MemberShip.h"
#include <string>


#ifndef Controller_H

class Controller
{
public:
	Automaton buildTheAutomaton(string location);
	void generateResultFile(string result);
	void set_default_Automaton(Automaton automaton);
	void set_FileManager(FileManager file);
	void initialze_System();
private:
	Automaton default_Automaton;
	FileManager fileManager;
	string result;
	Equevilance equevilance;
	MemberShip memberShip;
};



#endif // !Automaton_H


