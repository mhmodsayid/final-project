#include "Controller.h"
#include <vector>
#include <iostream>
#include <fstream>

Controller::Controller()
{
}

Automaton Controller::buildTheAutomaton(string location, char split_symbol)
{


	/*
	Automaton A
	openfile(location)
	txt=readfile()
	array[]=split(txt,',')
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


	return Automaton();
}

void Controller::generateResultFile(string result)
{

	/*
	
	
	*/
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
	vector<string> fileLines;

	string fileLine;
	ifstream myfile;
	bool isMembership = 0;

	myfile.open(Temp_argv_File_Location);
	//make sure file opened
	if (!myfile) {
		cout << "Unable to open file";
		//exit(1); // terminate with error
	}

	//read all by line
	while (getline(myfile, fileLine))
	{
		//there is no splitter it a word
		if (fileLine.find(split_symbol) == string::npos && fileLine != "")
			isMembership = 1;
		else
			//remove all the split symbols
			fileLine.erase(std::remove(fileLine.begin(), fileLine.end(), split_symbol), fileLine.end());

		// Line contains string of length > 0 then save it in vector
		if (fileLine.size() > 0)
			fileLines.insert(fileLines.end(), fileLine);
	}
	if (fileLines.size() > 1) {
		//there is more than one word
	}




	if (isMembership) {
		MemberShip membweship(default_Automaton);
		result = membweship.execute_MemberShip(fileLines);

	}
	else {//Equivalence//may we need to send the string instead of file location
		set_leanrer_Automaton(buildTheAutomaton(Temp_argv_File_Location, split_symbol));
		Equevilance equevilance(default_Automaton, leanrer_Automaton);
		result = equevilance.execute_Equevilance();

	}




	myfile.close();
	return 0;
}

void Controller::set_FileManager(FileManager file)
{
	fileManager = file;

}

void Controller::initialze_System(string default_Automaton_File_Location,char split_symbol)
{
	//int method;
	//method=file_type(Temp_argv_File_Location, split_symbol);//membership or Equivalence
	set_default_Automaton(buildTheAutomaton(default_Automaton_File_Location, split_symbol));
	//need to open result file and input file

}
