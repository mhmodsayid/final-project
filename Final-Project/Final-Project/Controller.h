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
	Controller();
	Automaton buildTheAutomaton(string location, char split_symbol);
	void generateResultFile(string result);
	Automaton get_default_Automaton();
	Automaton get_leanrer_Automaton();
	int analyze_file(string Temp_argv_File_Location, char split_symbol);
	void set_FileManager(FileManager file);
	void initialze_System(string fileLocation, char split_symbol);

private:
	Automaton default_Automaton;
	Automaton leanrer_Automaton;
	FileManager fileManager;
	string result;
	void set_default_Automaton(Automaton automaton);
	void set_leanrer_Automaton(Automaton automaton);
};



#endif // !Automaton_H


