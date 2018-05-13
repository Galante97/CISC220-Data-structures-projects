/*
 * LLSE.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: Debra
 */

#include "Node.hpp"
#include "LLSE.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

LLSE::LLSE() {
	first = NULL;
	last = NULL;
	size = 0;
}
LLSE::~LLSE() {
	Node *tmp = first;
	for (int i = 0; i < size; i++) {
		tmp = first->next;
		delete first;
		first = tmp;
	}
}

void LLSE::printLL() {
	Node *tmp = first;
	while (tmp != NULL) {
		cout << tmp->count << ":" << tmp->word << endl;
		tmp = tmp->next;
	}
}

void LLSE::addFirst(string w) {
	first = new Node(w);
	last = first;
	size = 1;
}

void LLSE::insertUnique(string w) {
	Node *tmp = first;
	if (tmp == NULL) {
		addFirst(w);
	} else {
		while (tmp != NULL && tmp->word < w) {
			tmp = tmp->next;
		}
		if ((tmp != NULL) && (tmp->word == w)) {
			tmp->count++;
		} else {
			Node *tmp2 = new Node(w);
			if (tmp != NULL) {
				if (tmp->prev != NULL) {
					tmp->prev->next = tmp2;
					tmp2->prev = tmp->prev;
				} else {
					first = tmp2;
				}
				tmp2->next = tmp;
				tmp->prev = tmp2;
			} else {
				last->next = tmp2;
				tmp2->prev = last;
				last = tmp2;
			}
			size++;

		}
	}
}

// Write an insertion Sort on the linked list (not an array, 
// a linked list!
void LLSE::insertionSortLL() {
	Node *current = first;
	Node *head = first;
	Node *insertionPointer = head;

	current = current->next;

	while (current != NULL) {
		insertionPointer = head;

		while (insertionPointer->next != current) {
			if (insertionPointer->word > current->word) {

				string temp = current->word;
				current->word = insertionPointer->word;
				insertionPointer->word = temp;

			} else {
				insertionPointer = insertionPointer->next;
			}
		}
		current = current->next;
	}
}

// Convert the linked list to an array of nodes and return that array
Node * LLSE::convertToArray() {
	int i = 0;
	Node *tmp = first;
	while (tmp->next != NULL) {
		wordarr[i] = tmp->word;
		tmp = tmp->next;
		i++;
	}

	return wordarr;
}

// For the quicksort - the partition
int LLSE::partition(int beg, int end) {
	/*int i = beg;
	int j = end;
	int tmp;
	int pivot = wordarr[(beg + end) / 2].count;

	while (i <= j) {
		while (wordarr[i].count < pivot)
			i++;
		while (wordarr[j].count > pivot)
			j--;
		if (i <= j) {
			tmp = wordarr[i].count;
			wordarr[i] = wordarr[j];
			wordarr[j].count = tmp;
			i++;
			j--;
		}
	}

	return pivot; */
}

// your recursive quicksort
void LLSE::quickSort(int beg, int end) {
/*	int middle;
	if (beg < end) {
		middle = partition(beg, end);
		quickSort(beg, middle);   // sort first section
		quickSort(middle + 1, end);   // sort second section
	}

	return; */

}

//Take the linked list and create a binary heap
Node * LLSE::makeHeap() {
/*	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	} */
}

//Sort the heap array using heapsort
void LLSE::heapSort() {
	// Build heap (rearrange array)
/*	for (int i = wordarr / 2 - 1; i >= 0; i--) {
		makeHeap();
	}

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);

	} */
}

