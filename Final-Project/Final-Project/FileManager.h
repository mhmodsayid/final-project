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
	string fileLocation;
	vector<string> ReadFile(char split_symbol);
	int WriteFile(string result);
	
private:
	void setFile(string fileLocation);
	
};



#endif // !Automaton_H



