/*
 * LLNode.hpp
 *
 *  Created on: Oct 24, 2016
 *      Author: James
 */

#ifndef LLNODE_HPP_
#define LLNODE_HPP_

class LLNode {
	friend class LLPQ;
	friend class LLHuff;
	char data;
	int count;
	int code;

	LLNode *next;
	LLNode *prev;

	LLNode *left;
	LLNode *right;

public:
	LLNode(char x);
	~LLNode();
};

#endif /* LLNODE_HPP_ */

