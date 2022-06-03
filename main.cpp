#include "src/UserPrompt/User_Prompt.h"

int main() {
	std::string input_file = "src/inputFiles/input1.txt";
	std::ifstream inputFile(input_file.c_str());

	Prompt user_prompt;

	user_prompt.loadEntries(inputFile);
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
			user_prompt.printEntries();
			break;

		case '2':
			user_prompt.addEntries();
			break;

		case '3':
			user_prompt.deleteEntries();
			break;

		case '4':
			user_prompt.searchEntries();
			break;

		case '5':
			user_prompt.sortEntries();
			break;

		case '6':
			user_prompt.exitMessage();
			break;

		default:
			user_prompt.invalidMessage();
			break;
		}

	} while (option != '6');
	
	return 0;
}
