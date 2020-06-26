
#include <string>
#include <algorithm>
#include "FileManager.h"
#include "Controller.h"
#include <iostream>
#include <chrono>
using namespace std;
typedef std::chrono::high_resolution_clock Clock;

int main(int argc, char* argv[]) {
	Controller controller;
	string default_Automaton_File_Location = argv[1];
	string learner_File_Location = argv[2];
	char split_symbol = ',';//the symbol split the info in the input file
	auto start_time = Clock::now();//start counting the time
	string results;
	string res= controller.initialze_System(default_Automaton_File_Location, split_symbol);// Decode Default automaton and buid automaton class
	if (res.find("Error") != string::npos)//Could not open Default automaton file
		results = res;
	else 
		results = controller.analyze_file(learner_File_Location, split_symbol);//Decode input file from learner

	auto end_time = Clock::now();
	std::cout << "Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() / 1000000000.0 << " seconds" << std::endl;//Print the time in seconds

	cout << results << endl;
	return 0;
}
