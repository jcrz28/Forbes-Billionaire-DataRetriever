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
	if (option == 'a') return "name";
	else if (option == 'b') return "networth";
	else if (option == 'c') return "country";
	else if (option == 'd') return "source";
	else if (option == 'e') return "rank";
	else if (option == 'f') return "age";
	else if (option == 'g') return "industry";
	else return "";
}

string prompt::char_option_to_str_field_2(char option) {
	if (option == 'a') return "networth";
	else if (option == 'b') return "rank";
	else if (option == 'c') return "age";
	else return "position";
}

void prompt::get_word(Database& access, string task, char option) {
	string data;
	string field = char_option_to_str_field(option);

	cout << "Enter the " << field << " you want to " << task << ":";
	cin.ignore();
	getline(cin, data);

	access.string_task(task, field, data);
}

void prompt::get_num(Database& access, string task, char option) {
	double num;
	string field = char_option_to_str_field(option);

	cout << "Enter the " << field << " you want to " << task << ":";
	cin >> num;

	access.num_task(task, field, num);
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

	switch (option) {

	case 'a':
		get_word(access, task, option);
		break;

	case 'b':
		get_num(access, task, option);
		break;

	case 'c':
		get_word(access, task, option);
		break;

	case 'd':
		get_word(access, task, option);
		break;

	case 'e':
		get_num(access, task, option);
		break;

	case'f':
		get_num(access, task, option);
		break;
	case 'g':
		get_word(access, task, option);
		break;

	default:
		invalid_input_message();
		break;
	}
}

void prompt::search_entries(Database& access) {

	string task = "search";
	string search;
	char option{};

	cout << "Select a field to search:\n";
	all_fields();

	cin >> option;

	switch (option) {

	case 'a':
		get_word(access, task, option);
		break;

	case 'b':
		get_num(access, task, option);
		break;

	case 'c':
		get_word(access, task, option);
		break;

	case 'd':
		get_word(access, task, option);
		break;

	case 'e':
		get_num(access, task, option);
		break;

	case 'f':
		get_num(access, task, option);
		break;

	case 'g':
		get_word(access, task, option);
		break;

	default:
		invalid_input_message();
		break;
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
	switch (option) {
	case'a':
		get_interval(access, task, option, first_interval, second_interval);
		break;
	case 'b':
		get_interval(access, task, option, first_interval, second_interval);
		break;
	case 'c':
		get_interval(access, task, option, first_interval, second_interval);
		break;
	default:
		invalid_input_message();
		break;
	}
}

void prompt::sort_entries(Database& access) {
	char option{};

	cout << "Select a field to sort:\n";
	num_fields();

	cin >> option;

	switch (option) {
	case 'a':
		choose_order(access, option);
		break;

	case 'b':
		choose_order(access, option);
		break;

	case 'c':
		choose_order(access, option);
		break;

	default:
		invalid_input_message();
		break;
	}
}

void prompt::choose_order(Database& access, char option) {
	string field = char_option_to_str_field_2(option);
	char option2{};

	cout << "Select the sorting order:\n";
	cout << "\na - Ascending order\n";
	cout << "\nb - Descending order\n";

	cin >> option2;

	switch (option2) {
	case 'a':
		perform_sorting(access, field, option2);
		break;

	case 'b':
		perform_sorting(access, field, option2);
		break;

	default:
		invalid_input_message();
		break;
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
