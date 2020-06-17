using namespace std;
#pragma once
#include <string>
#include <vector>
#include "Automaton.h"
#include "FileManager.h"
#ifndef MemberShip_H
class MemberShip
{
public:
	string concrete_word;
	string pattern_word;
	vector<string> Cwords;
	vector<string> Pwords;
	Automaton default_Automaton;

	bool execute_MemberShip(string Pword);


	MemberShip(vector<string> fileLines, Automaton default_Automaton);
	MemberShip(Automaton default_Automaton);


	string convert_CTP(string concrete_word, vector<string> ConstsList,int boundVSize);
	string run_w_on_A(Automaton default_Automaton, string pattern_word);

	string get_concrete_word();
	string get_pattern_word();

	

private:
	void set_concrete_word(string concrete_word);
	void set_pattern_word(string pattern_word);
	void set_multy_concrete_word(string concrete_word);
	void set_multy_pattern_word(string pattern_word);



};

#endif // !Automaton_H
