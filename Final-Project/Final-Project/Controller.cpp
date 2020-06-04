#include "Controller.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>


Automaton Controller::buildTheAutomaton(FileManager &file, char split_symbol)
{
	int i=0,TempSize,j, Alphabetsize;
	vector<string> dataFile = file.ReadFile(split_symbol);
	//string data = dataFile[0];
	Automaton temp_automaton;
	temp_automaton.setBoundVSize(stoi(dataFile[i++]));//VARIABLE SIZE
	temp_automaton.setAlphabetSize(stoi(dataFile[i++]));//NUMBER OF CONSTANT 

	Alphabetsize = temp_automaton.getAlphabetSize();
	vector <string> alphabet(Alphabetsize);//CONSTANTS
	
	for (int k=0; k < Alphabetsize; k++)
	{
		alphabet[k]= dataFile[i++];//read first element
		
	}
	temp_automaton.setAlphabetList(alphabet);
	temp_automaton.setStatesNumbe(stoi(dataFile[i++]));//States number
	temp_automaton.setAcceptStateNum(stoi(dataFile[i++]));
	TempSize = temp_automaton.getAcceptStateNum();

	vector <bool> Is_stateAccept(temp_automaton.getStatesNumbe());

	for (int k=0; k < TempSize; k++)
	{
		Is_stateAccept[stoi(dataFile[i++])] = true;//need to know if the sates start with 0 or 1

	}
	temp_automaton.setTransNum(stoi(dataFile[i++]));
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
	string transition_single;
	Trans* trans = new Trans;
	node* state;
	int transition_Type,next_State, state_Index;

	for ( int k=0; k < numberOfTr; k++)
	{
		state_Index = (stoi(dataFile[i++]));
		state = pointer_array[state_Index];
		
		transition_Type= (stoi(dataFile[i++]));
		transition_single = dataFile[i++];//why +=
		
		next_State = (stoi(dataFile[i++]));
		trans->next_state = pointer_array[next_State];
		//type=1 if character is constant
		if (transition_Type==1)
		{
			trans->transition_signal = transition_single;
			state->Constant_Trans_list.push_back(*trans);//*
		}
		else
		{
			int varialbe = stoi(transition_single);
			trans->transition_signal = transition_single[0];//need to change
			(state->Variable_Trans_list).insert(state->Variable_Trans_list.begin(),*trans);
			if (varialbe >temp_automaton.getBoundVSize())//if there is Y
			{
				state->has_free_varialbe = true;
			}
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


string Controller::analyze_file(string Temp_argv_File_Location, char split_symbol)
{
	leanrer_Automaton_file.setFile(Temp_argv_File_Location);
	vector<string> fileLines=leanrer_Automaton_file.ReadFile(split_symbol);
	bool membership_result;
	bool isMembership = 0;
		if (fileLines.back().find(split_symbol) == string::npos && (fileLines.empty()==false) )
			isMembership = 1;
		
	if (isMembership) {
		MemberShip membweship(fileLines,default_Automaton);
		membership_result = membweship.execute_MemberShip();
		if (membership_result == true)
			return "Yes! " + fileLines[0] + " belong to the default automaton! ";
		else 
			return "No! " + fileLines[0] + " does NOT belong to the default automaton!";
	}
	else {
		set_leanrer_Automaton(buildTheAutomaton(leanrer_Automaton_file, split_symbol));
		Equevilance equevilance(default_Automaton, leanrer_Automaton);
		result = equevilance.execute_Equevilance();
		return result;
	}
}



void Controller::initialze_System(string default_Automaton_File_Location,char split_symbol)
{
	default_Automaton_file.setFile(default_Automaton_File_Location);
	result_file.setFile(default_Automaton_File_Location);
	set_default_Automaton(buildTheAutomaton(default_Automaton_file, split_symbol));

}
