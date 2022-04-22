#pragma once
#ifndef LINKEDLIST_IMPLEMENTATIONS
#define LINKEDLIST_IMPLEMENTATIONS

#include <iostream>
using namespace std;

struct node {
	string name{}, country{}, source{}, industry{}, ranking{}, age{}, networth{};
	node* next{};
};

class LinkedList{
protected:
	int size;
	node* head;

public:
	friend class Prompt;
	// friend void perform_sorting(LinkedList& access, string field, char option);

	LinkedList();

	/*ADD FUNCTIONS*/


	bool checkEmpty();

	bool checkUnique(string name, string country, string source, string industry);

	node* assignData(string name, string networth, string country,
		string source, string rank, string age, string industry);

	void appendData(string name, string networth, string country,
		string source, string rank, string age, string industry);

	void insertData(string name, string networth, string country,
		string source, string rank, string age, string industry, int position);


	/*UTULITY FUNCTIONS*/


	/*Checks the task and field to either do search or remove.*/
	void getTask(string task, string field, string num);

	/*Checks the field and returns the data from the linked list.*/
	string getData (node* current, string field);

	/* Check if strings are equal.*/
	bool checkStrings(node* current, string field, string input_data);


	/*REMOVE FUNCTIONS*/


	bool checkRemoveFlag(bool flag);

	node* deleteFirstNode(node* temp);

	node* deletePositionNode(node* current);

	void deleteLastRemainingNode(node* current);

	void removeData(string field, string data);	


	/*SEARCH FUNCTIONS*/

	bool checkSearchFlag(bool flag, int counter);

	bool filterData(string field, string data);	


	/*SORT FUNCTIONS*/

	void swap_nodes(node* current);

	void sort(string field, char task);
	

	/*PRINT FUNCTIONS*/

	void text(node* current);

	void print();
		
	~LinkedList();

};
#endif
