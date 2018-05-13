/*
 * LLHuff.hpp
 *
 *  Created on: Oct 25, 2016
 *      Author: James
 */

#ifndef LLHUFF_HPP_
#define LLHUFF_HPP_

#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>

#include "LLNode.hpp"
#include "LLPQ.hpp"

class LLHuff {
	string file;
	LLNode *root;
	int size;

public:

	LLPQ *pq; //priority queue list of character nodes, made in first part
	LLPQ *ascii; //linked list of characters and their corresponding asci codes,read in from the asci.txt file

	LLHuff(string f);
	~LLHuff();

	void MakeHuff();
	void FindCode(LLNode *root, string path);
	void ReadAscii();
	void ReadFile();
	void compressFile();
};

#endif /* LLHUFF_HPP_ */
