#pragma once
#ifndef BUBBLE_SORT
#define BUBBLE_SORT

#include "LinkedList_Database.h"
#include <iostream>

void swap_nodes(node* current);

void perform_sorting(Database& access, string field, char task);

#endif // !BUBBLE_SORT
