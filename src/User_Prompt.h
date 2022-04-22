#pragma once
#ifndef USERPROMPT
#define USERPROMPT

#include "LinkedList.h"
#include <iostream>

using namespace std;

class Prompt {
public:

	/*Shows the fields of the database*/
	void all_fields();

	void num_fields();

	/*Char options to a string field category.*/

	string char_option_to_str_field(char option);

	/*Options for numerical fields only*/
	string char_option_to_str_field_2(char option); 


	void get_input_data(LinkedList& access, string task, char option);
	
	void choose_order(LinkedList& access, char option);

	void invalid_input_message();


	/*Main user options*/


	void print_entries(LinkedList& access);

	void add_entries(LinkedList& access);

	void delete_entries(LinkedList& access);

	void search_entries(LinkedList& access);

	void sort_entries(LinkedList& access);

	void exit_message();

};
#endif // !USERPROMPT
