/*
 * bNode.hpp
 *
 *  Created on: Dec 4, 2016
 *      Author: James
 */

#ifndef BNODE_HPP_
#define BNODE_HPP_

#include <iostream>
#include <string>
using namespace std;

class bNode {
	friend class bookLL;
	bNode *next;
	bNode *prev;

	string bookTitle;
	string author;
	string category;
	int pages;
	int yearPublished;
	int count;



public:
	bNode(string t, string a, string c, int y, int p);
	//bNode();
};


#endif /* BNODE_HPP_ */
