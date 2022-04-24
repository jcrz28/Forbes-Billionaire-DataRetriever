#include "User_Prompt.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void Prompt::all_fields() {
	std::cout << "\na - Name\n";

	std::cout << "\nb - Networth\n";

	std::cout << "\nc - Country\n";

	std::cout << "\nd - Source\n";

	std::cout << "\ne - Rank\n";

	std::cout << "\nf - Age\n";

	std::cout << "\ng - Industry\n";
}

void Prompt::num_fields() {
	std::cout << "\na - Networth\n";

	std::cout << "\nb - Rank\n";

	std::cout << "\nc - Age\n";
}

std::string Prompt::char_option_to_str_field(char option) {
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

std::string Prompt::char_option_to_str_field_2(char option) {
	switch (option){
	case 'a':
		return "networth";
	
	case 'b':
		return "rank";

	case 'c':
		return "age";
	
	default:
		return "";
	}
}

void Prompt::get_input_data(LinkedList& access, std::string task, char option) {
	std::string input_data;
	std::string field = char_option_to_str_field(option);

	std::cout << "Enter the " << field << " you want to " << task << ":";
	std::cin.ignore();
	std::getline(std::cin, input_data);

	access.getTask(task, field, input_data);
}

void Prompt::print_entries(LinkedList& access) {
	access.print();
}

void Prompt::add_entries(LinkedList& access) {
	std::string name, country, source, industry;
	std::string rank, age, networth;
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

	access.insertData(name, networth, country, source, rank, age, industry, position);
}

void Prompt::delete_entries(LinkedList& access) {
	std::string task = "delete";
	char option;

	std::cout << "Select a field to delete:\n";
	all_fields();

	std::cin >> option;

	if (option == 'a' || option == 'b' || option == 'c' || option == 'd' || option == 'e' || option == 'f' || option == 'g'){
		return get_input_data(access, task, option);
	}
	return invalid_input_message();
}

void Prompt::search_entries(LinkedList& access) {
	std::string task = "search";
	char option;

	std::cout << "Select a field to search:\n";
	all_fields();

	std::cin >> option;
	
	if (option == 'a' || option == 'b' || option == 'c' || option == 'd' || option == 'e' || option == 'f' || option == 'g'){
		return get_input_data(access, task, option);
	}
	return invalid_input_message();
}

void Prompt::sort_entries(LinkedList& access) {
	char option;

	std::cout << "Select a field to sort:\n";
	num_fields();

	std::cin >> option;

	if (option == 'a' || option == 'b' || option == 'c'){
		return choose_order(access, option);
	}
	return invalid_input_message();
}

void Prompt::choose_order(LinkedList& access, char option) {
	std::string field = char_option_to_str_field_2(option);
	char option2;

	std::cout << "Select the sorting order:\n";

	std::cout << "\na - Ascending order\n";

	std::cout << "\nb - Descending order\n";

	std::cin >> option2;

	if (option2 == 'a' || option2 == 'b'){
		return access.sort(field, option2);
	}
	return invalid_input_message();
}

void Prompt::invalid_input_message() {
	std::cout << "\nSorry invalid option. Please try again.\n\n";
}

void Prompt::exit_message() {
	std::cout << "\nThank you, goodbye.\n";
}
