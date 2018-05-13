/*
 * LLNode.cpp
 *
 *  Created on: Oct 24, 2016
 *      Author: James
 */

#include "LLNode.hpp"

#include <iostream>
#include <stdlib.h>
using namespace std;


LLNode::LLNode(char x) {
	data = x;
	count = NULL;
	code = NULL;

	next = NULL;
	prev = NULL;

	left = NULL;
	right = NULL;


} //constructor

LLNode::~LLNode() {
	if (next != NULL) {
		cout << "delete" << endl;

	}
}



