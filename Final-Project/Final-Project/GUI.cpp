
#include <string>
#include <algorithm>
#include "FileManager.h"
#include "Controller.h"
#include <iostream>

using namespace std;

void main(int argc, char* argv[]) {
	//should get the parameter from main of the file
	Controller controller;
	string default_Automaton_File_Location ="AutomatonFile.txt";
	string learner_File_Location = "LearnerFile.txt";

	char split_symbol = ',';

	controller.initialze_System(default_Automaton_File_Location, split_symbol);
	controller.analyze_file(learner_File_Location, split_symbol);
	
	return;
}
