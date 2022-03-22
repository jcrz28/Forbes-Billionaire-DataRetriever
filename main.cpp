// To run the program: 
// g++  main.cpp src/LinkedList.cpp src/Bubble_Sort.cpp src/User_Prompt.cpp
// ./a.exe

#include "src/LinkedList.h"
#include "src/Bubble_Sort.h"
#include "src/User_Prompt.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void parseFile (ifstream& inputFile, LinkedList& access) {
	string name, networth, country, source, age, rank, industry, ignore;
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

		//removes $ sign, 'B', and leading space
		networth = networth.substr(1, networth.length()-3);
		getline(inputFile, country, '\t');
		getline(inputFile, source, '\t');
		getline(inputFile, rank, '\t');
		getline(inputFile, age, '\t');

		//age in dataset is not available
		if (age == "N/A") continue;

		getline(inputFile, industry, '\n');

		access.appendData(name, networth, country, source, rank, age, industry);
	}
}

void prompt (ifstream& inputFile, LinkedList& access, Prompt& user_prompt){
	// assumes all inputs are valid for each column
	parseFile(inputFile, access);

	char option;

	do {
		cout << "Welcome to Forbes Billionaire 2021 Data Set.\n";
		cout << "Please select a task from the list below.\n";
		cout << "\n1 - View Entries\n";
		cout << "\n2 - Add Entries\n";
		cout << "\n3 - Delete Entries\n";
		cout << "\n4 - Search Entries\n";
		cout << "\n5 - Sort Entries\n";
		cout << "\n6 - Exit\n";

		cin >> option;
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
}
int main() {
	string input_file = "src/input1.txt";
	ifstream inputFile(input_file.c_str());

	LinkedList access;
	Prompt user_prompt;

	prompt(inputFile, access, user_prompt);
	
	return 0;
}
