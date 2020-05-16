#include "FileManager.h"




vector<string> FileManager::ReadFile(char split_symbol)
{

	string fileLine="";
	vector<string> fileData;
	bool flag = false;//detrmine if its membership query or equevilance query
	file.open(fileLocation);
	//make sure file opened
	if (!file) {
		cout << "Unable to open file";
		//exit(1); // terminate with error
	}
	while (getline(file, fileLine))
	{
		
		//size_t found = fileLine.find(split_symbol);
		//if (found != string::npos)//equevilance query
			//flag = true;
		size_t pos = 0;
		string token;
		//string s;
		while ((pos = fileLine.find(split_symbol)) != string::npos) { //if we get equevilance file we preform split by symbol,else we dont
			token = fileLine.substr(0, pos);
			fileData.push_back(token);
			fileLine.erase(0, pos + 1);
			flag = true;
		}

		if (flag)
		{
			fileData.push_back(fileLine);
			fileData.push_back(string(1, split_symbol));//add to the end of the array symbol to know its equevilance
		}
			
		else
			fileData.push_back(fileLine);

	
	}
	
	file.close();
	return fileData;
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





