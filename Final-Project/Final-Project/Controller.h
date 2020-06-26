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
	Automaton buildTheAutomaton(vector<string> Content);
	string analyze_file(string Temp_argv_File_Location, char split_symbol);
	string initialze_System(string fileLocation, char split_symbol);
	Automaton get_default_Automaton();
	Automaton get_leanrer_Automaton();
private:
	Automaton default_Automaton;
	Automaton leanrer_Automaton;
	FileManager default_Automaton_file;
	FileManager leanrer_Automaton_file;
	FileManager MemberShip_results;
	FileManager equivalence_result;
	string result;
	void set_default_Automaton(Automaton automaton);
	void set_leanrer_Automaton(Automaton automaton);
};



#endif // !Automaton_H


