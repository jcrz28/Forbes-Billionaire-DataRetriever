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

class LinkedList{
protected:
	int size;
	node* head;

public:
	friend class Prompt;
	friend void perform_sorting(LinkedList& access, string field, char option);

	LinkedList();

	/*ADD FUNCTIONS*/


	bool check_empty();

	bool check_uniqueness(string name, string country, string source, string industry);

	node* create_data(string name, double NETWORTH, string country,
		string source, int rank, int age, string industry);

	void append_data(string name, double NETWORTH, string country,
		string source, int rank, int age, string industry);

	void insertNewData(string name, double NETWORTH, string country,
		string source, int rank, int age, string industry, int position);


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


	/*SEARCH FUNCTIONS*/


	bool check_search_flag(bool flag, int counter);

	void update(node* current, bool& flag, int& counter);

	bool filter_word(string field, string data);	

	bool filter_num(string field, double num);	


	/*PRINT FUNCTIONS*/

	void text(node* current);

	void print();
		
	~LinkedList();

};
#endif
