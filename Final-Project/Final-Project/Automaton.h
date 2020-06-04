#pragma once

using namespace std;

#ifndef Automaton_H
#define Automaton_H
#include<string>
#include<vector>
struct Trans
{
	struct node* next_state;
	string transition_signal;//input alpha

	Trans() //Constructor
	{
		next_state = NULL;
		transition_signal = ' ';
	}
}typedef Trans;
struct node
{
	bool is_accept=false;
	bool has_free_varialbe = false;
	struct node* next_state;
	int state;
	//char transition_signal;//input alpha
	vector <Trans> Constant_Trans_list;
	vector <Trans> Variable_Trans_list;


	node() //Constructor
	{
		//next_transition = NULL;
		next_state = NULL;
		//last_transition = NULL;
		state = 0;
		//transition_signal = ' ';
		is_accept = false;
	}
}typedef Node;




class Automaton //only declaration //inhabitance from file manager
{
public:
	Automaton();
	Automaton(int x);
	int freeVariableShifter = 0;
	~Automaton();
	

	Automaton operator ++();//++A
	Automaton operator ++(int);//A++
	Automaton operator ~();//complement
	Automaton& operator * (Automaton& A);
	vector <string> alphabetList;
	int boundVSize;
	int alphabetSize;
	int statesNumbe;
	int acceptStateNum;
	int transNum;
	//string transList;//
	//string automataList;//
	//we can add the list 
	vector <node*> pointer_array;
	vector<bool> temp_accept_states;
private:
	int y;
	
public:
	void restore_states();
    int getBoundVSize() const;
    void setBoundVSize(int boundVSize);

    int getAlphabetSize() const;
    void setAlphabetSize(int alphabetSize);

   

    int getStatesNumbe() const;
    void setStatesNumbe(int statesNumbe);

    int getAcceptStateNum() const;
    void setAcceptStateNum(int acceptStateNum);

   
    int getTransNum() const;
    void setTransNum(int transNum);

   

    int getY() const;
    void setY(int y);

public:
    vector<string> getAlphabetList() const;

	void setAlphabetList(vector<string> alphabetList);

public:
    node* getPointerarray(int index) const;
	vector <node*> getPointerarray() const;
    void setPointerarray(vector<node*> pointerarray);

};



#endif // !Automaton_H



