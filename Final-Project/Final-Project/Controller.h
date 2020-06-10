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
	Automaton buildTheAutomaton(FileManager & location, char split_symbol);
	string analyze_file(string Temp_argv_File_Location, char split_symbol);
	void initialze_System(string fileLocation, char split_symbol);
	Automaton get_default_Automaton();
	Automaton get_leanrer_Automaton();
private:
	Automaton default_Automaton;
	Automaton leanrer_Automaton;
	//FileManager result_file;
	FileManager default_Automaton_file;
	FileManager leanrer_Automaton_file;
	string result;
	void set_default_Automaton(Automaton automaton);
	void set_leanrer_Automaton(Automaton automaton);
};



#endif // !Automaton_H


