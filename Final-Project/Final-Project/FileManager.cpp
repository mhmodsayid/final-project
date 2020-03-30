#include "FileManager.h"




vector<string> FileManager::ReadFile(char split_symbol)
{

	string fileLine;
	file.open(fileLocation);
	//make sure file opened
	if (!file) {
		cout << "Unable to open file";
		//exit(1); // terminate with error
	}
	while (getline(file, fileLine))
	{
		
		fileLine.erase(std::remove(fileLine.begin(), fileLine.end(), split_symbol), fileLine.end());
		// Line contains string of length > 0 then save it in vector
		if (fileLine.size() > 0)
			fileLines.insert(fileLines.end(), fileLine);
	}
	file.close();
	return fileLines;
}

void FileManager::WriteFile(string result)
{
	file.open(fileLocation);
	//make sure file opened
	if (!file) {
		cout << "Unable to open file";
		//exit(1); // terminate with error
	}
	file << result;
	file.close();
}

void FileManager::setFile(string fLocation)
{
	fileLocation = fLocation;
}





