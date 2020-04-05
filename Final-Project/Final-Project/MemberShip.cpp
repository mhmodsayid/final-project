#include "MemberShip.h"

/* pseudo code

*******************************************
function run_w_on_A(string w){
	load default automaton A 
	start from the initial state of A, q0
	for each character ch in w do:
		go to qi in the states linked list 
		if there is transition with ch and qi 
			then make transition to the next state in the transition linked list 
		search for the next state in the states linked list 
	end for
	if qi is accept state 
		then return true 
	else 
		return false
}

*/

MemberShip::MemberShip(FileManager& file, Automaton default_Automaton)
{
	vector<string> CwordsVec=file.ReadFile('\n');
	set_concrete_word(CwordsVec.at(0));
	this->default_Automaton = default_Automaton;
	this->pattern_word = convert_CTP(this->get_concrete_word,default_Automaton.alphabetList,default_Automaton.boundVSize);
}

MemberShip::MemberShip(Automaton default_Automaton)
{
}

bool MemberShip::execute_MemberShip()
{

	return false;
}


string MemberShip::convert_CTP(string concrete_word, vector<char> ConstsList, int boundVSize)
{
	string pattern_word = "";
	int j = 1,Bound_index=0;
	vector<char> BoundVariables(boundVSize);

	for (char& c : concrete_word)
	{
		//check if constant 
		std::vector<char>::iterator it = std::find(ConstsList.begin(), ConstsList.end(), c);
		if (it != ConstsList.end())
			pattern_word += c;
		else {
			//check if its assigned to a bound variable 
			std::vector<char>::iterator it = std::find(BoundVariables.begin(), BoundVariables.end(), c);
			if (it != BoundVariables.end()) {
				int index = std::distance(BoundVariables.begin(), it);
				pattern_word += "x" + index;
			}
			else
			{
				//assign new bound variable if it is possible
				if (Bound_index <= boundVSize)
				{
					Bound_index++;
					pattern_word += "x" + Bound_index;
					BoundVariables.at(Bound_index) = c;
				}
				else
				{
					pattern_word += "y";
				}				
			}		
		}
	}
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
