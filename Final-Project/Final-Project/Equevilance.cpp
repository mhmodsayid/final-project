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

/*
Equevilance::Equevilance(Automaton default_Automaton, Automaton lerner_Automaton)
{
}
*/
Equevilance::Equevilance()
{
	cout << "here";
}

string Equevilance::execute_Equevilance()
{
	
	extend_LAutomaton(&leanrer_Automaton,default_Automaton);
	complement(default_Automaton);
	Automaton cross=crossA(default_Automaton, &leanrer_Automaton);
	string result = emptiness(cross);
	if (result == "") {//should be !=

		return result;
	}
	else
	{
		leanrer_Automaton.restore_states();
		complement(default_Automaton);
		complement(leanrer_Automaton);
		cross = crossA(leanrer_Automaton,&default_Automaton);
		//result = emptiness(cross);
		for (int i = 0; i < result.size(); i++)
		{
			result[i] += 16;
		}



		return result;
	}
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
				node* extened_node= new node;
				Trans extend_trans;
				extened_node->Constant_Trans_list = state->Constant_Trans_list;
				extened_node->Variable_Trans_list = state->Variable_Trans_list;
				extened_node->Variable_Trans_list[leanrer_Automaton->boundVSize].transition_signal++;
				state->Variable_Trans_list[leanrer_Automaton->boundVSize].next_state = extened_node;
				extened_node->Variable_Trans_list[leanrer_Automaton->boundVSize].next_state = extened_node;

				leanrer_Automaton->boundVSize++;
				leanrer_Automaton->statesNumbe++;
				if (state->is_accept)
				{
					leanrer_Automaton->acceptStateNum++;
					extened_node->is_accept = true;
				}
				leanrer_Automaton->pointer_array.push_back(extened_node);
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
	//map<char, vector<char> > adjList;
	queue<int> q;
	vector <vector<string>> path_ofg_node(crossA.getStatesNumbe());
	map<char, bool> visited;
	q.push(pointer_array[0]->state);
	path_ofg_node[0].push_back("");
	visited[pointer_array[0]->state] = true;
	while (!q.empty())
	{
		int state = q.front();
		//cout << state << ", ";
		if (pointer_array[state]->is_accept)
		{
			//cout << path_ofg_node[state][0];
			return path_ofg_node[state][0];
			//need to  a1b4 -> ax1yy
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
