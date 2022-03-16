#include "User_Prompt.h"
#include "LinkedList_Database.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void prompt::all_fields() {
	cout << "\na - Name\n";

	cout << "\nb - Networth\n";

	cout << "\nc - Country\n";

	cout << "\nd - Source\n";

	cout << "\ne - Rank\n";

	cout << "\nf - Age\n";

	cout << "\ng - Industry\n";
}

void prompt::num_fields() {
	cout << "\na - Networth\n";

	cout << "\nb - Rank\n";

	cout << "\nc - Age\n";
}

string prompt::char_option_to_str_field(char option) {
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

string prompt::char_option_to_str_field_2(char option) {
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

void prompt::get_input_data(Database& access, string task, char option) {
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

void prompt::perform_range_task(Database& access, string task, string field, int num1, int num2) {
	if (task == "search") {
		access.filter_range(field, num1, num2);
	}
	else if (task == "delete") {
		access.trim(num1, num2);
	}
}

bool prompt::get_interval(Database& access, string task, char option, int &first_interval, int& second_interval) {
	string field = char_option_to_str_field_2(option);
	cout << "Enter the " << field << "s you want to " << task << ":\n";

	cin.ignore();

	cout << "\nFirst Interval:";
	cin >> first_interval;

	cout << "\nSecond Interval:";
	cin >> second_interval;

	if (first_interval > second_interval) {
		cout << "\nInvalid interval. Please try again.\n";
		cout << "HINT: Second input must be larger than the first input\n\n";
		return false;
	}

	perform_range_task(access, task, field, first_interval, second_interval);
	return true;
}

void prompt::print_entries(Database& access) {
	access.print();
}

void prompt::add_entries(Database& access) {
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

void prompt::delete_entries(Database& access) {

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

void prompt::search_entries(Database& access) {

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

void prompt::search_range(Database& access) {
	int first_interval, second_interval;
	char option{};
	string field;
	string task = "search";

	cout << "Select a field to search:\n";
	num_fields();

	cin >> option;

	if (option == 'a' || option == 'b' || option == 'c'){
		get_interval(access, task, option, first_interval, second_interval);
	}
	else{
		invalid_input_message();
	}
}

void prompt::sort_entries(Database& access) {
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

void prompt::choose_order(Database& access, char option) {
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

void prompt::trim_entries(Database& access) {
	int first_interval, second_interval;

	string task = "delete";
	char option = ' ';

	get_interval(access, task, option, first_interval, second_interval);
}

void prompt::invalid_input_message() {
	cout << "\nSorry invalid option. Please try again.\n\n";
}

void prompt::exit_message() {
	cout << "\nThank you, goodbye.\n";
}
