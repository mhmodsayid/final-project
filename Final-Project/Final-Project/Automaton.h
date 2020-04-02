#pragma once

using namespace std;

#ifndef Automaton_H
#define Automaton_H
#include<string>
#include<vector>
struct node
{
	bool is_accept=false;
	struct node* next_transition;
	struct node* next_state;
	struct node* last_transition;
	int state;
	char transition_signal;//input alpha

	node() //Constructor
	{
		next_transition = NULL;
		next_state = NULL;
		last_transition = NULL;
		state = 0;
		transition_signal = ' ';
		is_accept = false;
	}
}typedef Node;


class Automaton //only declaration //inhabitance from file manager
{
public:
	Automaton();
	Automaton(int x);
	
	~Automaton();
	

	Automaton operator ++();//++A
	Automaton operator ++(int);//A++

	Automaton operator * (Automaton In);


	int boundVSize;
	int alphabetSize;
	vector <char> alphabetList;
	int statesNumbe;
	int acceptStateNum;
	vector <int> acceptStateList;
	int transNum;
	string transList;
	string automataList;
	vector <node*> pointer_array;

private:
	int y;
public:
    int getBoundVSize() const;
    void setBoundVSize(int boundVSize);

    int getAlphabetSize() const;
    void setAlphabetSize(int alphabetSize);

   

    int getStatesNumbe() const;
    void setStatesNumbe(int statesNumbe);

    int getAcceptStateNum() const;
    void setAcceptStateNum(int acceptStateNum);

    string getAcceptStateList() const;
    void setAcceptStateList(string acceptStateList);

    int getTransNum() const;
    void setTransNum(int transNum);

    string getTransList() const;
    void setTransList(string transList);

    string getAutomataList() const;
    void setAutomataList(string automataList);

    int getY() const;
    void setY(int y);

public:
    vector<char> getAlphabetList() const;
    void setAlphabetList(vector<char> alphabetList);

};



#endif // !Automaton_H



