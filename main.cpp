#include "src/LinkedList/LinkedList.h"
#include "src/UserPrompt/User_Prompt.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int main() {
	std::string input_file = "src/inputFiles/input1.txt";
	std::ifstream inputFile(input_file.c_str());

	LinkedList access;
	Prompt user_prompt;

	user_prompt.load_entries(inputFile);
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
			user_prompt.print_entries();
			break;

		case '2':
			user_prompt.add_entries();
			break;

		case '3':
			user_prompt.delete_entries();
			break;

		case '4':
			user_prompt.search_entries();
			break;

		case '5':
			user_prompt.sort_entries();
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
