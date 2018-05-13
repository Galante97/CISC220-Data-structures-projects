/*
 * NodeTB.hpp
 *
 *  Created on: Nov 2, 2016
 *      Author: James
 */

#ifndef NODETB_HPP_
#define NODETB_HPP_

#include <iostream>
using namespace std;
#include <stdlib.h>

class NodeTB {
	friend class BSTB;
	friend class Game;

//todo: fix private public member thing
public:

	string data;
	unsigned char height;

	NodeTB *left;
	NodeTB *right;

	NodeTB(string x);
	~NodeTB();


};

#endif /* NODETB_HPP_ */
