#pragma once

using namespace std;

#ifndef Automaton_H
#define Automaton_H
#include<string>
#include<vector>

//transition struct contains two fields 
struct Trans
{
	struct node* next_state;
	string transition_signal; 

	Trans() //Constructor
	{
		next_state = NULL;
		transition_signal = ' ';
	}
}typedef Trans;

//node of the list struct 
struct node
{
	bool is_accept=false;//is the state is accepting state 
	bool has_free_varialbe = false; //if the node vontains free variable 
	struct node* next_state;
	int state; //number of state 
	vector <Trans> Constant_Trans_list;//transition list of the constant 
	vector <Trans> Variable_Trans_list;//transition list of the bound variable and the free variable 


	node() //Constructor
	{
		next_state = NULL;
		state = 0;
		is_accept = false;
	}
}typedef Node;


class Automaton //only declaration //inhabitance from file manager
{
public:
	
	vector <string> alphabetList;
	vector <node*> pointer_array;
	vector<bool> temp_accept_states;
	int boundVSize;
	int alphabetSize;
	int statesNumbe;
	int acceptStateNum;
	int transNum;
	int freeVariableShifter = 0;
		
	void restore_states();
    int getBoundVSize() const; 
    int getAlphabetSize() const;  
    int getStatesNumbe() const;   
    int getAcceptStateNum() const;   
    int getTransNum() const;  
	vector<string> getAlphabetList() const;	
	node* getPointerarray(int index) const;
	vector <node*> getPointerarray() const;
	

	void setBoundVSize(int boundVSize);
	void setAlphabetSize(int alphabetSize);
	void setStatesNumbe(int statesNumbe);
	void setAcceptStateNum(int acceptStateNum);
	void setTransNum(int transNum);
	void setAlphabetList(vector<string> alphabetList);
	void setPointerarray(vector<node*> pointerarray);

};



#endif // !Automaton_H



