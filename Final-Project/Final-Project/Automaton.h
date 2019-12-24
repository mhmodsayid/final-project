using namespace std;
#include"FileManager.h"

#ifndef Automaton_H


struct node
{
	bool is_accept;
	struct node* next_transition;
	struct node* next_state;
	char state;
	char alphabet;//input alpha

}typedef Node;

class Automaton : public FileManager  //only declaration //inhabitance from file manager
{
public:
	Automaton();
	Automaton(int x);
	void getx();
	void setx();
	~Automaton();
	

	Automaton operator ++();//++A
	Automaton operator ++(int);//A++

	Automaton operator * (Automaton In);

private:
	int y;
};



#endif // !Automaton_H



