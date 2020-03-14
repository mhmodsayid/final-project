#include <iostream>
#include <fstream>
#include <string>
#include "FileManager.h"
using namespace std;

void main(int argc, char* argv[]) {
	//should get the parametr from main of the file

	string Temp_argv_File_Location="AutomatonFile.txt";
	string file_content;
	string temp;
	ifstream myfile;

	myfile.open(Temp_argv_File_Location);
	//make sure file opened
	if (!myfile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
	//read all the file
	while (myfile >> temp) 
		file_content = file_content + temp;

	char* pch;
	pch = strtok(file_content, " ,.-");
	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ,.-");
	}

	myfile.close();
	cout << "TEST";
	//FileManager f;
	//ddmhhh
}
