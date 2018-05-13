/*
 * LLPQ.hpp
 *
 *  Created on: Oct 24, 2016
 *      Author: James
 */

#ifndef LLPQ_HPP_
#define LLPQ_HPP_

#include "LLNode.hpp"


class LLPQ {
	friend class LLNode;
	friend class LLHuff;

	int size;
	LLNode *first;
	LLNode *last;

public:

	LLPQ();
	~LLPQ(); //destructor
	void printLLPQ();
	void addFirst(char x, int co);
	void addAtFirst(char x, int co);
	LLNode remFirst();
	int findCode(char k);
	void sortLL();
	void swap(LLNode *temp1, LLNode *temp2);

	void insertUnique(char c);
	void insertInOrder(LLNode *n);
};

#endif /* LLPQ_HPP_ */
