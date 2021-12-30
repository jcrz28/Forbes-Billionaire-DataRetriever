// To run the program: 
// g++  main.cpp src/LinkedList_Database.cpp src/Bubble_Sort.cpp src/User_Prompt.cpp
// ./a.exe

#include "src/LinkedList_Database.h"
#include "src/Bubble_Sort.h"
#include "src/User_Prompt.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void parse_file(ifstream& inputFile, Database& access) {
	string name, networth, country, source, age, rank, industry, ignore;
	int INT_age, INT_rank;
	double DBL_networth;
	
	char extra_endline = '\n';

	while (!inputFile.eof()) {
		getline(inputFile, name, '\t');
		//Removes trailing strings from previous entry. This happens because of the function continue. 
		//It grabs the last string from the previous line. 
		size_t found = name.find(extra_endline);

		if (found != string::npos) {
			name = name.substr(found + 1, name.length());
		}
		getline(inputFile, networth, '\t');

		//removes $ sign and 'B'
		networth = networth.substr(1, networth.length()-1);
		DBL_networth = stod(networth);

		getline(inputFile, country, '\t');
		getline(inputFile, source, '\t');

		getline(inputFile, rank, '\t');
		INT_rank = stoi(rank);

		getline(inputFile, age, '\t');

		//age in dataset is not available
		if (age == "N/A") continue;
		INT_age = stoi(age);

		getline(inputFile, industry, '\n');

		access.append_data(name, DBL_networth, country, source, INT_rank, INT_age, industry);
	}
}
int main() {
	string input_file = "src/input4.txt";
	ifstream inputFile(input_file.c_str());

	Database access;
	prompt b_access;

	parse_file(inputFile, access);
	
	char option;

	do {
		cout << "Welcome to Forbes Billionaire 2021 Data Set.\n";
		cout << "Please select a task from the list below.\n";
		cout << "\n1 - View Entries\n";
		cout << "\n2 - Add Entries\n";
		cout << "\n3 - Delete Entries\n";
		cout << "\n4 - Search Entries\n";
		cout << "\n5 - Search Range\n";
		cout << "\n6 - Sort Entries\n";
		cout << "\n7 - Trim Data Entries\n";
		cout << "\n8 - Exit\n";

		cin >> option;
		switch (option) {

		case '1':
			b_access.print_entries(access);
			break;

		case '2':
			b_access.add_entries(access);
			break;

		case '3':
			b_access.delete_entries(access);
			break;

		case '4':
			b_access.search_entries(access);
			break;

		case '5':
			b_access.search_range(access);
			break;

		case '6':
			b_access.sort_entries(access);
			break;

		case '7':
			b_access.trim_entries(access);
			break;

		case '8':
			b_access.exit_message();
			break;

		default:
			b_access.invalid_input_message();
			break;

		}
	} while (option != '8');

	return 0;
}
