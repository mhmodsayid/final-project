#include "FileManager.h"

//function receives split sympol, reads the file and split the content according to the symbol 
//return the splited content in a vector of string 
vector<string> FileManager::ReadFile(char split_symbol)
{

	string fileLine="";
	vector<string> fileData;
	bool flag = false;//detrmine if its membership query or equevilance query
	file.open(fileLocation);
	//make sure file opened
	if (!file) {
		fileData.push_back("Error");
		return fileData;
	}
	while (getline(file, fileLine))
	{
		size_t pos = 0;
		string token;
		//if we get equevilance file we preform split by symbol,else we dont
		while ((pos = fileLine.find(split_symbol)) != string::npos) {
			token = fileLine.substr(0, pos);
			fileData.push_back(token);
			fileLine.erase(0, pos + 1);
			flag = true;
		}

		//we add a split symbol to the end of the array to indicate it is equevilance query
		if (flag)
		{
			fileData.push_back(fileLine);
			fileData.push_back(string(1, split_symbol));
		}			
		else
			fileData.push_back(fileLine);
	}
	
	file.close();
	return fileData;
}

//function receives the result as a string and write it to a file 
//returns 1 if there is an error else 0
int FileManager::WriteFile(string result)
{
	file.open(fileLocation, ios::out);
	//make sure file opened
	if (!file) {
		cout << "Unable to open file";
		return 1;
	}
	file << result;
	file.close();
	return 0;
}

//set file location 
void FileManager::setFile(string fLocation)
{
	fileLocation = fLocation;
}





