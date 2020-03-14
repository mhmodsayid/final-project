#pragma once


using namespace std;
#include"FileManager.h"

#ifndef Automaton_H

class FileManager
{
public:
	FileManager();
	FileManager(int x);
	void getx();
	void setx();
	~FileManager();


	FileManager operator ++();//++A
	FileManager operator ++(int);//A++

	FileManager operator * (FileManager In);

private:
	int y;
};



#endif // !Automaton_H



