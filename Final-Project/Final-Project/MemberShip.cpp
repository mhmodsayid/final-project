#include "MemberShip.h"

/* pseudo code
*******************************************

function memberShip(string path) {
	read file from location path into a string w
	call convert_concrete_to_pattern(w)
	call run_w_on_A(w)
	if the run stopped at accept state 
		then return Yes
	else 
		return No 
}

*******************************************
function convert_concrete_to_pattern(string w){
	define u as new empty string
	define k as the number of bounded variables of the default automaton 
	for each character ch in w do:
		if ch a constant letter 
			then concatenate to u, ch
		else 
			concatenate to u xi where i is a running index 
		if ch is assigned to one of the xi's 
			then concatenate to u, same xi 
		else 
			concatenate to u, xi+1
		if i=k 
			then check if ch is assigned to one of the xi's 
				then concatenate to u same xi
			else concatenate to u, y 
	end for
	return u
}

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


