#include "Bubble_Sort.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

void swap_nodes(node* current) {
	swap(current->name, current->next->name);

	swap(current->net_worth, current->next->net_worth);

	swap(current->country, current->next->country);

	swap(current->source, current->next->source);

	swap(current->ranking, current->next->ranking);

	swap(current->age, current->next->age);

	swap(current->industry, current->next->industry);
}

void perform_sorting(LinkedList& access, string field, char option) {

	//option a == increasing
	//option b == decreasing

	if (option == 'a') {
		for (int i = 0; i < access.size - 1; i++) {
			node* current = access.head;
			for (int j = 0; j < access.size - 1 - i; j++) {
				if (access.getVal(current, field) > access.getVal(current->next, field)) {
					swap_nodes(current);
				}
				current = current->next;
			}
		}
	}
	else {
		for (int i = 0; i < access.size - 1; i++) {
			node* current = access.head;
			for (int j = 0; j < access.size - 1 - i; j++) {
				if (access.getVal(current, field) < access.getVal(current->next, field)) {
					swap_nodes(current);
				}
				current = current->next;
			}
		}
	}
}
