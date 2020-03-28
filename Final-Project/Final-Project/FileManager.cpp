#include "FileManager.h"




vector<string> FileManager::ReadFile(char split_symbol)
{
	string fileLine;
	while (getline(file, fileLine))
	{
		//there is no splitter it a word
		//if (fileLine.find(split_symbol) == string::npos && fileLine != "")
		//	isMembership = 1;
		//else
			//remove all the split symbols
			fileLine.erase(std::remove(fileLine.begin(), fileLine.end(), split_symbol), fileLine.end());

		// Line contains string of length > 0 then save it in vector
		if (fileLine.size() > 0)
			fileLines.insert(fileLines.end(), fileLine);
	}



	return fileLines;
}

void FileManager::WriteFile(string result)
{
}

void FileManager::setFile(string fileLocation)
{
	file.open(fileLocation);
	//make sure file opened
	if (!file) {
		cout << "Unable to open file";
		//exit(1); // terminate with error
	}
}

ifstream FileManager::getFile()
{
	return ifstream();
}



