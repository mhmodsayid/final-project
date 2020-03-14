#include "FileManager.h"

FileManager::FileManager()
{

}

FileManager::~FileManager()
{
}

FileManager FileManager::operator++()
{
	return FileManager();
}

FileManager FileManager::operator++(int)
{
	return FileManager();
}

FileManager FileManager::operator*(FileManager In)
{
	return FileManager();
}



