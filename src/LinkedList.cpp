#include "LinkedList.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

LinkedList::LinkedList() {
	head = NULL;
	size = 0;
}


/*ADD FUNCTIONS*/


bool LinkedList::checkEmpty() {
	if (head == NULL) {
		cout << "\nThe database has currently no entries.\n\n";
		return true;
	}
	return false;
}

bool LinkedList::checkUnique(string name, string country, string source, string industry) {
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

node* LinkedList::assignData(string name, string networth, string country,
	string source, string rank, string age, string industry) {

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

void LinkedList::appendData(string name, string networth, string country,
	string source, string rank, string age, string industry) {

	node* current = head;
	bool check = checkUnique(name, country, source, industry);

	if (!check) {
		cout << "INVALID: DATA ALREADY EXISTS" << endl << endl;
		return;
	}
	node* data = assignData(name, networth, country, source, rank, age, industry);
	data->next = NULL;

	if (current == NULL) {
		head = data;
		size++;
	}
	else {
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = data;
		size++;
	}
}

void LinkedList::insertData(string name, string networth, string country,
	string source, string rank, string age, string industry, int position) {

	node* current = head;

	bool check = checkUnique(name, country, source, industry);
	if (!check) {
		cout << "INVALID: DATA ALREADY EXISTS" << endl << endl;
		return;
	}
	node* data = assignData(name, networth, country, source, rank, age, industry);

	if (position <= 0) {
		data->next = head;
		head = data;
		size++;
	}
	else if (position >= size) {
		appendData(name, networth, country, source, rank, age, industry);
	}
	else {
		for (int i = 0; i < position - 1; i++) {
			current = current->next;
		}
		data->next = current->next;
		current->next = data;
		size++;
	}
}


/*Checks the task and field to either do search or remove.*/
void LinkedList::getTask(string task, string field, string input_data) {
	if (task == "delete") {
		removeData(field, input_data); 
	}
	else {
		filterData(field, input_data); 
	}
}

/*Checks the field and returns the data from the linked list.*/

string LinkedList::getData(node* current, string field){
	if (field == "name") {
		return current->name;
	}
	else if (field == "country") {
		return current->country;
	}
	else if (field == "source") {
		return current->source;
	}
	else if (field ==  "industry"){
		return current->industry;
	}
	else if (field == "networth") {
		return current->networth; 
	}
	else if (field == "rank") {
		return current->ranking; 
	}
	else{
		return current->age; 
	}
}

/*Checks the field and performs case insensitivity match*/
bool LinkedList::checkStrings(node* current, string field, string input_data) {
	
	string s1 = getData(current, field);
	string s2 = input_data;

	transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
	transform(s2.begin(), s2.end(), s2.begin(), ::toupper);

	if (s1 == s2) {
		return true;
	}
	return false;
}

/*REMOVE FUNCTIONS*/


bool LinkedList::checkRemoveFlag(bool flag) {
	if (!flag) {
		cout << "Sorry, the data is non existent.\n\n";
		return false;
	}
	cout << "Entries are successfully deleted.\n\n";
	return true;
}

node* LinkedList::deleteFirstNode(node* temp) {
	temp = head;
	head = head->next;

	delete temp;
	size--;
	return head;
}

node* LinkedList::deletePositionNode(node* current) {
	node* temp = current->next;
	current->next = current->next->next;

	delete temp;
	size--;
	return current->next;
}

void LinkedList::deleteLastRemainingNode(node* current) {
	head = NULL;

	delete current;
	size--;
}


void LinkedList::removeData(string field, string input_data) {
	if (checkEmpty()) {
		return;
	}
	bool flag = false;
	node* current = head;

	
	while (current != NULL && current->next != NULL) {
		if (head == current && checkStrings(current, field, input_data)) {
			current = deleteFirstNode(head);
			flag = true;

			if (field == "name") {
				break;
			}
		}
		else if (checkStrings(current->next, field, input_data)) {
			deletePositionNode(current);
			flag = true;

			if (field == "name") {
				break;
			}
		}
		else {
			current = current->next;
		}
	}
	if (current != NULL && size == 1 && checkStrings(current, field, input_data)) {
		deleteLastRemainingNode(current);
		flag = true;
	}
		
	checkRemoveFlag(flag);
}


/*SEARCH FUNCTIONS*/


bool LinkedList::checkSearchFlag(bool flag, int counter) {
	if (!flag) {
		cout << "Sorry, but the data you are searching for does not exist.\n\n";
		return false;
	}
	cout << "The data you are searching for has " << counter << " entries.\n\n";
	return true;
}

bool LinkedList::filterData(string field, string input_data) {
	bool flag = false;
	int counter = 0;
	node* current = head;

	while (current != NULL) {					
		if (checkStrings(current, field, input_data)) {
			flag = true;
			counter++;
			text(current);

			if (field == "name") {
				break;
			}
		}
		current = current->next;
	}	
	return (checkSearchFlag(flag, counter));
}

void LinkedList::text(node* current) {
	cout << "Name:" << current->name << endl;
	cout << "Net Worth:$" << current->networth << " B Country:" << current->country << " Source:" << current->source <<
		" RANK:" << current->ranking << " Age:" << current->age << " Industry:" << current->industry << endl << endl;
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
		delete temp;
		size--;
	}
	head = NULL;
}