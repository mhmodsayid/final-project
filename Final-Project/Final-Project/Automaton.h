#pragma once

using namespace std;

#ifndef Automaton_H
#define Automaton_H
#include<string>
#include<vector>
struct node
{
	bool is_accept;
	struct node* next_transition;
	struct node* next_state;
	char state;
	char alphabet;//input alpha

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
	string acceptStateList;
	int transNum;
	string transList;
	string automataList;

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



