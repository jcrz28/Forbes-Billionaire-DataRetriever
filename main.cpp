#include "src/LinkedList/LinkedList.h"
#include "src/UserPrompt/User_Prompt.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void parseFile(std::ifstream& inputFile, LinkedList& access) {
	std::string name, networth, country, source, age, rank, industry, ignore;

	while (!inputFile.eof()) {
		getline(inputFile, name, '\t');

		//Removes trailing strings from previous entry.
		size_t found = name.find('\n');

		if (found != std::string::npos) {
			name = name.substr(found + 1, name.length());
		}
		getline(inputFile, networth, '\t');

		//removes $ sign, 'B', and leading space
		networth = networth.substr(1, networth.length()-3);
		
		getline(inputFile, country, '\t');

		getline(inputFile, source, '\t');

		getline(inputFile, rank, '\t');

		getline(inputFile, age, '\t');

		if (age == "N/A") continue;

		getline(inputFile, industry, '\n');

		access.appendData(name, networth, country, source, rank, age, industry);
	}
}

int main() {
	std::string input_file = "src/inputFiles/input1.txt";
	std::ifstream inputFile(input_file.c_str());

	LinkedList access;
	Prompt user_prompt;
	parseFile(inputFile, access);

	char option;
	
	do {
		std::cout << "Welcome to Forbes Billionaire 2021 Data Set.\n";
		std::cout << "Please select a task from the list below.\n";
		std::cout << "\n1 - View Entries\n";
		std::cout << "\n2 - Add Entries\n";
		std::cout << "\n3 - Delete Entries\n";
		std::cout << "\n4 - Search Entries\n";
		std::cout << "\n5 - Sort Entries\n";
		std::cout << "\n6 - Exit\n";

		std::cin >> option;
		switch (option) {

		case '1':
			user_prompt.print_entries(access);
			break;

		case '2':
			user_prompt.add_entries(access);
			break;

		case '3':
			user_prompt.delete_entries(access);
			break;

		case '4':
			user_prompt.search_entries(access);
			break;

		case '5':
			user_prompt.sort_entries(access);
			break;

		case '6':
			user_prompt.exit_message();
			break;

		default:
			user_prompt.invalid_input_message();
			break;
		}

	} while (option != '6');
	
	return 0;
}
