#pragma once
#ifndef USERPROMPT
#define USERPROMPT

#include "../LinkedList/LinkedList.h"
#include <iostream>

class Prompt {
public:

	/*Shows the fields of the database*/
	void all_fields();

	void num_fields();

	/*Char options to a string field category.*/

	std::string char_option_to_str_field(char option);

	/*Options for numerical fields only*/
	std::string char_option_to_str_field_2(char option); 


	void get_input_data(LinkedList& access, std::string task, char option);
	
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
