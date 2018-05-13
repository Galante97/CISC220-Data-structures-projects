/*
 * LLHuff.cpp
 *
 *  Created on: Oct 25, 2016
 *      Author: James
 */

#include "LLHuff.hpp"
#include "LLNode.hpp"

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

LLHuff::LLHuff(string f) {
	file = f;
	root = NULL;
	size = 0;

	pq = new LLPQ();
	ascii = NULL;

} //Constructor

LLHuff::~LLHuff() {

}

void LLHuff::MakeHuff() {
	while (int i = 0 <= pq->size / 2) {
		LLNode *first = pq->first;
		pq->remFirst();
		pq->first = pq->first->next;

		LLNode *second = pq->first;
		pq->remFirst();
		pq->first = pq->first->next;

		LLNode *a_node = new LLNode("*");

		a_node->count = first->count + second->count;

		a_node->left = first;
		first->code = 0;
		a_node->right = second;
		second->code = 1;

		pq->insertInOrder(a_node);
		pq->insertInOrder(second);
		pq->insertInOrder(first);

		root = a_node;

		i++;
	}
}

void LLHuff::FindCode(LLNode *root, string path) { //1101
	LLNode *temp = root;

	if (path[0] == 1) {
		temp = temp->right;
	}
	if (path[0] == 0) {
		temp = temp->left;
	}

	if (temp->left == NULL && temp->right == NULL) {
		int codeValue = atoi(path.c_str());
		temp->code = codeValue;
	}


}

void LLHuff::ReadAscii() {
	cout << file << endl;
	ifstream infile("assciitable.txt", ios::in);
	char ch;
	string asciicode;
	if (!infile.is_open()) {
		return;
	}
	infile >> asciicode;
	pq->addFirst(" ", asciicode);
	infile >> asciicode;
	while (infile>>ch) {
	// loop getting single characters
	cout << ch;
	infile>>asciicode; // gets entire word (code)
	cout << asciicode << endl;
	pq->addAtFirst(ch,asciicode);
	}
	cout << endl;
	infile.close();

	ifstream infile2(file.c_str(),ios::in);
	ofstream outfile("asciivsn.txt",ios::out);
	char k;
	string comp;
	while (infile2.get(k)) {
		cout << k;
		comp = pq->findCode(k);
		if (comp == "") {
			cout << "ERROR WITH " << k << endl;
		}
		else {
			cout << k << ":" << comp << endl;
			outfile << comp << " ";
		}
		cout << endl;
		infile2.close();
		outfile.close();
	}
}

void LLHuff::ReadFile() {
	ifstream infile(file.c_str(), ios::in); // open file
	char k;
	while (infile.get(k)) { // loop getting single characters
		pq->insertUnique(k); // inserting the character k into the priority queue
	}
	infile.close();
}

void LLHuff::compressFile() {
	ofstream outfile("compressed.txt", ios::out); //create file

	LLNode *temp = pq->first;
	while (temp->next != NULL) {
		int comp = pq->findCode(temp->data);
		outfile << comp << " ";

		temp = temp->next;
	}
}

