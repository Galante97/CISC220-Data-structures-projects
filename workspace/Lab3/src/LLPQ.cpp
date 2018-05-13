/*
 * LLPQ.cpp
 *
 *  Created on: Oct 24, 2016
 *      Author: James
 */

#include "LLPQ.hpp"

#include <iostream>
#include <stdlib.h>
using namespace std;

LLPQ::LLPQ() {
	first = NULL;
	last = NULL;
	size = 0;

} //constructor

LLPQ::~LLPQ() {
	LLNode *tmp = first;
	while (first != NULL) {
		tmp = first->next;
		delete first;
		first = tmp;
		size--;
	}
	first = NULL;
	last = NULL;
}

void LLPQ::printLLPQ() {
	//prints list
	LLNode *tmp = first;
	while (tmp != NULL) {
		cout << tmp->data << "->";
		tmp = tmp->next;
	}
	cout << endl;
}

void LLPQ::addFirst(char x, int co = -1) {
	//adds the first character to the list when nothing is there already
	size = 1;
	LLNode *node = new LLNode(x);
	node->code = co;
	first = node;
	last = node;

}

void LLPQ::addAtFirst(char x, int co = -1) {
	if (size == 0) {
		addFirst(x, -1);
	} else {
		LLNode *temp2 = first;
		first = new LLNode(x);
		first->next = temp2;
		size++;
	} //else

	LLNode *temp = first;
	temp->code = co;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	last = temp;

}

LLNode LLPQ::remFirst() {
	//remove the first node from the list, returning its data
	LLNode *temp = first;
	first = first->next;
	size--;
	return *temp;

}

int LLPQ::findCode(char k) {
	LLNode *temp = first;
	while (temp != NULL) {
		if (temp->data == k) {
			return temp->code;
		} else {
			temp = temp->next;
		}

	}

	return 0;
}

void LLPQ::sortLL() {
	LLNode *temp1 = first;
	LLNode *temp2 = temp1->next;

	while (temp2->next != NULL) {
		while (temp2->next != NULL) {
			if (temp1->count > temp2->count) {
				swap(temp1, temp2);
				temp2 = temp2->next;
			} else {
				temp2 = temp2->next;
			}
		}
		temp1 = temp1->next;
		temp2 = temp1->next->next;
	}
}

void LLPQ::swap(LLNode *temp1, LLNode *temp2) {

	if (temp1 == first) {
		temp2 = first;
		temp1->next = temp2->next;
		temp2->next = temp1;

	} else {
		LLNode *temp3 = temp1->prev;
		LLNode *temp4 = temp1->next;

		//swap1
		temp1->next = temp2->next;
		temp1->prev = temp2->prev;
		temp2->prev->next = temp1;
		temp2->next->prev = temp1;

		//swap2
		temp4->prev = temp2;
		temp3->next = temp2;

		temp2->prev = temp3;
		temp2->next = temp4;

	}

}

void LLPQ::insertUnique(char c) {
	// inserts only unique characters into the linked list.
	//If the character is already in the linked list, it increases the
	//count of that character
	bool inList = false;

	LLNode *temp = first;
	while (temp->next != NULL) {
		if (c == temp->data) {
			temp->count++;
			inList = true;
		} else {
			temp = temp->next;
		}
	}

	if (inList == false) {
		LLNode *node = new LLNode(c);
		node->count=1;
		insertInOrder(node);
	}

}

void LLPQ::insertInOrder(LLNode *n) {
	//will always insert in the front
	n->prev = NULL;
	n->next = first;

	first->prev = n;
	n = first;

}





