#include "MemberShip.h"
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
//running time O(L*T) 
//memory comp O(L+N+K+T)


//membership constructor 
MemberShip::MemberShip(vector<string> CwordsVec, Automaton default_Automaton)
{
	//save the default automaton in this class 
	this->default_Automaton = default_Automaton;
	//set multiple concrete words in the class and convert each one to a pattern word  
	for (int i = 0; i < CwordsVec.size(); i++)
	{
		set_multy_concrete_word(CwordsVec[i]);
		string ptemp=convert_CTP(CwordsVec[i], default_Automaton.alphabetList, default_Automaton.boundVSize);
		set_multy_pattern_word(ptemp);
	}		
}


//function receives a pattern word and excute a run on the default automaton, 
//return true if it stops at accepting state else return false 
bool MemberShip::execute_MemberShip(string Pword)
{
	
	int current_signal_index = 0,flag=0;//flag determine if its 1-variable or 0-constant 
	int free_Variable_index = default_Automaton.boundVSize + 1;//free variable index is number of bound variables + 1
	string current_signal;
	vector <node*> pointer_array = default_Automaton.getPointerarray();//array of pointers helps reduce searching 
	node* current_state = pointer_array[0];//initial state
	vector<string> constantsList = this->default_Automaton.alphabetList;//constant list of the default automaton 
	
	//loop on the charcters of the pattern word 
	do
	{
		current_signal= Pword[current_signal_index];
		if (current_signal == "0")//constant
		{
			current_signal = Pword[++current_signal_index];
			flag = 0;
		}
		else if(current_signal =="x"){ //bonud variable
			current_signal = Pword[++current_signal_index];
			flag = 1;
		}
		else if (current_signal == "y")//free variable
		{
			current_signal = to_string(free_Variable_index);
			flag = 1;
		}
			
		//if it is a constant then search for tansition in the constant transition list 
		if(!flag)
		{
			for (int i = 0; i < current_state->Constant_Trans_list.size(); i++)//T transitions 
				if (current_state->Constant_Trans_list[i].transition_signal == current_signal)
				{
					current_state = current_state->Constant_Trans_list[i].next_state;
					break;
				}
		}
		else//if it is a bound variable or free variable then search for tansition in the variable transition list 
		{
			for (int i = 0; i < current_state->Variable_Trans_list.size(); i++)
				if (current_state->Variable_Trans_list[i].transition_signal == current_signal)
				{
					current_state = current_state->Variable_Trans_list[i].next_state;
					break;
				}
		}
		current_signal_index++;	
		
		flag = 0;
	} while (Pword[current_signal_index]!='\0');

	return current_state->is_accept;//return state condition 
}

//function receives a concrete word, constant list of the default automaton and number of bound variables 
//converts the concrete word to a pattern word and return it .
string MemberShip::convert_CTP(string concrete_word, vector<string> ConstsList, int boundVSize)
{
	string pattern_word;
	int j = 1,Bound_index=0;
	//a helper vector to determine the character each bound variable assigned t
	//each bound variable represnted by the index 
	vector<char> BoundVariables(boundVSize); 

	for (char& c : concrete_word)
	{
		//check if constant- if it is save it to the pattern word 
		string s(1, c);
		std::vector<string>::iterator it = std::find(ConstsList.begin(), ConstsList.end(), s);
		if (it != ConstsList.end())
			pattern_word += "0"+c;
		else {
			//check if its assigned to a bound variable using the helper vector  
			std::vector<char>::iterator it = std::find(BoundVariables.begin(), BoundVariables.end(), c);
			if (it != BoundVariables.end()) {
				int index = std::distance(BoundVariables.begin(), it);
				pattern_word += "x" + to_string(index+1);
			}
			else
			{
				//assign new bound variable if it is possible
				if (Bound_index < boundVSize)
				{
					BoundVariables[Bound_index] = c;
					Bound_index++;
					pattern_word += "x" + to_string(Bound_index);
				}//if there is no more bound variables index to assign then the rest character are free variables 
				else
				{
					pattern_word += "y";
				}				
			}		
		}	
	}
	pattern_word += '\0';
	return pattern_word;
}

string MemberShip::run_w_on_A(Automaton default_Automaton, string pattern_word)
{
	return string();
}

string MemberShip::get_concrete_word()
{
	return this->concrete_word;
}

string MemberShip::get_pattern_word()
{
	return this->pattern_word;
}


void MemberShip::set_concrete_word(string concrete_word)
{
	this->concrete_word = concrete_word;
}

void MemberShip::set_pattern_word(string pattern_word)
{
	this->pattern_word = pattern_word;
}

void MemberShip::set_multy_concrete_word(string concrete_word)
{
	Cwords.push_back(concrete_word);
}

void MemberShip::set_multy_pattern_word(string pattern_word)
{
	Pwords.push_back(pattern_word);
}
