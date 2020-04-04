#include "Controller.h"
#include <vector>
#include <iostream>
#include <fstream>


Automaton Controller::buildTheAutomaton(FileManager &file, char split_symbol)
{
	int i,TempSize,j;
	vector<string> dataFile = file.ReadFile(split_symbol);
	string data = dataFile[0];
	Automaton temp_automaton;
	temp_automaton.setBoundVSize(int(data[0])-'0');//VARIABLE SIZE
	temp_automaton.setAlphabetSize(int(data[1]) - '0');//NUMBER OF CONSTANT 

	TempSize = temp_automaton.getAlphabetSize();
	vector <char> alphabet(TempSize);//CONSTANTS
	
	for ( i = 0; i < TempSize; i++)
	{
		alphabet[i]=data[i+2];//read first element
	}
	temp_automaton.setAlphabetList(alphabet);
	temp_automaton.setStatesNumbe(int(data[i + 2])-'0');//States number
	temp_automaton.setAcceptStateNum(int(data[i + 3])-'0');
	TempSize = int(data[i + 3])-'0';
	vector <bool> Is_stateAccept(temp_automaton.getStatesNumbe());

	for (j = i; j < TempSize+i; j++)
	{
		Is_stateAccept[int(data[j + 4])-'0'-1] = true;//need to know if the sates start with 0 or 1

	}
	temp_automaton.setTransNum(int(data[j + 4])-'0');
	TempSize = temp_automaton.getStatesNumbe();
	
	vector <node*> pointer_array(TempSize);//size of pinter array
	
	node *head=NULL;
	node *tail = NULL;
	for ( j = 0; j < TempSize; j++)
	{
		node* tmp = new node;
		tmp->state = j;

		if (Is_stateAccept[j])
			tmp->is_accept = true;
		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else {
			tail->next_state = tmp;
			tail = tmp;
		}
		pointer_array[j] = tmp;
		/*
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
		
		pointer_array.at(j) = node;*/
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
