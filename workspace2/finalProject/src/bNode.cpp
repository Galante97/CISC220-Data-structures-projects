/*
 * bNode.cpp
 *
 *  Created on: Dec 4, 2016
 *      Author: James
 */

#include "bNode.hpp"
#include <iostream>
#include <string>
using namespace std;

bNode::bNode(string t, string a, string c, int y, int p) {

	next = NULL;
	prev = NULL;

	bookTitle = t;
	author = a;
	category = c;
	pages = p;
	yearPublished = y;
	count = 0;

}
