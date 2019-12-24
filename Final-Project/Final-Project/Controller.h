#pragma once
using namespace std;
#include "Automaton.h"
#include"FileManager.h"
#include <string>


#ifndef Controller_H

class Controller
{
public:
	Automaton buildTheAutomaton(string location);
	void generateResultFile(string result);
private:
	Automaton default_Automaton;
	FileManager File;
	string result;
};



#endif // !Automaton_H


