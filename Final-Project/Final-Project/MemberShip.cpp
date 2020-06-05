#include "MemberShip.h"
#include "Controller.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>


MemberShip::MemberShip(vector<string> CwordsVec, Automaton default_Automaton)
{
	set_concrete_word(CwordsVec[0]);
	this->default_Automaton = default_Automaton;
	this->pattern_word = convert_CTP(this->get_concrete_word(),default_Automaton.alphabetList,default_Automaton.boundVSize);
	//flag=execute_MemberShip();	
}

MemberShip::MemberShip(Automaton default_Automaton)
{
}

bool MemberShip::execute_MemberShip()
{
	
	int current_signal_index = 0,flag=0;//flag determine if its variable or constant 
	int free_Variable_index = default_Automaton.boundVSize + 1;
	string current_signal;
	node* current_state = this->default_Automaton.pointer_array[0];//initial state
	vector<string> constantsList = this->default_Automaton.alphabetList;
	do
	{
		current_signal= this->pattern_word[current_signal_index];
		if(current_signal =="x"){
			current_signal = this->pattern_word[++current_signal_index];
			flag = 1;
		}
		else if (current_signal == "y")
		{
			current_signal = to_string(free_Variable_index);
			flag = 1;
		}
			
		//check if the signal is a constant or a bound variable 
		//constantsList
		if(!flag)
		{
			std::vector<string>::iterator it = std::find(constantsList.begin(), constantsList.end(), current_signal);
			if (it != constantsList.end())//in case it is a constant use the constants trans list 
			{
				for(int i=0;i< current_state->Constant_Trans_list.size();i++)
					if (current_state->Constant_Trans_list[i].transition_signal == current_signal)
					{
						current_state = current_state->Constant_Trans_list[i].next_state;
						break;
					}
			}
		}
		else//if it is a bound variable or free variable
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
	} while (this->pattern_word[current_signal_index]!='\0');

	return current_state->is_accept;
}


string MemberShip::convert_CTP(string concrete_word, vector<string> ConstsList, int boundVSize)
{
	string pattern_word;
	int j = 1,Bound_index=0;
	vector<char> BoundVariables(boundVSize);

	for (char& c : concrete_word)
	{
		//check if constant 
		std::vector<string>::iterator it = std::find(ConstsList.begin(), ConstsList.end(), c+"");
		if (it != ConstsList.end())
			pattern_word += c;
		else {
			//check if its assigned to a bound variable 
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
					//BoundVariables[Bound_index-1] = c;
				}
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
