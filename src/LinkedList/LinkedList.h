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

	bool checkEmpty();
	bool checkUnique(std::string name, std::string country, std::string source, std::string industry);
	node* setData(std::string name, std::string networth, std::string country,
		std::string source, std::string rank, std::string age, std::string industry);
	void insertData(std::string name, std::string networth, std::string country,
		std::string source, std::string rank, std::string age, std::string industry, int position);


	std::string getData (node* current, std::string field);
	bool checkStrings(node* current, std::string field, std::string input_data);
	void checkFlag(bool flag, int counter);
	void checkFlag(bool flag);

	void deleteData(std::string field, std::string data);	

	void filterData(std::string field, std::string data);	

	void bubbleSort(std::string field, char task);
	void checkNeighbor(node* current, double curr, double next, char option);
	void checkNeighbor(node* current, std::string curr, std::string next, char option);
	void swapNodes(node* current);

	void text(node* current);
	void print();
		
	~LinkedList();
};

#endif
