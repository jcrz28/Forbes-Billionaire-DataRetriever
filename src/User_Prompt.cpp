#include "User_Prompt.h"
#include "LinkedList.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void Prompt::all_fields() {
	cout << "\na - Name\n";

	cout << "\nb - Networth\n";

	cout << "\nc - Country\n";

	cout << "\nd - Source\n";

	cout << "\ne - Rank\n";

	cout << "\nf - Age\n";

	cout << "\ng - Industry\n";
}

void Prompt::num_fields() {
	cout << "\na - Networth\n";

	cout << "\nb - Rank\n";

	cout << "\nc - Age\n";
}

string Prompt::char_option_to_str_field(char option) {
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

string Prompt::char_option_to_str_field_2(char option) {
	switch (option){
	case 'a':
		return "networth";
	
	case 'b':
		return "rank";

	case 'c':
		return "age";
	
	default:
		return "position";
	}
}

void Prompt::get_input_data(LinkedList& access, string task, char option) {
	string input_data;
	string field = char_option_to_str_field(option);

	cout << "Enter the " << field << " you want to " << task << ":";
	cin.ignore();
	getline(cin, input_data);

	if (option == 'b' || option == 'e' || option == 'f'){
		access.num_task(task, field, stod(input_data));
	}
	else{
		access.string_task(task, field, input_data);
	}
}

void Prompt::print_entries(LinkedList& access) {
	access.print();
}

void Prompt::add_entries(LinkedList& access) {
	string name, country, source, industry;
	int rank, age, position;
	float networth;

	cout << "Position Number:";
	cin >> position;

	cout << "\nName:";
	cin.ignore();
	getline(cin, name);

	cout << "\nNetWorth:";
	cin >> networth;

	cout << "\nCountry:";
	cin.ignore();
	getline(cin, country);

	cout << "\nSource:";
	getline(cin, source);

	cout << "\nRank:";
	cin >> rank;

	cout << "\nAge:";
	cin >> age;

	cout << "\nIndustry:";
	cin.ignore();
	getline(cin, industry);
	cout << '\n';

	access.insertNewData(name, networth, country, source, rank, age, industry, position);
}

void Prompt::delete_entries(LinkedList& access) {

	string task = "delete";
	string field;
	char option;

	cout << "Select a field to delete:\n";
	all_fields();

	cin >> option;

	if (option == 'a' || option == 'b' || option == 'c' || option == 'd' || option == 'e' || option == 'f' || option == 'g'){
		get_input_data(access, task, option);
	}
	else{
		invalid_input_message();
	}
}

void Prompt::search_entries(LinkedList& access) {

	string task = "search";
	string search;
	char option{};

	cout << "Select a field to search:\n";
	all_fields();

	cin >> option;
	
	if (option == 'a' || option == 'b' || option == 'c' || option == 'd' || option == 'e' || option == 'f' || option == 'g'){
		get_input_data(access, task, option);
	}
	else{
		invalid_input_message();
	}
}

void Prompt::sort_entries(LinkedList& access) {
	char option{};

	cout << "Select a field to sort:\n";
	num_fields();

	cin >> option;

	if (option == 'a' || option == 'b' || option == 'c'){
		choose_order(access, option);
	}
	else{
		invalid_input_message();
	}
}

void Prompt::choose_order(LinkedList& access, char option) {
	string field = char_option_to_str_field_2(option);
	char option2{};

	cout << "Select the sorting order:\n";

	cout << "\na - Ascending order\n";

	cout << "\nb - Descending order\n";

	cin >> option2;

	if (option == 'a' || option == 'b' || option == 'c'){
		perform_sorting(access, field, option2);
	}
	else{
		invalid_input_message();
	}
}



void Prompt::invalid_input_message() {
	cout << "\nSorry invalid option. Please try again.\n\n";
}

void Prompt::exit_message() {
	cout << "\nThank you, goodbye.\n";
}
