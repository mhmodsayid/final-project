#include "Equevilance.h"
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
