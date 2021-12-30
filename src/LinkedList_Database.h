#pragma once
#ifndef LINKEDLIST_IMPLEMENTATIONS
#define LINKEDLIST_IMPLEMENTATIONS

#include <iostream>
using namespace std;

struct node {
	string name{}, country{}, source{}, industry{};
	int ranking{}, age{};
	double net_worth{};
	node* next{};
};

class Database{
protected:
	int size;
	node* head;

public:
	friend class prompt;
	friend void perform_sorting(Database& access, string field, char option);

	Database();

	/*ADD FUNCTIONS*/


	bool check_empty();

	bool check_uniqueness(string NAME, string COUNTRY, string SOURCE, string INDUSTRY);

	node* create_data(string NAME, double NETWORTH, string COUNTRY,
		string SOURCE, int RANK, int AGE, string INDUSTRY);

	void append_data(string NAME, double NETWORTH, string COUNTRY,
		string SOURCE, int RANK, int AGE, string INDUSTRY);

	void insertNewData(string NAME, double NETWORTH, string COUNTRY,
		string SOURCE, int RANK, int AGE, string INDUSTRY, int POSITION);


	/*UTULITY FUNCTIONS*/


	/*Checks the task and field to either do search or remove.*/
	void string_task(string task, string field, string data);
	void num_task(string task, string field, double num);


	/*Checks the field and returns the current value from the linked list.*/
	double get_val(node* current, string field);	


	/*Transform both strings to upper cases and checks if they are equal.*/
	bool check_strings(string s1, string s2);

	/*Checks the field and performs case insensitivity match.*/
	bool check_case_insensitivity(node* current, string field, string data);


	/*REMOVE FUNCTIONS*/


	bool check_remove_flag(bool flag);

	node* delete_beginning(node* temp);

	node* delete_positional_elements(node* current);

	void delete_last_and_remaining_element(node* current);

	node* remove_all(node* temp);

	void remove_word(string field, string data);	

	void remove_num(string field, double num);	

	void trim(int pos1, int pos2);


	/*SEARCH FUNCTIONS*/


	bool check_search_flag(bool flag, int counter);

	void update(node* current, bool& flag, int& counter);

	bool filter_word(string field, string data);	

	bool filter_num(string field, double num);	

	bool filter_range(string field, double num1, double num2);


	/*PRINT FUNCTIONS*/

	void text(node* CURRENT);

	void print();
		
	~Database();

};
#endif
