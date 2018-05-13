/*
 * bookLL.hpp
 *
 *  Created on: Dec 4, 2016
 *      Author: James
 */

#ifndef BOOKLL_HPP_
#define BOOKLL_HPP_

#include "bNode.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class bookLL {
	friend class bNode;
	friend class setup;
	bNode *first;
	bNode *last;
	int size;
	int numberOfCategories;



public:
	bookLL();
	~bookLL();
	void printLL();
	void addFirst(string t, string a, string c, int y, int p);
	void insert(string t, string a, string c, int y, int p);
	void categoryView();
	void rangeOfYears();
	void rangeOfPages();
	void userInsert();
	void generalSearch();

};

struct catNumbers {
	string cat;
	int count;
};

#endif /* BOOKLL_HPP_ */
