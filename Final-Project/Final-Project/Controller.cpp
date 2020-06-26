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

Automaton Controller::buildTheAutomaton(vector<string> dataFile)//Decode Automaton and build automata class
{
	int i=0,TempSize,j, Alphabetsize;
	Automaton temp_automaton;
	temp_automaton.setBoundVSize(stoi(dataFile[i++]));//Set VARIABLE SIZE
	Alphabetsize = stoi(dataFile[i++]);//NUMBER OF CONSTANT 
	temp_automaton.setAlphabetSize(Alphabetsize);

	vector <string> alphabet(Alphabetsize);//Read the constant from the automaton and insert in alphabet vector 
	
	for (int k=0; k < Alphabetsize; k++)
	{
		alphabet[k]= dataFile[i++];//read constant and insert to alphabet vector
	}

	temp_automaton.setAlphabetList(alphabet);//set constant vector 
	temp_automaton.setStatesNumbe(stoi(dataFile[i++]));//Set the number of the states in automata
	temp_automaton.setAcceptStateNum(stoi(dataFile[i++]));//number of accept states
	TempSize = temp_automaton.getAcceptStateNum();

	vector <bool> Is_stateAccept(temp_automaton.getStatesNumbe());//set a Is_stateAccept vector for access time of O(1)

	for (int k=0; k < TempSize; k++)
	{
		Is_stateAccept[stoi(dataFile[i++])] = true;//Set the state number as index to true in Is_stateAccept
	}
	temp_automaton.setTransNum(stoi(dataFile[i++]));// The number of transition in the automaton 
	TempSize = temp_automaton.getStatesNumbe();
	
	vector <node*> pointer_array(TempSize);//size of pointer array so we have access O(1) to any state
	
	//Build the automaton connected list
	node *head=NULL;
	node *tail = NULL;
	
	for ( j = 0; j < TempSize; j++)//Run on the automaton states to connect them together
	{
		node* tmp = new node;//Create new state
		tmp->state = j;
		vector <Trans> Constant_Trans_list;
		vector <Trans> Variable_Trans_list;
		tmp->Constant_Trans_list = Constant_Trans_list;//initialize Constant vector 
		tmp->Variable_Trans_list = Variable_Trans_list;//initialize Variable vector 

		if (Is_stateAccept[j])// if its accepted state set is_accept to true
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
		pointer_array[j] = tmp;// insert the new state to states array pointer_array
		
	}

	temp_automaton.setPointerarray(pointer_array); // set states array we just created 

	int numberOfTr = temp_automaton.getTransNum();
	string transition_single;
	Trans* trans = new Trans;//create new transition variable 
	node* state;// create a state pointer 
	int transition_Type,next_State, state_Index;

	for ( int k=0; k < numberOfTr; k++)//Run on all transition for the automata  
	{
		state_Index = (stoi(dataFile[i++]));//current state of the transition 
		state = pointer_array[state_Index];//get the state that belong to this transition in order to insert it to his list of transition 
		
		transition_Type= (stoi(dataFile[i++]));//Get the type of the signal if 0 variable if 1 constant  
		transition_single = dataFile[i++];// the signal of the transition 
		
		next_State = (stoi(dataFile[i++]));// The next state after this transition 
		trans->next_state = pointer_array[next_State];//get the next state pointer 
		//type=1 if character is constant
		if (transition_Type==1)
		{
			trans->transition_signal = transition_single;
			state->Constant_Trans_list.push_back(*trans);//copy trans to Constant_Trans_list
		}
		else
		{
			int varialbe = stoi(transition_single);//convert the signal to int
			trans->transition_signal = transition_single;//set the signal
			state->Variable_Trans_list.push_back(*trans); // copy trans to Variable_Trans_list
			if (varialbe >temp_automaton.getBoundVSize())//If the signal is Y
			{
				state->has_free_varialbe = true;//set true flag that this state has Y free variable
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

//This method will analyze the input file and choose witch method needed to be run membership or equivalence
// the method get the file location and the split_symbol
string Controller::analyze_file(string Temp_argv_File_Location, char split_symbol)
{
	leanrer_Automaton_file.setFile(Temp_argv_File_Location);//set the input file location
	vector<string> fileLines=leanrer_Automaton_file.ReadFile(split_symbol);//read and split the input file into vector fileLines
	if (fileLines.empty())
		return "Error Input File is Empty!";
	else if (fileLines[0] == "Error")
		return "Error Input Opening File!";

	string res = "";
	bool membership_result{};
	bool isMembership = 0;
		if (fileLines.back().find(split_symbol) == string::npos && (fileLines.empty()==false) )//if the first line has "," then it's automata and need to run equivalence method
			isMembership = 1;
		
	if (isMembership) {
		MemberShip membership(fileLines,default_Automaton);//Create membership variable while set the default automata and the words vector
		MemberShip_results.setFile("m_results.txt");//result file set
		
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
			return "Error opining File! Results Not Saved!!";
		else 
			return res+"Results Saved To File "+ MemberShip_results.fileLocation;
		
	}
	else {
		equivalence_result.setFile("e_results.txt");//The result file 
		set_leanrer_Automaton(buildTheAutomaton(fileLines));//build the learner Automaton and set it as leanrer_Automaton
		Equevilance equevilance(default_Automaton, leanrer_Automaton);// create equivalence class with assigning both automata 
		result = equevilance.execute_Equevilance();// execute equivalence main function 
		if (result=="")//no counter example the Automata are equivalent
		{
			res = "Yes, the Automata are equivalent";
			
			if (equivalence_result.WriteFile(res) == 1)
				return "\nError Opening File! Results Not Saved!!";
			else
				return res + "\nResults Saved To File " + equivalence_result.fileLocation;
		}
		else// there is counter example there are NOT equivalent
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
	default_Automaton_file.setFile(default_Automaton_File_Location);//set file location 
	//FileManager file;
	vector<string> dataFileContent = default_Automaton_file.ReadFile(split_symbol);//read file and analyze it and split it by split_symbol and insert to vector dataFileContent
	if (dataFileContent.empty())
		return "Error Default Automaton File is Empty!";
	else if (dataFileContent[0] == "Error")
		return "Error Opening Default Automaton File!";

	set_default_Automaton(buildTheAutomaton(dataFileContent));// build the default automate from vector data and set it as default_Automaton
	return "";
}
