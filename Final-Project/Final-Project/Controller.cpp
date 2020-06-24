#include "Controller.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

//sizes
//K constants 
//N bound variables 
//L len of the word 
//T transitions 
//S number of states 
//running time O(2S+T+K)
//memory comp  O(T+2S+K)

//Automaton Controller::buildTheAutomaton(FileManager &file, char split_symbol,vector<string> dataFile)
Automaton Controller::buildTheAutomaton(vector<string> dataFile)
{
	int i=0,TempSize,j, Alphabetsize;
	//vector<string> dataFile = file.ReadFile(split_symbol);
	//string data = dataFile[0];
	Automaton temp_automaton;
	temp_automaton.setBoundVSize(stoi(dataFile[i++]));//VARIABLE SIZE
	temp_automaton.setAlphabetSize(stoi(dataFile[i++]));//NUMBER OF CONSTANT 

	Alphabetsize = temp_automaton.getAlphabetSize();
	vector <string> alphabet(Alphabetsize);//K
	
	for (int k=0; k < Alphabetsize; k++)
	{
		alphabet[k]= dataFile[i++];//read first element
		
	}
	temp_automaton.setAlphabetList(alphabet);
	temp_automaton.setStatesNumbe(stoi(dataFile[i++]));//States number
	temp_automaton.setAcceptStateNum(stoi(dataFile[i++]));
	TempSize = temp_automaton.getAcceptStateNum();

	vector <bool> Is_stateAccept(temp_automaton.getStatesNumbe());//S

	for (int k=0; k < TempSize; k++)//S
	{
		Is_stateAccept[stoi(dataFile[i++])] = true;//need to know if the sates start with 0 or 1

	}
	temp_automaton.setTransNum(stoi(dataFile[i++]));
	TempSize = temp_automaton.getStatesNumbe();
	
	vector <node*> pointer_array(TempSize);//size of pointer array
	
	node *head=NULL;
	node *tail = NULL;
	
	for ( j = 0; j < TempSize; j++)//S
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

	for ( int k=0; k < numberOfTr; k++)//T
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
	if (fileLines.empty())
		return "Error Input File is Empty!";
	else if (fileLines[0] == "Error")
		return "Error Input Opening File!";

	string res = "";
	bool membership_result{};
	bool isMembership = 0;
		if (fileLines.back().find(split_symbol) == string::npos && (fileLines.empty()==false) )
			isMembership = 1;
		
	if (isMembership) {
		MemberShip membership(fileLines,default_Automaton);
		MemberShip_results.setFile("m_results.txt");
		
		for (int i = 0; i < membership.Pwords.size(); i++)
		{
			string pword = membership.Pwords[i];
			membership_result = membership.execute_MemberShip(pword);
			
			if (membership_result == true)
				res+= "Yes! " + membership.Cwords[i] + " belong to the default automaton! ";
			else
				res+= "No! " + membership.Cwords[i] + " does NOT belong to the default automaton!";
			res += '\n';	
		}
		if (MemberShip_results.WriteFile(res) == 1)
			return "Error Opning File! Results Not Saved!!";
		else 
			return res+"Results Saved To File "+ MemberShip_results.fileLocation;
		
	}
	else {
		//set_leanrer_Automaton(buildTheAutomaton(leanrer_Automaton_file, split_symbol));
		equivalence_result.setFile("e_results.txt");
		set_leanrer_Automaton(buildTheAutomaton(fileLines));
		Equevilance equevilance(default_Automaton, leanrer_Automaton);
		result = equevilance.execute_Equevilance();
		if (result=="")
		{
			res = "Yes, the Automata are equivalent";
			
			if (equivalence_result.WriteFile(res) == 1)
				return "\nError Opening File! Results Not Saved!!";
			else
				return res + "\nResults Saved To File " + equivalence_result.fileLocation;
		}
		else
		{
			res= "No, the Automata are NOT equivalent.\nCounter example: "+result;
			if (equivalence_result.WriteFile(res) == 1)
				return "\nError Opening File! Results Not Saved!!";
			else
				return res + "\nResults Saved To File " + equivalence_result.fileLocation;
		}
		
	}
}


//first function set the default/teacher automaton file 
//1: file location  2:split symbol 
string Controller::initialze_System(string default_Automaton_File_Location,char split_symbol)
{
	default_Automaton_file.setFile(default_Automaton_File_Location);
	//FileManager file;
	vector<string> dataFileContent = default_Automaton_file.ReadFile(split_symbol);
	if (dataFileContent.empty())
		return "Error Default Automaton File is Empty!";
	else if (dataFileContent[0] == "Error")
		return "Error Opening Default Automaton File!";

	set_default_Automaton(buildTheAutomaton(dataFileContent));
	return "";
	//set_default_Automaton(buildTheAutomaton(default_Automaton_file, split_symbol));

}
