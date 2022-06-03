#pragma once
#ifndef USERPROMPT
#define USERPROMPT

#include "../LinkedList/LinkedList.h"
#include <string>
#include <iostream>
#include <fstream>

class Prompt: public LinkedList {
public:
	void fields();

	std::string toField(char option);
	
	void chooseOrder(char option);

	bool validOptions(char option);

	void invalidMessage();
	

	void loadEntries(std::ifstream& inputFile);

	/*Main user options*/
	
	void printEntries();

	void addEntries();

	void deleteEntries();

	void searchEntries();

	void sortEntries();

	void exitMessage();

};
#endif // !USERPROMPT
