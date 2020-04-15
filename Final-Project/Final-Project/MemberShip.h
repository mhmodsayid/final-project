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
	MemberShip(FileManager &file_To_read, Automaton default_Automaton);
	MemberShip(Automaton default_Automaton);
	bool execute_MemberShip(vector<string>);
	//string execute_MemberShip(vector<string> word);
	

	string convert_CTP(string concrete_word, vector<char> ConstsList,int );
	string run_w_on_A(Automaton default_Automaton, string pattern_word);

	string get_concrete_word();
	string get_pattern_word();

	string concrete_word;
	string pattern_word;
	Automaton default_Automaton;

private:
	void set_concrete_word(string concrete_word);
	void set_pattern_word(string pattern_word);


};

#endif // !Automaton_H
