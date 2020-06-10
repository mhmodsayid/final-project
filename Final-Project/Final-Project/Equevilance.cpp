#include "Equevilance.h"
#include <iostream>
#include <functional>
#include <queue>
#include <map>

Equevilance::Equevilance(Automaton default_Automaton, Automaton lerner_Automaton)
{
	set_default_Automaton(default_Automaton);
	set_leanrer_Automaton(lerner_Automaton);
	//set the automatons 
}


string Equevilance::execute_Equevilance()
{
	
	extend_LAutomaton(&leanrer_Automaton,default_Automaton);
	complement(default_Automaton);
	cross=crossA(default_Automaton, &leanrer_Automaton);
	result = emptiness(cross);
	if (result == "") {//if the first aggregation didn't get Counter example try the other way
		leanrer_Automaton.restore_states();//restore what the first attempt changes 
		complement(default_Automaton);//return the default to the original state 2 complement cancel each other
		complement(leanrer_Automaton);
		cross = crossA(leanrer_Automaton, &default_Automaton);
		result = emptiness(cross);
	}
	
	for (int i = 0; i < result.size(); i++)//Converting counter word to concrete word
	{
		result[i] += 16;
	}
	return result;
}

void Equevilance::extend_LAutomaton(Automaton *leanrer_Automaton, Automaton default_Automaton)
{
	
	int LearnerVsize = leanrer_Automaton->getBoundVSize();
	vector <string> alphabetList = default_Automaton.getAlphabetList();
	int defaultVsize = default_Automaton.getBoundVSize();
	while (LearnerVsize != defaultVsize) {//need to extend changed the =!to == for test
		vector <node*> states =leanrer_Automaton->getPointerarray();

		for (node* state : states)//state transition 
		{
			if (state->has_free_varialbe) {//need to perform extend to this state
				node* extened_node= new node;//the new state to add
				Trans extend_trans;
				extened_node->Constant_Trans_list = state->Constant_Trans_list;//get all consent from original state
				extened_node->Variable_Trans_list = state->Variable_Trans_list;//get all variables from original state
				extened_node->has_free_varialbe = true;//the new node p3 has Y
				state->has_free_varialbe = false;//p2 no longer has Y
				//extened_node->Variable_Trans_list[leanrer_Automaton->boundVSize].transition_signal= leanrer_Automaton->boundVSize+1;
				leanrer_Automaton->freeVariableShifter++;//shift the Y to higher value 
				state->Variable_Trans_list[leanrer_Automaton->boundVSize].next_state = extened_node;
				extened_node->Variable_Trans_list[leanrer_Automaton->boundVSize].next_state = extened_node;
				extened_node->state = leanrer_Automaton->statesNumbe;//name of the new state the next max variable 
				leanrer_Automaton->boundVSize++;//number if variables added 1
				leanrer_Automaton->statesNumbe++;//new state added

				if (state->is_accept)//if the current state accept then the new extend state also accept 
				{
					leanrer_Automaton->acceptStateNum++;
					extened_node->is_accept = true;
				}
				leanrer_Automaton->pointer_array.push_back(extened_node);//add the state to the automaton
				break;
			}
		}
		LearnerVsize = leanrer_Automaton->getBoundVSize();
	}
	
}
void Equevilance::complement(Automaton extended_Learner)
{//need to convert to operator 
	
	for (const auto& state :extended_Learner.getPointerarray())
		state->is_accept = !state->is_accept;
}

Automaton Equevilance::crossA(Automaton default_Automaton, Automaton *lerner_Automaton)
{
	
	for (int i = 0; i < lerner_Automaton->statesNumbe; i++)
	{
		lerner_Automaton->temp_accept_states.push_back(lerner_Automaton->pointer_array[i]->is_accept);
		if (default_Automaton.pointer_array[i]->is_accept != lerner_Automaton->pointer_array[i]->is_accept){
			lerner_Automaton->pointer_array[i]->is_accept = false;
		}
	}
	return *lerner_Automaton;
}

string Equevilance::emptiness(Automaton crossA)
{//BFS
	vector <node*> pointer_array = crossA.getPointerarray();
	queue<int> q;
	vector <vector<string>> path_ofg_node(crossA.getStatesNumbe());
	map<char, bool> visited;
	q.push(pointer_array[0]->state);
	path_ofg_node[0].push_back("");
	visited[pointer_array[0]->state] = true;
	while (!q.empty())
	{
		int state = q.front();
		if (pointer_array[state]->is_accept)
		{
			return path_ofg_node[state][0];
		}
		q.pop();
		for (Trans neighbor : pointer_array[state]->Constant_Trans_list )
		{
			if (!visited[neighbor.next_state->state] && neighbor.next_state != NULL)
			{
				path_ofg_node[neighbor.next_state->state].push_back(path_ofg_node[state][0] + neighbor.transition_signal);
				q.push(neighbor.next_state->state);
				visited[neighbor.next_state->state] = true;
			}
		}
		for (Trans neighbor : pointer_array[state]->Variable_Trans_list)
		{
			if (!visited[neighbor.next_state->state] && neighbor.next_state!=NULL)
			{
				path_ofg_node[neighbor.next_state->state].push_back(path_ofg_node[state][0] + neighbor.transition_signal);
				q.push(neighbor.next_state->state);
				visited[neighbor.next_state->state] = true;
			}
		}
	}

	return "";
}

Automaton Equevilance::get_default_Automaton()
{
	return Automaton();
}

Automaton Equevilance::get_leanrer_Automaton()
{
	return Automaton();
}



void Equevilance::set_default_Automaton(Automaton automaton)
{
	default_Automaton = automaton;
}

void Equevilance::set_leanrer_Automaton(Automaton automaton)
{
	leanrer_Automaton = automaton;
}
