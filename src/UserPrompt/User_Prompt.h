#pragma once
#ifndef USERPROMPT
#define USERPROMPT

#include "../LinkedList/LinkedList.h"
#include <string>
#include <iostream>
#include <fstream>

class Prompt: public LinkedList {
public:

	
	/*Shows the fields of the database*/
	void all_fields();

	void num_fields();

	/*Char options to a string field category.*/

	std::string char_option_to_str_field(char option);

	/*Options for numerical fields only*/
	std::string char_option_to_str_field_2(char option); 


	void get_input_data(std::string task, char option);
	
	bool validOptions(char option);

	void invalid_input_message();
	

	void load_entries(std::ifstream& inputFile);

	/*Main user options*/
	
	void print_entries();

	void add_entries();

	void delete_entries();

	void search_entries();

	void sort_entries();

	void exit_message();

};
#endif // !USERPROMPT
