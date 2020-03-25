using namespace std;
#pragma once
#include <string>
#include <vector>
#include "Automaton.h"
#ifndef MemberShip_H
class MemberShip
{
public:
	MemberShip();
	MemberShip(Automaton default_Automaton);
	string execute_MemberShip(vector<string> word);
	string concrete_word;
	string pattern_word;
	Automaton default_Automaton;
	string convert_CTP(string concrete_word);
	string run_w_on_A(Automaton default_Automaton, string pattern_word);

	string get_concrete_word(string concrete_word);
	string get_pattern_word(string pattern_word);

private:
	void set_concrete_word(string concrete_word);
	void set_pattern_word(string pattern_word);


};

#endif // !Automaton_H
