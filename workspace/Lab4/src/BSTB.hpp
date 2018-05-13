/*
 * BSTB.hpp
 *
 *  Created on: Nov 2, 2016
 *      Author: James
 */

#ifndef BSTB_HPP_
#define BSTB_HPP_

#include "NodeTB.hpp"
#include <iostream>
#include <string>
using namespace std;

#include <stdlib.h>

class BSTB {
	friend class NodeTB;
	friend class Game;
	NodeTB *root;
	int count; // the count of the number of words in the AVL tree

public:
	BSTB();
	~BSTB();

	int getScore(NodeTB *n, BSTB *dict);

	void fixheight(NodeTB *n); //used as a helper func for adjustBalances, rotateLeft, rotateRight
	int balanceDifferce(NodeTB *n); // used as helper func for  adjustBalances, rotateLeft, rotateRight

	NodeTB *rotateRight(NodeTB *n);
	NodeTB * rotateLeft(NodeTB *n);

	NodeTB* adjustBalances(NodeTB *n); //note changed return type to NodeTB

	bool search(NodeTB *n, string x);

	bool insert(string x);
	NodeTB *insert(string x, NodeTB *n); //note changed return type to NodeTB so it can rebalance easy


	void printTreeio(NodeTB *n);
	void printTreePre(NodeTB *n);
	void printTreePost(NodeTB *n);

};

#endif /* BSTB_HPP_ */
