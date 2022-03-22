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


	bool checkEmpty();

	bool checkUnique(string name, string country, string source, string industry);

	node* assignData(string name, double NETWORTH, string country,
		string source, int rank, int age, string industry);

	void appendData(string name, double NETWORTH, string country,
		string source, int rank, int age, string industry);

	void insertData(string name, double NETWORTH, string country,
		string source, int rank, int age, string industry, int position);


	/*UTULITY FUNCTIONS*/


	/*Checks the task and field to either do search or remove.*/
	void string_task(string task, string field, string data);
	void num_task(string task, string field, double num);


	/*Checks the field and returns the data from the linked list.*/
	double getVal(node* current, string field);	
	string getString(node* current, string field);

	/* Check if strings are equal.*/
	bool checkStrings(node* current, string field, string input_data);


	/*REMOVE FUNCTIONS*/


	bool check_remove_flag(bool flag);

	node* deleteFirstNode(node* temp);

	node* deletePositionNode(node* current);

	void deleteLastRemainingNode(node* current);

	void remove_word(string field, string data);	

	void remove_num(string field, double num);	


	/*SEARCH FUNCTIONS*/


	bool check_search_flag(bool flag, int counter);

	bool filter_word(string field, string data);	

	bool filter_num(string field, double num);	


	/*PRINT FUNCTIONS*/

	void text(node* current);

	void print();
		
	~LinkedList();

};
#endif
