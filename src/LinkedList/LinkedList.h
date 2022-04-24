#pragma once
#ifndef LINKEDLIST_IMPLEMENTATIONS
#define LINKEDLIST_IMPLEMENTATIONS

#include <iostream>

struct node {
	std::string name, country, source, ranking, industry, age, networth;
	node* next;
};

class LinkedList{
protected:
	int size;
	node* head;

public:
	friend class Prompt;

	LinkedList();

	/*ADD FUNCTIONS*/


	bool checkEmpty();

	bool checkUnique(std::string name, std::string country, std::string source, std::string industry);

	node* setData(std::string name, std::string networth, std::string country,
		std::string source, std::string rank, std::string age, std::string industry);

	void appendData(std::string name, std::string networth, std::string country,
		std::string source, std::string rank, std::string age, std::string industry);

	void insertData(std::string name, std::string networth, std::string country,
		std::string source, std::string rank, std::string age, std::string industry, int position);


	/*UTULITY FUNCTIONS*/


	/*Checks the task and field to either do search or remove.*/
	void getTask(std::string task, std::string field, std::string num);

	/*Checks the field and returns the data from the linked list.*/
	std::string getData (node* current, std::string field);

	/* Check if strings are equal.*/
	bool checkStrings(node* current, std::string field, std::string input_data);


	/*REMOVE FUNCTIONS*/


	bool checkRemoveFlag(bool flag);

	node* deleteFirstNode(node* temp);

	node* deletePositionNode(node* current);

	void deleteLastRemainingNode(node* current);

	void removeData(std::string field, std::string data);	


	/*SEARCH FUNCTIONS*/

	bool checkSearchFlag(bool flag, int counter);

	bool filterData(std::string field, std::string data);	


	/*SORT FUNCTIONS*/

	void swap_nodes(node* current);

	void sort(std::string field, char task);
	

	/*PRINT FUNCTIONS*/

	void text(node* current);

	void print();
		
	~LinkedList();

};
#endif
