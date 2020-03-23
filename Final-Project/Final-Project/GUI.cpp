#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "FileManager.h"
#include "Controller.h"

using namespace std;

void main(int argc, char* argv[]) {
	//should get the parameter from main of the file
	vector<string> fileLines;
	Controller controller;
	string Temp_argv_File_Location="AutomatonFile.txt";
	string fileLine;
	ifstream myfile;
	bool isMembership = 0;
	char split_symbol = ',';

	myfile.open(Temp_argv_File_Location);
	//make sure file opened
	if (!myfile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}


	

	//read all by line
	while (getline(myfile, fileLine))
	{
		//there is no splitter it a word
		if (fileLine.find(split_symbol)== string::npos && fileLine!="")
			isMembership = 1;
		else
		//remove all the split symbols
		fileLine.erase(std::remove(fileLine.begin(), fileLine.end(), split_symbol), fileLine.end());
		
		// Line contains string of length > 0 then save it in vector
		if (fileLine.size() > 0)
			fileLines.insert(fileLines.end(),fileLine);
	}

	if (fileLines.size() > 1) {
		//there is more than one word
	}
	
	controller.set_default_Automaton(controller.buildTheAutomaton(fileLines[0]));


		 
	if (isMembership) {

	}
	else {

	}




	myfile.close();
	cout << "TEST";
	
	return;
}
