#include "User_Prompt.h"

void Prompt::fields() {
	std::cout << "\na - Name\n";
	std::cout << "\nb - Networth\n";
	std::cout << "\nc - Country\n";
	std::cout << "\nd - Source\n";
	std::cout << "\ne - Rank\n";
	std::cout << "\nf - Age\n";
	std::cout << "\ng - Industry\n";
}

std::string Prompt::toField(char option) {
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
	return (option == 'a' || option == 'b' || option == 'c' || option == 'd' || 
			option == 'e' || option == 'f' || option == 'g');
}

void Prompt::loadEntries(std::ifstream& inputFile){
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
	return;
}

void Prompt::printEntries() {
	return print();
}

void Prompt::addEntries() {
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

	return insertData(name, networth, country, source, rank, age, industry, position);
}

void Prompt::deleteEntries() {
	char option;
	std::string input_data;

	std::cout << "Select a field to delete:\n";
	fields();

	std::cin >> option;

	if (validOptions(option)){
		std::string field = toField(option);

		std::cout << "Enter the " << field << " you want to delete:";
		std::cin.ignore();
		std::getline(std::cin, input_data);

		return deleteData(field, input_data);
	}
	return invalidMessage();
}

void Prompt::searchEntries() {
	char option;
	std::string input_data;

	std::cout << "Select a field to search:\n";
	fields();

	std::cin >> option;

	if (validOptions(option)){
		std::string field = toField(option);

		std::cout << "Enter the " << field << " you want to search:";
		std::cin.ignore();
		std::getline(std::cin, input_data);

		return filterData(field, input_data);
	}
	return invalidMessage();
}

void Prompt::chooseOrder (char option) {
	std::cout << "Select the sorting order:\n";
	std::cout << "\na - Ascending order\n";
	std::cout << "\nb - Descending order\n";

	std::cin >> option;
	return (option == 'a' || option == 'b')? bubbleSort(toField(option), option) : invalidMessage();
}

void Prompt::sortEntries() {
	char option;

	std::cout << "Select a field to sort:\n";
	fields();

	std::cin >> option;
	return validOptions(option)? chooseOrder(option) : invalidMessage();
}

void Prompt::invalidMessage() {
	std::cout << "\nSorry invalid option. Please try again.\n\n";
}

void Prompt::exitMessage() {
	std::cout << "\nThank you, goodbye.\n";
}
