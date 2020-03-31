#include "Controller.h"
#include <vector>
#include <iostream>
#include <fstream>


Automaton Controller::buildTheAutomaton(FileManager &file, char split_symbol)
{
	int i,TempSize,j;
	vector<string> data = file.ReadFile(split_symbol);
	Automaton temp_automaton;
	temp_automaton.setBoundVSize(stoi(data[0]));//VARIABLE SIZE
	temp_automaton.setAlphabetSize(stoi(data[1]));//NUMBER OF CONSTANT 

	TempSize = stoi(data[1]);
	vector <char> alphabet(TempSize);
	
	for ( i = 0; i < TempSize; i++)
	{
		alphabet.insert(alphabet.end(), data[i+2][0]);//read first element
	}
	temp_automaton.setAlphabetList(alphabet);
	temp_automaton.setStatesNumbe(stoi(data[i + 2]));//States number
	temp_automaton.setAcceptStateNum(stoi(data[i + 3]));
	TempSize = stoi(data[i + 3]);
	vector <int> AcstateList(TempSize);
	for (j = i; j < TempSize+i; j++)
	{
		AcstateList.insert(AcstateList.end(), stoi(data[j + 3]));
	}
	temp_automaton.setTransNum(stoi(data[j + 3]));
	TempSize = temp_automaton.getStatesNumbe();
	vector <node*> pointer_array(TempSize);//size of pinter array

	node* Pnode=NULL;
	for ( j = 0; j < TempSize; j++)
	{
		node* node{};
		node->state = j;
		if (find(AcstateList.begin(), AcstateList.end(), j) != AcstateList.end())
			node->is_accept = true;
		if (Pnode == NULL)
		{
			Pnode = node;
			Pnode->next_state = NULL;
		}
		else {
			Pnode->next_state = node;
		}
		
		pointer_array.at(j) = node;
	}






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


	return temp_automaton;
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
