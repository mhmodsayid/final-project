#pragma once


using namespace std;
#include"FileManager.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#ifndef FileManager_H
#define FileManager_H
class FileManager
{
public:
	
	fstream file;
	vector<string> fileLines;

	FileManager operator ++();//++A
	FileManager operator ++(int);//A++

	FileManager operator * (FileManager In);

	string fileLocation;
	vector<string> ReadFile(char split_symbol);
	void WriteFile(string result);
	void setFile(string fileLocation);

private:
	
};



#endif // !Automaton_H



