#include "Bubble_Sort.h"
#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std;

void swap_nodes(node* current) {
	swap(current->name, current->next->name);

	swap(current->networth, current->next->networth);

	swap(current->country, current->next->country);

	swap(current->source, current->next->source);

	swap(current->ranking, current->next->ranking);

	swap(current->age, current->next->age);

	swap(current->industry, current->next->industry);
}

void perform_sorting(LinkedList& access, string field, char option) {

	//option a == increasing
	//option b == decreasing
	
	for (int i = 0; i < access.size - 1; i++) {
		node* current = access.head;
		for (int j = 0; j < access.size - 1 - i; j++) {

			double num1 = stod(access.getData(current, field));
			double num2 = stod(access.getData(current->next, field));
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
