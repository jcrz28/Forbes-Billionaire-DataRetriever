#include "LinkedList_Database.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

Database::Database() {
	head = NULL;
	size = 0;
}


/*ADD FUNCTIONS*/


bool Database::check_empty() {
	if (head == NULL) {
		cout << "\nThe database has currently no entries.\n\n";
		return true;
	}
	return false;
}

bool Database::check_uniqueness(string NAME, string COUNTRY, string SOURCE, string INDUSTRY) {
	node* current = head;

	while (current != NULL) {

		if ((current->name == NAME) && (current->country == COUNTRY) &&
			(current->source == SOURCE) && (current->industry == INDUSTRY)) {

			return false;
		}
		current = current->next;
	}
	return true;
}

node* Database::create_data(string NAME, double NETWORTH, string COUNTRY,
	string SOURCE, int RANK, int AGE, string INDUSTRY) {

	node* data = new node;

	data->name = NAME;

	data->net_worth = NETWORTH;

	data->country = COUNTRY;

	data->source = SOURCE;

	data->ranking = RANK;

	data->age = AGE;

	data->industry = INDUSTRY;

	return data;
}

void Database::append_data(string NAME, double NETWORTH, string COUNTRY,
	string SOURCE, int RANK, int AGE, string INDUSTRY) {

	node* current = head;
	bool check = check_uniqueness(NAME, COUNTRY, SOURCE, INDUSTRY);

	if (check == false) {
		cout << "INVALID: DATA ALREADY EXISTS" << endl << endl;
		return;
	}
	node* data = create_data(NAME, NETWORTH, COUNTRY, SOURCE, RANK, AGE, INDUSTRY);
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

void Database::insertNewData(string NAME, double NETWORTH, string COUNTRY,
	string SOURCE, int RANK, int AGE, string INDUSTRY, int POSITION) {

	node* current = head;

	bool check = check_uniqueness(NAME, COUNTRY, SOURCE, INDUSTRY);
	if (check == false) {
		cout << "INVALID: DATA ALREADY EXISTS" << endl << endl;
		return;
	}
	node* data = create_data(NAME, NETWORTH, COUNTRY, SOURCE, RANK, AGE, INDUSTRY);

	if (POSITION <= 0) {
		data->next = head;
		head = data;
		size++;
	}
	else if (POSITION >= size) {
		append_data(NAME, NETWORTH, COUNTRY, SOURCE, RANK, AGE, INDUSTRY);
	}
	else {
		for (int i = 0; i < POSITION - 1; i++) {
			current = current->next;
		}
		data->next = current->next;
		current->next = data;
		size++;
	}
}


/*UTULITY FUNCTIONS*/


/*Checks the task and field to either do search or remove.*/
void Database::string_task(string task, string field, string data) {
	if (task == "delete") {
		if (field == "name") 
			remove_word(field, data); 

		else if (field == "country") 
			remove_word(field, data); 

		else if (field == "source")  
			remove_word(field, data); 

		else if (field == "industry")  
			remove_word(field, data); 

	}
	else if (task == "search") {
		if (field == "name")  
			filter_word(field, data); 

		else if (field == "country")  
			filter_word(field, data); 

		else if (field == "source")  
			filter_word(field, data); 

		else if (field == "industry")  
			filter_word(field, data); 
	}
}

void Database::num_task(string task, string field, double num) {
	if (task == "delete") {
		if (field == "networth")  
			remove_num(field, num); 

		else if (field == "rank")  
			remove_num(field, num); 

		else if (field == "age")  
			remove_num(field, num); 
	}

	else if (task == "search") {
		if (field == "networth")  
			filter_num(field, num); 

		else if (field == "rank")  
			filter_num(field, num); 

		else if (field == "age") 
			filter_num(field, num); 
	}
}


/*Checks the field and returns the current value from the linked list.*/
double Database::get_val(node* current, string field) {
	if (field == "networth") 
		return current->net_worth; 

	else if (field == "rank")  
		return current->ranking; 

	else if (field == "age")  
		return current->age; 

	else return 0;
}


/*Transform both strings to upper cases and checks if they are equal.*/
bool Database::check_strings(string s1, string s2) {
	string temp = s1;

	transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
	transform(s2.begin(), s2.end(), s2.begin(), ::toupper);

	if (temp == s2)
		return true;
	return false;
}

/*Checks the field and performs case insensitivity match*/
bool Database::check_case_insensitivity(node* current, string field, string data) {
	if (field == "name") {
		if (check_strings(current->name, data)) {
			return true;
		}
	}
	else if (field == "country") {
		if (check_strings(current->country, data)) {
			return true;
		}
	}
	else if (field == "source") {
		if (check_strings(current->source, data)) {
			return true;
		}
	}
	else if (field == "industry") {
		if (check_strings(current->industry, data)) {
			return true;
		}
	}
	return false;
}


/*REMOVE FUNCTIONS*/


bool Database::check_remove_flag(bool flag) {
	if (flag == false) {
		cout << "Sorry, the data is non existent.\n\n";
		return false;
	}
	cout << "Entries are successfully deleted.\n\n";
	return true;
}

node* Database::delete_beginning(node* temp) {
	temp = head;
	head = head->next;

	delete temp;
	size--;
	return head;
}

node* Database::delete_positional_elements(node* current) {
	node* temp = current->next;
	current->next = current->next->next;

	delete temp;
	size--;
	return current->next;
}

void Database::delete_last_and_remaining_element(node* current) {
	head = NULL;

	delete current;
	size--;
}

node* Database::remove_all(node* temp) {
	while (temp != NULL) {
		head = head->next;
		delete temp;
		temp = head;
		size--;
	}
	head = NULL;
	return head;
}

void Database::remove_word(string field, string data) {
	if (check_empty()) {
		return;
	}
	bool flag = false;
	node* current = head;

	if (field == "name") {
		while (current != NULL && current->next != NULL) {
			if (head == current && check_case_insensitivity(current, field, data)) {
				current = delete_beginning(head);
				flag = true;
				break;
			}
			else if (check_case_insensitivity(current->next, field, data)) {
				delete_positional_elements(current);
				flag = true;
				break;
			}
			else {
				current = current->next;
			}
		}
		if (current != NULL && size == 1 && check_case_insensitivity(current, field, data)) {
			delete_last_and_remaining_element(current);
			flag = true;
		}
	}
	else {
		while (current != NULL && current->next != NULL) {
			if (head == current && check_case_insensitivity(current, field, data)) {
				current = delete_beginning(head);
				flag = true;
			}
			else if (check_case_insensitivity(current->next, field, data)) {
				delete_positional_elements(current);
				flag = true;
			}
			else {
				current = current->next;
			}
		}
		if (current != NULL && size == 1 && check_case_insensitivity(current, field, data)) {
			delete_last_and_remaining_element(current);
			flag = true;
		}
	}
	check_remove_flag(flag);
}

void Database::remove_num(string field, double num) {
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

void Database::trim(int num1, int  num2) {
	if (check_empty()) {
		return;
	}
	if (num1 <= 0 && num2 >= size) {
		remove_all(head);
		cout << "\nAll data entries are deleted.\n\n";
		return;
	}
	node* current = head;
	int counter = 0;

	while (current != NULL && current->next != NULL && counter != num2) {
		if (num1 == 0) {
			current = delete_beginning(head);
		}
		else if (num2 > counter + 1 && counter + 1 >= num1) {
			delete_positional_elements(current);
		}
		else {
			current = current->next;
		}
		counter++;
	}
	if (size == 1 && counter == num2) {
		delete_last_and_remaining_element(current);
	}
	cout << "\n--------------------------------------------SUCCESSFULLY TRIMMED THE DATA-----------------------------------------------\n\n";
}


/*SEARCH FUNCTIONS*/


bool Database::check_search_flag(bool flag, int counter) {
	if (flag == false) {
		cout << "Sorry, but the data you are searching for does not exist.\n\n";
		return false;
	}
	cout << "The data you are searching for has " << counter << " entries.\n\n";
	return true;
}

void Database::update(node* current, bool& flag, int& counter) {
	text(current);
	flag = true;
	counter++;
}

bool Database::filter_word(string field, string data) {
	bool flag = false;
	int counter = 0;
	node* current = head;

	if (field == "name") {
		while (current != NULL) {
			if (check_case_insensitivity(current, field, data)) {
				update(current, flag, counter);
				break;
			}
			current = current->next;
		}
	}
	else {
		while (current != NULL) {					
			if (check_case_insensitivity(current, field, data)) {
				update(current, flag, counter);
			}
			current = current->next;
		}
		
	}
	return (check_search_flag(flag, counter));
}

bool Database::filter_num(string field, double num) {
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

bool Database::filter_range(string field, double num1, double num2) {
	bool flag = false;
	int counter = 0;
	node* current = head;

	while (current != NULL) {
		if (num1 <= get_val(current, field) && get_val(current, field) <= num2) {
			update(current, flag, counter);
		}
		current = current->next;
	}
	return (check_search_flag(flag, counter));

}


/*PRINT FUNCTIONS*/


void Database::text(node* current) {
	cout << "Name:" << current->name << endl;

	cout << "Net Worth:$" << current->net_worth << " B Country:" << current->country << " Source:" << current->source <<
		" RANK:" << current->ranking << " Age:" << current->age << " Industry:" << current->industry << endl << endl;
}

void Database::print() {
	if (check_empty()) {
		return;
	}
	node* current = head;

	while (current != NULL) {
		text(current);
		current = current->next;
	}
}

Database::~Database() {
	node* current = head;

	while (current != NULL) {
		node* temp = current;
		current = current->next;
		delete temp;
		size--;
	}
	head = NULL;
}