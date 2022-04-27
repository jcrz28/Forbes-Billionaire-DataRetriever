#pragma once
#ifndef LINKEDLIST_IMPLEMENTATIONS
#define LINKEDLIST_IMPLEMENTATIONS

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

struct node {
	std::string name, country, source, ranking, industry, age, networth;
	node* next;
};

class LinkedList{
protected:
	int size;
	node* head;

public:

	LinkedList();

	/*ADD FUNCTIONS*/


	bool checkEmpty();

	bool checkUnique(std::string name, std::string country, std::string source, std::string industry);

	node* setData(std::string name, std::string networth, std::string country,
		std::string source, std::string rank, std::string age, std::string industry);

	void insertData(std::string name, std::string networth, std::string country,
		std::string source, std::string rank, std::string age, std::string industry, int position);


	/*UTULITY FUNCTIONS*/

	/*Checks the field and returns the data from the linked list.*/
	std::string getData (node* current, std::string field);

	/* Check if strings are equal.*/
	bool checkStrings(node* current, std::string field, std::string input_data);

	void checkFlag(bool flag, int counter);

	void checkFlag(bool flag);

	/*DELETE FUNCTIONS*/

	void deleteData(std::string field, std::string data);	


	/*SEARCH FUNCTIONS*/

	void filterData(std::string field, std::string data);	


	/*SORT FUNCTIONS*/

	void swap_nodes(node* current);

	void sort(std::string field, char task);
	

	/*PRINT FUNCTIONS*/

	void text(node* current);

	void print();
		
	~LinkedList();
};

#endif
