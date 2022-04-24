#include "LinkedList.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

LinkedList::LinkedList() {
	head = NULL;
	size = 0;
}


/*ADD FUNCTIONS*/


bool LinkedList::checkEmpty() {
	if (head == NULL) {
		std::cout << "\nThe database has currently no entries.\n\n";
		return true;
	}
	return false;
}

bool LinkedList::checkUnique(std::string name, std::string country, std::string source, std::string industry) {
	node* current = head;

	while (current != NULL) {

		if ((current->name == name) && (current->country == country) &&
			(current->source == source) && (current->industry == industry)) {

			return false;
		}
		current = current->next;
	}
	return true;
}

node* LinkedList::setData(std::string name, std::string networth, std::string country,
	std::string source, std::string rank, std::string age, std::string industry) {

	node* data = new node;

	data->name = name;

	data->networth = networth;

	data->country = country;

	data->source = source;

	data->ranking = rank;

	data->age = age;

	data->industry = industry;

	return data;
}

void LinkedList::appendData(std::string name, std::string networth, std::string country,
	std::string source, std::string rank, std::string age, std::string industry) {

	node* current = head;
	bool check = checkUnique(name, country, source, industry);

	if (!check) {
		std::cout << "INVALID: DATA ALREADY EXISTS\n\n";
		return;
	}
	
	node* data = setData(name, networth, country, source, rank, age, industry);
	data->next = NULL;

	if (current == NULL) {
		head = data;
		size++;
		return;
	}
	
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = data;
	size++;
}

void LinkedList::insertData(std::string name, std::string networth, std::string country,
	std::string source, std::string rank, std::string age, std::string industry, int position) {

	node* current = head;

	bool check = checkUnique(name, country, source, industry);
	if (!check) {
		std::cout << "INVALID: DATA ALREADY EXISTS\n\n";
		return;
	}
	node* data = setData(name, networth, country, source, rank, age, industry);

	if (position <= 0) {
		data->next = head;
		head = data;
		size++;
		return;
	}
	
	if (position >= size) {
		return appendData(name, networth, country, source, rank, age, industry);
	}
	
	for (int i = 0; i < position - 1; i++) {
		current = current->next;
	}
	data->next = current->next;
	current->next = data;
	size++;
}

/*Checks the field and returns the data from the linked list.*/

std::string LinkedList::getData(node* current, std::string field){
	if (field == "name") {return current->name;}

	if (field == "country") {return current->country;}

	if (field == "source") {return current->source;}

	if (field ==  "industry") {return current->industry;}

	if (field == "networth") {return current->networth;}

	if (field == "rank") {return current->ranking;}
	
	if (field == "age") {return current->age;}
}

/*Checks the field and performs case insensitivity match*/
bool LinkedList::checkStrings(node* current, std::string field, std::string input_data) {
	
	std::string s1 = getData(current, field);
	std::string s2 = input_data;

	transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
	transform(s2.begin(), s2.end(), s2.begin(), ::toupper);

	if (s1 == s2) {
		return true;
	}
	return false;
}

/*REMOVE FUNCTIONS*/


void LinkedList::checkFlag(bool flag) {
	if (!flag){ std::cout << "Sorry, the data is non existent.\n\n"; }

	else{ std::cout << "Entries are successfully deleted.\n\n"; }
}

node* LinkedList::deleteFirstNode(node* temp) {
	temp = head;
	head = head->next;
	
	size--;
	delete temp;
	return head;
}

node* LinkedList::deletePositionNode(node* current) {
	node* temp = current->next;
	current->next = current->next->next;
	
	size--;
	delete temp;
	return current->next;
}

void LinkedList::deleteLastRemainingNode(node* current) {
	head = NULL;

	size--;
	delete current;
}

void LinkedList::removeData(std::string field, std::string input_data) {
	if (checkEmpty()) { return; }

	bool flag = false;
	node* current = head;

	while (current != NULL && current->next != NULL) {
		if (head == current && checkStrings(current, field, input_data)) {
			current = deleteFirstNode(head);
			flag = true;
		}
		else if (checkStrings(current->next, field, input_data)) {
			deletePositionNode(current);
			flag = true;
		}
		else {
			current = current->next;
		}

		if (field == "name" && flag) { break; }
		
	}
	if (current != NULL && size == 1 && checkStrings(current, field, input_data)) {
		deleteLastRemainingNode(current);
		flag = true;
	}
		
	checkFlag(flag);
}


/*SEARCH FUNCTIONS*/


void LinkedList::checkFlag(bool flag, int counter) {
	if (!flag) {std::cout << "Sorry, but the data you are searching for does not exist.\n\n"; }

	else { std::cout << "The data you are searching for have " << counter << " entries.\n\n"; }
}

void LinkedList::filterData(std::string field, std::string input_data) {
	bool flag = false;
	int counter = 0;
	node* current = head;

	while (current != NULL) {					
		if (checkStrings(current, field, input_data)) {
			flag = true;
			counter++;
			text(current);

			if (field == "name") { break; }
		}
		current = current->next;
	}	
	checkFlag(flag, counter);
}

void LinkedList::text(node* current) {
	std::cout << "Name:" << current->name << '\n';
	std::cout << "Net Worth:$" << current->networth << " B Country:" << current->country << " Source:" << current->source <<
		" RANK:" << current->ranking << " Age:" << current->age << " Industry:" << current->industry << "\n\n";
}

void LinkedList::swap_nodes(node* current) {
	swap(current->name, current->next->name);

	swap(current->networth, current->next->networth);

	swap(current->country, current->next->country);

	swap(current->source, current->next->source);

	swap(current->ranking, current->next->ranking);

	swap(current->age, current->next->age);

	swap(current->industry, current->next->industry);
}

void LinkedList::sort(std::string field, char option) {
	//option a == increasing
	//option b == decreasing
	
	for (int i = 0; i < size - 1; i++) {
		node* current = head;

		for (int j = 0; j < size - 1 - i; j++) {
			double num1 = stod(getData(current, field));
			double num2 = stod(getData(current->next, field));

			if (option == 'a' && num1 > num2) {
				swap_nodes(current);
			}
			else if (option == 'b' && (num1 < num2)){
				swap_nodes(current);
			}
			current = current->next;
		}
	}
}

void LinkedList::print() {
	if (checkEmpty()) {
		return;
	}
	node* current = head;

	while (current != NULL) {
		text(current);
		current = current->next;
	}
}

LinkedList::~LinkedList() {
	node* current = head;

	while (current != NULL) {
		node* temp = current;
		current = current->next;
		size--;
		delete temp;
	}
	head = NULL;
}