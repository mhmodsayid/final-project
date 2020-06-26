#include "Equevilance.h"
#include <iostream>
#include <functional>
#include <queue>
#include <map>

//sizes
//K constants 
//N bound variables 
//L len of the word 
//T transitions 
//S number of states 
//running time O(S*T)
//memory comp  O(K+S)

Equevilance::Equevilance(Automaton default_Automaton, Automaton learner_Automaton)
{
	set_default_Automaton(default_Automaton);
	set_leanrer_Automaton(learner_Automaton);
	//set the automaton
}

string Equevilance::execute_Equevilance()//main Equivalence method
{
	
	extend_LAutomaton(&leanrer_Automaton,&default_Automaton);//O(N*S)//call extend method with learner and default automaton pointer
	complement(&default_Automaton);//O(S)//perform complement on default automaton 
	cross=crossA(&default_Automaton, &leanrer_Automaton);//O(S)//perform cross on learner and default automata
	result = emptiness(&cross);//O(S*T)//run BFS on cross automata 
	if (result == "") {//if the first aggregation didn't get Counter example try the other way
		leanrer_Automaton.restore_states();//restore what the first attempt changes 
		complement(&default_Automaton);//return the default to the original state 2 complement cancel each other
		complement(&leanrer_Automaton);
		cross = crossA(&leanrer_Automaton, &default_Automaton);
		result = emptiness(&cross);
	}
	
	
	return result;
}

void Equevilance::extend_LAutomaton(Automaton *leanrer_Automaton, Automaton *default_Automaton)
{
	
	int LearnerVsize = leanrer_Automaton->getBoundVSize();
	vector <string> alphabetList = default_Automaton->getAlphabetList();
	int defaultVsize = default_Automaton->getBoundVSize();
	while (LearnerVsize != defaultVsize) { //the automatons are not the same size extend until they have the same variable size
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
				leanrer_Automaton->freeVariableShifter++;//shift the Y to higher value 
				state->Variable_Trans_list[leanrer_Automaton->boundVSize].next_state = extened_node;//connect the previews state to the new state
				extened_node->Variable_Trans_list[leanrer_Automaton->boundVSize].next_state = extened_node;//add the Y loop to the new state
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
void Equevilance::complement(Automaton *extended_Learner)
{
	for (const auto& state :extended_Learner->getPointerarray())//flip every state status
		state->is_accept = !state->is_accept;
}

Automaton Equevilance::crossA(Automaton *default_Automaton, Automaton *learner_Automaton)
{
	
	for (int i = 0; i < learner_Automaton->statesNumbe; i++)//perform intersect between learner and default automaton 
	{
		learner_Automaton->temp_accept_states.push_back(learner_Automaton->pointer_array[i]->is_accept);//save learner accept array in order to restore later
		if (default_Automaton->pointer_array[i]->is_accept != learner_Automaton->pointer_array[i]->is_accept){//if one of the states is not accept
			learner_Automaton->pointer_array[i]->is_accept = false;//the cross state is false
		}
	}
	return *learner_Automaton;
}

string Equevilance::emptiness(Automaton *crossA)
{//BFS
	vector <node*> pointer_array = crossA->getPointerarray();//get the state vector
	queue<int> q;//BFS Q to save the states
	vector <vector<string>> path_ofg_node(crossA->getStatesNumbe());//the path for each state from the start
	map<char, bool> visited;//BFS map not to visit the same state more than once to prevent loop
	q.push(pointer_array[0]->state);//start with the first state
	path_ofg_node[0].push_back("");//the path to the first state
	visited[pointer_array[0]->state] = true;//not to visit again
	while (!q.empty())
	{
		int state = q.front();
		if (pointer_array[state]->is_accept)//We have reach accept state return the path from the start to this state
		{
			return path_ofg_node[state][0];
		}
		q.pop();//we did get this state sons no need for it any more remove it from Q
		for (Trans neighbor : pointer_array[state]->Constant_Trans_list )//run on all constant transition 
		{
			if (!visited[neighbor.next_state->state] && neighbor.next_state != NULL)//never visited and there is sons
			{
				path_ofg_node[neighbor.next_state->state].push_back(path_ofg_node[state][0] + neighbor.transition_signal);//append the path from the start to the father state to sons path from the father 
				q.push(neighbor.next_state->state);
				visited[neighbor.next_state->state] = true;
			}
		}
		for (Trans neighbor : pointer_array[state]->Variable_Trans_list)//run on all Variable transition 
		{
			if (!visited[neighbor.next_state->state] && neighbor.next_state!=NULL)
			{
				path_ofg_node[neighbor.next_state->state].push_back(path_ofg_node[state][0] + char(stoi(neighbor.transition_signal) + 64));
				q.push(neighbor.next_state->state);
				visited[neighbor.next_state->state] = true;
			}
		}
	}
	return "";//there is no accept state found
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
