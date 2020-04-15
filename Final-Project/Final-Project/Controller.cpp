#include "Controller.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>


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
		Is_stateAccept[int(data[j + 4])-'0'] = true;//need to know if the sates start with 0 or 1

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
		vector <Trans> Constant_Trans_list;
		vector <Trans> Variable_Trans_list;
		tmp->Constant_Trans_list = Constant_Trans_list;
		tmp->Variable_Trans_list = Variable_Trans_list;

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
		
	}


	temp_automaton.setPointerarray(pointer_array);

	
	int numberOfTr = temp_automaton.getTransNum();

	for ( i=0; i < numberOfTr; i++)
	{
		int state_Index = (int(data[j + 4 + 3 * i]) - '0');
		node* state = pointer_array[state_Index];
		int next_State = (int(data[j + 6 + 3 * i]) - '0');
		Trans* trans = new Trans;
		trans->next_state = pointer_array[next_State];
		string transition_single;
		transition_single += data[j + 5 + 3 * i];
		if (std::all_of(transition_single.begin(), transition_single.end(), ::isdigit))
		{
			trans->transition_signal = stoi(transition_single);
			(state->Variable_Trans_list).insert(state->Variable_Trans_list.begin(),*trans);
		}
		else {
			trans->transition_signal = transition_single[0];
			state->Constant_Trans_list.push_back(*trans);//*

		}

	}
	

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
