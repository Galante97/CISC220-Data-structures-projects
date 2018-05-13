/*
 * NodeTB.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: James
 */

#include "NodeTB.hpp"

#include <iostream>
#include <stdlib.h>
using namespace std;

NodeTB::NodeTB(string x) {

	data = x;
	height = NULL;
	left = NULL;
	right = NULL;

} //constructor

NodeTB::~NodeTB() {
	/***TODO: FIX DESTRUCTOR LATER***/

	if (left != NULL) {
		cout << "delete" << endl;

	}
}


