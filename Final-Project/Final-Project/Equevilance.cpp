#include "Equevilance.h"
#include <iostream>
#include <functional>
#include <queue>
#include <map>

/*
function Equivalence(string path){
	read file from path 
	build Automaton LDVFA 
	load default automaton TDVFA
	call check_equality(LDVFA,TDVFA)
	if result is true 
		return Yes 
	else 
	{
		return counter example a
		return NO
	}
}

**************************************************************

function check_equality(Automaton LDVFA,Automaton TDVFA){
	check equality of two automaton by two way aggregation 
	define flag_first_way=0
	define flag_second_way=0
	first way:
	call CLDVFA=complement_automata(LDVFA)
	call TxL=Intersection_automata(CLDVFA,TDVFA)
	call check_emptiness(TxL)
	if L(TxL) is empty 
		then flag_first_way=1
	else 
		call BFS algorithm set counter example 
		return counter example 
		return false 

	second way :
	call CTDVFA=complement_automata(TDVFA)
	call TxL=Intersection_automata(LDVFA,CTDVFA)
	call check_emptiness(TxL)
		if L(TxL) is empty
		then flag_second_way=1
	else
		call BFS algorithm set counter example
		return counter example
		return false
	if flag_first_way=1 and flag_second_way=1 
		then return true
}

**************************************************************

function complement_automata(Automaton A){
	for each state that NOT accept state do:
		convert state to accept 
	end for
	for each accept state do:
		convert accept state to reject state 
	end for
}

**************************************************************

function Intersection_automata(Automaton LDVFA,Automaton TDVFA){
	define new intersection TxL automata 
	if bounded variable size in LDVFA NOT equals to bounded variable size in TDVFA 
		then call expand_variablesSet(LDVFA)
	make cross algorithm between two automata
	for each state q in TDVFA pattern automata and state p in LDVFA pattern automata do:
		add qipi state to TxL 
		if qi and pi is accept state 
			then make qipi accept state 
		make new transition in TxL according to δ(qi,σ) and δ(pi,σ) 
	end for
	return TxL		
}


**************************************************************
function check_emptiness(Automaton TxL){
	define F set of accept states of TxL
	build new set R using run BFS algorithm to collect all reachable states of TxL and saving all the way to this node,
	in case it was accept we will return the path as it a negative word so we send it to learner
	if F∩R is empty 
		then return true 
	else 
		return false 
}

**************************************************************
function expand_variablesSet(Automaton LDVFA){
	do: 
		go to lastest occurrence of the free variable y in the states linked list  
		add new state (qnew)
		copy all transitions from the last state to the new state δ(qnew,σ)=δ(qlast,σ)
		add new transiton between the new state and the last state δ(qlast,xiy)=qnew
	until LDVFA variable size equls default automata variable size
}
*/


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
	
	Automaton extended_Learner=extend_LAutomaton(leanrer_Automaton,default_Automaton);
	complement(extended_Learner);
	Automaton cross=crossA(default_Automaton, extended_Learner);
	emptiness(cross);

	return string();
}

Automaton Equevilance::extend_LAutomaton(Automaton leanrer_Automaton, Automaton default_Automaton)
{
	
	int LearnerVsize = leanrer_Automaton.getBoundVSize();
	int defaultVsize = default_Automaton.getBoundVSize();
	if (LearnerVsize != defaultVsize) {//need to extend
		Automaton extended_Learner;


		return extended_Learner;
	}
	else
	{
		return leanrer_Automaton;
	}
}
void Equevilance::complement(Automaton extended_Learner)
{//need to convert to operator 
	
	for (const auto& state :extended_Learner.getPointerarray())
		state->is_accept = !state->is_accept;
}

Automaton Equevilance::crossA(Automaton default_Automaton, Automaton lerner_Automaton)
{














	return lerner_Automaton;
}

string Equevilance::emptiness(Automaton crossA)
{//BFS
	vector <node*> pointer_array = crossA.getPointerarray();
	//map<char, vector<char> > adjList;
	queue<int> q;
	map<char, bool> visited;
	q.push(pointer_array[0]->state);

	visited[pointer_array[0]->state] = true;
	while (!q.empty())
	{
		int state = q.front();
		//cout << state << ", ";
		if (pointer_array[state]->is_accept)
		{
			cout << "No found an accept state";
		}
		q.pop();
		for (Trans neighbor : pointer_array[state]->Constant_Trans_list)
		{
			if (!visited[neighbor.next_state->state])
			{
				q.push(neighbor.next_state->state);
				visited[neighbor.next_state->state] = true;
			}
		}
		for (Trans neighbor : pointer_array[state]->Variable_Trans_list)
		{
			if (!visited[neighbor.next_state->state])
			{
				q.push(neighbor.next_state->state);
				visited[neighbor.next_state->state] = true;
			}
		}
	}












	return string();
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
