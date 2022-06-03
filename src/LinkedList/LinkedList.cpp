#include "LinkedList.h"

LinkedList::LinkedList() {
	head = NULL;
	size = 0;
}

bool LinkedList::checkEmpty() {
	if (head == NULL) {
		std::cout << "\nThe database has currently no entries.\n\n";
		return true;
	}return false;
}

bool LinkedList::checkUnique(std::string name, std::string country, std::string source, std::string industry) {
	node* current = head;
	while (current != NULL) {

		if ((current->name == name) && (current->country == country) &&
			(current->source == source) && (current->industry == industry)) {
			std::cout << "INVALID: DATA ALREADY EXISTS\n\n";
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

void LinkedList::insertData(std::string name, std::string networth, std::string country,
	std::string source, std::string rank, std::string age, std::string industry, int position) {

	if (!checkUnique(name, country, source, industry)){ return; }
	
	node* current = head;
	node* data = setData(name, networth, country, source, rank, age, industry);

	if (current == NULL) {
		data->next = NULL;
		head = data;
		size++;
		return;
	}

	if (position < 0) {
		data->next = head;
		head = data;
		size++;
		return;
	}
	
	if (position >= size) {
		data->next = NULL;

		while (current->next != NULL) {
			current = current->next;
		}
		current->next = data;
		size++;
		return;
	}
	
	for (int i = 0; i < position - 1; i++) {
		current = current->next;
	}
	data->next = current->next;
	current->next = data;
	size++;
	return;
}

/*Checks the field and returns the data from the linked list.*/

std::string LinkedList::getData(node* current, std::string field){
	if (field == "name")
		return current->name;
	else if (field == "country")
		return current->country;
	else if (field == "source")
		return current->source;
	else if (field ==  "industry")
		return current->industry;
	else if (field == "networth")
		return current->networth;
	else if (field == "rank")
		return current->ranking;
	else if (field == "age")
		return current->age;
}

/*Checks the field and performs case insensitivity match*/
bool LinkedList::checkStrings(node* current, std::string field, std::string input_data) {
	std::string s1 = getData(current, field);
	std::string s2 = input_data;

	transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
	transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
	
	return s1 == s2;
}

void LinkedList::checkFlag(bool flag) {
	!flag ? std::cout << "Sorry, the data is non existent.\n\n": 
			std::cout << "Entries are successfully deleted.\n\n";
}

void LinkedList::deleteData(std::string field, std::string input_data) {
	if (checkEmpty()) { return; }

	bool flag = false;
	node* current = head;

	while (current->next != NULL) {
		if (checkStrings(current, field, input_data)){
			current = head = head->next;
			size--;
			flag = true;
		}else if (checkStrings(current->next, field, input_data)){
			current->next = current->next->next;
			size--;
			flag = true;
		}else {
			current = current->next;
		}
		if (field == "name" && flag) { break; }
	}

	if (current != NULL && size == 1 && checkStrings(current, field, input_data)) {
		head = NULL;
		size--;
		flag = true;
	}

	checkFlag(flag);
}

void LinkedList::checkFlag(bool flag, int counter) {
	!flag ? std::cout << "Sorry, but the data you are searching for does not exist.\n\n":
	 		std::cout << "The data you are searching for have " << counter << " entries.\n\n"; 
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
		}
		if (field == "name" && flag) { break; }
		current = current->next;
	}	
	checkFlag(flag, counter);
}

void LinkedList::text(node* current) {
	std::cout << "Name:" << current->name << '\n';
	std::cout << "Net Worth:$" << current->networth << " B Country:" << current->country << " Source:" << current->source <<
		" RANK:" << current->ranking << " Age:" << current->age << " Industry:" << current->industry << "\n\n";
}

void LinkedList::swapNodes(node* current) {
	swap(current->name, current->next->name);
	swap(current->networth, current->next->networth);
	swap(current->country, current->next->country);
	swap(current->source, current->next->source);
	swap(current->ranking, current->next->ranking);
	swap(current->age, current->next->age);
	swap(current->industry, current->next->industry);
}

void LinkedList::checkNeighbor(node* current, double curr, double next, char option){
	if (option == 'a' && curr > next) {
		swapNodes(current);
	}else if (option == 'b' && curr < next){
		swapNodes(current);
	}
}

void LinkedList::checkNeighbor(node* current, std::string curr, std::string next, char option){
	if (option == 'a' && curr > next) {
		swapNodes(current);
	}else if (option == 'b' && curr < next){
		swapNodes(current);
	}
}

void LinkedList::bubbleSort(std::string field, char option) {
	std::string curr, next;

	for (int i = 0; i < size - 1; i++) {
		node* current = head;

		for (int j = 0; j < size - 1 - i; j++) {
			curr = getData(current, field);
			next = getData(current->next, field);

			if (field == "networth" || field == "rank" || field =="age") {
				checkNeighbor(current, stod(curr), stod(next), option);
			}else{
				checkNeighbor(current, curr, next, option);
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