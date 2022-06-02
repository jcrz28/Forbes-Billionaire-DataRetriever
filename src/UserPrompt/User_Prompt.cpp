#include "User_Prompt.h"

void Prompt::all_fields() {
	std::cout << "\na - Name\n";

	std::cout << "\nb - Networth\n";

	std::cout << "\nc - Country\n";

	std::cout << "\nd - Source\n";

	std::cout << "\ne - Rank\n";

	std::cout << "\nf - Age\n";

	std::cout << "\ng - Industry\n";
}

std::string Prompt::convertOptionField(char option) {
	switch (option){
	case 'a':
		return "name";
	
	case 'b':
		return "networth";

	case 'c':
		return "country";
	
	case 'd':
		return "source";

	case 'e':
		return "rank";
	
	case 'f':
		return "age";

	case 'g':
		return "industry";
	
	default:
		return "";
	}
	
}

bool Prompt::validOptions(char option){
	return (option == 'a' || option == 'b' || option == 'c' || option == 'd' || option == 'e' || option == 'f' || option == 'g');
}

void Prompt::get_input_data(std::string task, char option) {
	std::string input_data;
	std::string field = convertOptionField(option);

	std::cout << "Enter the " << field << " you want to " << task << ":";
	std::cin.ignore();
	std::getline(std::cin, input_data);
	
	return task == "delete" ? deleteData(field, input_data) : filterData(field, input_data);
}

void Prompt::load_entries(std::ifstream& inputFile){
	std::string name, networth, country, source, age, rank, industry, ignore;
	int pos = 0;
	
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

		insertData(name, networth, country, source, rank, age, industry, pos);
		pos++;
	}
}

void Prompt::print_entries() {
	print();
}

void Prompt::add_entries() {
	std::string name, country, source, industry, rank, age, networth;
	int position;

	std::cout << "Position Number:";
	std::cin >> position;

	std::cout << "\nName:";
	std::cin.ignore();
	std::getline(std::cin, name);

	std::cout << "\nNetWorth:";
	std::cin >> networth;

	std::cout << "\nCountry:";
	std::cin.ignore();
	std::getline(std::cin, country);

	std::cout << "\nSource:";
	std::getline(std::cin, source);

	std::cout << "\nRank:";
	std::cin >> rank;

	std::cout << "\nAge:";
	std::cin >> age;

	std::cout << "\nIndustry:";
	std::cin.ignore();
	std::getline(std::cin, industry);
	std::cout << '\n';

	insertData(name, networth, country, source, rank, age, industry, position);
}

void Prompt::delete_entries() {
	char option;

	std::cout << "Select a field to delete:\n";
	all_fields();

	std::cin >> option;
	return validOptions(option) ? get_input_data("delete", option) : invalid_input_message();
}

void Prompt::search_entries() {
	char option;

	std::cout << "Select a field to search:\n";
	all_fields();

	std::cin >> option;
	return validOptions(option) ? get_input_data("search", option) : invalid_input_message();
}

void Prompt::chooseOrder (char option) {
	std::string field = convertOptionField(option);
	std::cout << "Select the sorting order:\n";

	std::cout << "\na - Ascending order\n";

	std::cout << "\nb - Descending order\n";

	std::cin >> option;
	return (option == 'a' || option == 'b')? bubbleSort(field, option) : invalid_input_message();
}

void Prompt::sort_entries() {
	char option;

	std::cout << "Select a field to sort:\n";
	all_fields();

	std::cin >> option;
	return validOptions(option)? chooseOrder(option) : invalid_input_message();
}

void Prompt::invalid_input_message() {
	std::cout << "\nSorry invalid option. Please try again.\n\n";
}

void Prompt::exit_message() {
	std::cout << "\nThank you, goodbye.\n";
}
