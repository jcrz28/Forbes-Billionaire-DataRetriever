#pragma once
#ifndef USERPROMPT
#define USERPROMPT

#include "LinkedList_Database.h"
#include <iostream>

using namespace std;

class prompt {
public:

	/*Shows the fields of the database*/
	void all_fields();

	void num_fields();

	/*I converted char options to a string field category as I presumed
	it would be easier to read and understand the code.*/

	string char_option_to_str_field(char option);

	/*Options for numerical fields only*/
	string char_option_to_str_field_2(char option); 


	void get_input_data(Database& access, string task, char option);
	
	/*Perform search range or trim function*/
	void perform_range_task(Database& access, string task, string field, int num1, int num2);

	bool get_interval(Database& access, string task, char option, int& num1, int& num2);

	void choose_order(Database& access, char option);

	void invalid_input_message();


	/*Main user options*/


	void print_entries(Database& access);

	void add_entries(Database& access);

	void delete_entries(Database& access);

	void search_entries(Database& access);

	void search_range(Database& access);

	void sort_entries(Database& access);

	void trim_entries(Database& access);

	void exit_message();

};
#endif // !USERPROMPT
