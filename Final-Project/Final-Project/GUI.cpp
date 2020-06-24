
#include <string>
#include <algorithm>
#include "FileManager.h"
#include "Controller.h"
#include <iostream>
#include <chrono>
using namespace std;
typedef std::chrono::high_resolution_clock Clock;

int main(int argc, char* argv[]) {
	//should get the parameter from main of the file
	//cout << argv[1];
	Controller controller;
	//string default_Automaton_File_Location = argv[1];
	//string learner_File_Location = argv[2];

	string learner_File_Location = "LearnerFile.txt";
	//string learner_File_Location = "test5_notEqual_difAcceptState.txt";
	//string learner_File_Location = "MultyþþConcreteWord.txt";
	string default_Automaton_File_Location = "AutomatonFile.txt";
	char split_symbol = ',';
	auto start_time = Clock::now();//start counting the time
	string results;
	
	string res= controller.initialze_System(default_Automaton_File_Location, split_symbol);
	if (res.find("Error") != string::npos)
		results = res;
	else 
		results = controller.analyze_file(learner_File_Location, split_symbol);

	auto end_time = Clock::now();
	std::cout << "Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() / 1000000000.0 << " seconds" << std::endl;

	cout << results << endl;
	return 0;
}
