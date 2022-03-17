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


bool LinkedList::check_empty() {
	if (head == NULL) {
		cout << "\nThe database has currently no entries.\n\n";
		return true;
	}
	return false;
}

bool LinkedList::check_uniqueness(string name, string country, string source, string industry) {
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

node* LinkedList::create_data(string name, double networth, string country,
	string source, int rank, int age, string industry) {

	node* data = new node;

	data->name = name;

	data->net_worth = networth;

	data->country = country;

	data->source = source;

	data->ranking = rank;

	data->age = age;

	data->industry = industry;

	return data;
}

void LinkedList::append_data(string name, double networth, string country,
	string source, int rank, int age, string industry) {

	node* current = head;
	bool check = check_uniqueness(name, country, source, industry);

	if (check == false) {
		cout << "INVALID: DATA ALREADY EXISTS" << endl << endl;
		return;
	}
	node* data = create_data(name, networth, country, source, rank, age, industry);
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

void LinkedList::insertNewData(string name, double networth, string country,
	string source, int rank, int age, string industry, int position) {

	node* current = head;

	bool check = check_uniqueness(name, country, source, industry);
	if (check == false) {
		cout << "INVALID: DATA ALREADY EXISTS" << endl << endl;
		return;
	}
	node* data = create_data(name, networth, country, source, rank, age, industry);

	if (position <= 0) {
		data->next = head;
		head = data;
		size++;
	}
	else if (position >= size) {
		append_data(name, networth, country, source, rank, age, industry);
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


/*UTULITY FUNCTIONS*/


/*Checks the task and field to either do search or remove.*/
void LinkedList::string_task(string task, string field, string input_data) {
	if (task == "delete") {
		remove_word(field, input_data); 
	}
	else if (task == "search") {
		filter_word(field, input_data); 
	}
}

void LinkedList::num_task(string task, string field, double num) {
	if (task == "delete") {
		remove_num(field, num);
	}
	else if (task == "search") {
		filter_num(field, num); 
	}
}


/*Checks the field and returns the current value from the linked list.*/
double LinkedList::get_val(node* current, string field) {
	if (field == "networth") {
		return current->net_worth; 
	}
	else if (field == "rank") {
		return current->ranking; 
	}
	else if (field == "age"){ 
		return current->age; 
	}
	else return 0;
}


/*Transform both strings to upper cases and checks if they are equal.*/
bool LinkedList::check_strings(string s1, string s2) {
	transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
	transform(s2.begin(), s2.end(), s2.begin(), ::toupper);

	if (s1 == s2) {
		return true;
	}
	return false;
}

/*Checks the field and performs case insensitivity match*/
bool LinkedList::check_case_insensitivity(node* current, string field, string input_data) {
	if (field == "name") {
		if (check_strings(current->name, input_data)) {
			return true;
		}
	}
	else if (field == "country") {
		if (check_strings(current->country, input_data)) {
			return true;
		}
	}
	else if (field == "source") {
		if (check_strings(current->source, input_data)) {
			return true;
		}	
	}
	else if (field == "industry") {
		if (check_strings(current->industry, input_data)) {
			return true;
		}
	}
	return false;
}


/*REMOVE FUNCTIONS*/


bool LinkedList::check_remove_flag(bool flag) {
	if (flag == false) {
		cout << "Sorry, the data is non existent.\n\n";
		return false;
	}
	cout << "Entries are successfully deleted.\n\n";
	return true;
}

node* LinkedList::delete_beginning(node* temp) {
	temp = head;
	head = head->next;

	delete temp;
	size--;
	return head;
}

node* LinkedList::delete_positional_elements(node* current) {
	node* temp = current->next;
	current->next = current->next->next;

	delete temp;
	size--;
	return current->next;
}

void LinkedList::delete_last_and_remaining_element(node* current) {
	head = NULL;

	delete current;
	size--;
}


void LinkedList::remove_word(string field, string input_data) {
	if (check_empty()) {
		return;
	}
	bool flag = false;
	node* current = head;

	
	while (current != NULL && current->next != NULL) {
		if (head == current && check_case_insensitivity(current, field, input_data)) {
			current = delete_beginning(head);
			flag = true;

			if (field == "name") {
				break;
			}
		}
		else if (check_case_insensitivity(current->next, field, input_data)) {
			delete_positional_elements(current);
			flag = true;

			if (field == "name") {
				break;
			}
		}
		else {
			current = current->next;
		}
	}
	if (current != NULL && size == 1 && check_case_insensitivity(current, field, input_data)) {
		delete_last_and_remaining_element(current);
		flag = true;
	}
		
	check_remove_flag(flag);
}

void LinkedList::remove_num(string field, double num) {
	if (check_empty()) {
		return;
	}
	bool flag = false;
	node* current = head;

	while (current != NULL && current->next != NULL) {
		if (head == current && get_val(current, field) == num) {
			current = delete_beginning(head);
			flag = true;
		}
		else if (get_val(current->next, field) == num) {
			delete_positional_elements(current);
			flag = true;
		}
		else {
			current = current->next;
		}
	}
	if (current != NULL && size == 1 && get_val(current, field) == num) {
		delete_last_and_remaining_element(current);
		flag = true;
	}
	
	check_remove_flag(flag);
}


/*SEARCH FUNCTIONS*/


bool LinkedList::check_search_flag(bool flag, int counter) {
	if (flag == false) {
		cout << "Sorry, but the data you are searching for does not exist.\n\n";
		return false;
	}
	cout << "The data you are searching for has " << counter << " entries.\n\n";
	return true;
}

void LinkedList::update(node* current, bool& flag, int& counter) {
	text(current);
	flag = true;
	counter++;
}

bool LinkedList::filter_word(string field, string input_data) {
	bool flag = false;
	int counter = 0;
	node* current = head;

	while (current != NULL) {					
		if (check_case_insensitivity(current, field, input_data)) {
			update(current, flag, counter);

			if (field == "name") {
				break;
			}
		}
		current = current->next;
	}	
	
	return (check_search_flag(flag, counter));
}

bool LinkedList::filter_num(string field, double num) {
	bool flag = false;
	int counter = 0;
	node* current = head;

	while (current != NULL) {
		if (get_val(current, field) == num) {
			update(current, flag, counter);
		}
		current = current->next;
	}
	return (check_search_flag(flag, counter));
}


/*PRINT FUNCTIONS*/


void LinkedList::text(node* current) {
	cout << "Name:" << current->name << endl;

	cout << "Net Worth:$" << current->net_worth << " B Country:" << current->country << " Source:" << current->source <<
		" RANK:" << current->ranking << " Age:" << current->age << " Industry:" << current->industry << endl << endl;
}

void LinkedList::print() {
	if (check_empty()) {
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