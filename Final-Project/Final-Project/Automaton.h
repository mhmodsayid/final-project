using namespace std;
#include"FileManager.h"

#ifndef Automaton_H

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



