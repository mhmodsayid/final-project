#include "Controller.h"
#include <vector>
#include <iostream>
#include <fstream>


Automaton Controller::buildTheAutomaton(FileManager &file, char split_symbol)
{
	vector<string> data = file.ReadFile(split_symbol);
	
	/*
	
	A.Varbles=array[0]
	A.AphaSize=array[1]
	for i=2 to A.AphaSize
		A.alphabetSet.add[array[i]]
	A.StateSize=array[i++]
	A.AcceptStateSize=array[i++]
	for i to A.AcceptStateSize
		A.AcceptStateSet.add[array[i]]
	A.transitions=array[i++]

	for j=0 to A.transitions
		transition t;
		t.currentS=array[i]
		t.tansiotionLetter=array[i++]
		t.NextS=array[i++]
		A.transitionsSet.add[t]

	A.LinkList[A.StateSize][]
	pointer_array[A.StateSize]

	for j=0 to T=A.transitionsSet
		if(pointer_array[T.currentS])!=null
			node N
			pointer_array[T.currentS]=&N
			setlinkedlist(N.Isaccept,N.nextState,N.nextTranstions,N.State,N.alphabet)

	
	*/


	return default_Automaton;
}


void Controller::set_default_Automaton(Automaton automaton)
{
	default_Automaton = automaton;
}

void Controller::set_leanrer_Automaton(Automaton automaton)
{
	leanrer_Automaton = automaton;
}




Automaton Controller::get_default_Automaton()
{
	return default_Automaton;
}

Automaton Controller::get_leanrer_Automaton()
{
	return leanrer_Automaton;
}


int Controller::analyze_file(string Temp_argv_File_Location, char split_symbol)
{
	leanrer_Automaton_file.setFile(Temp_argv_File_Location);
	vector<string> fileLines=leanrer_Automaton_file.ReadFile(split_symbol);
	
	string fileLine;
	ifstream myfile;
	bool isMembership = 0;
		if (fileLines[0].find(split_symbol) == string::npos && fileLine != "")
			isMembership = 1;
		
	if (isMembership) {
		MemberShip membweship(default_Automaton);
		result = membweship.execute_MemberShip(fileLines);

	}
	else {
		set_leanrer_Automaton(buildTheAutomaton(leanrer_Automaton_file, split_symbol));
		Equevilance equevilance(default_Automaton, leanrer_Automaton);
		result = equevilance.execute_Equevilance();

	}
	myfile.close();
	return 0;
}



void Controller::initialze_System(string default_Automaton_File_Location,char split_symbol)
{
	default_Automaton_file.setFile(default_Automaton_File_Location);
	result_file.setFile(default_Automaton_File_Location);
	set_default_Automaton(buildTheAutomaton(default_Automaton_file, split_symbol));

}
