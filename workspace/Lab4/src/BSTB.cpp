/*
 * BSTB.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: James
 */

#include "BSTB.hpp"

#include <iostream>
#include <stdlib.h>
using namespace std;

BSTB::BSTB() {
	root = NULL;
	count = 0;

} //constructor

//TODO: descrustor
BSTB::~BSTB() {

}

int BSTB::getScore(NodeTB *n, BSTB *dict) {
	if (n != NULL) {
		getScore(n->left, dict);
		getScore(n->right, dict);
		count++;
	}
	return count;
}

//calc height
unsigned char height(NodeTB *n) {
	return n ? n->height : 0;
}

//height left right
void fixheight(NodeTB *n) {
	unsigned char hLeft = height(n->left);
	unsigned char hRight = height(n->right);
	n->height = (hLeft > hRight ? hLeft : hRight) + 1;
}

//calculate balance factor of a node
int balanceDifferce(NodeTB *n) {
	return height(n->right) - height(n->left);
}

//right rotation
NodeTB *rotateRight(NodeTB *n) {
	NodeTB *temp = n->left;
	n->left = temp->right;
	temp->right = n;
	fixheight(n);
	fixheight(temp);
	return temp;

}

//left rotation
NodeTB *rotateLeft(NodeTB *n) {
	NodeTB *temp = n->right;
	n->right = temp->left;
	temp->left = n;
	fixheight(n);
	fixheight(temp);
	return temp;

}

//fixes balance of tree if its off
//note I changed it to return NODE
NodeTB* adjustBalances(NodeTB *n) {
	fixheight(n);

	if (balanceDifferce(n) == 2) {
		if (balanceDifferce(n->right) < 0) {
			n->right = rotateRight(n->right);
		}
		return rotateLeft(n);
	}

	if (balanceDifferce(n) == -2) {
		if (balanceDifferce(n->left) > 0) {
			n->left = rotateLeft(n->left);
		}
		return rotateRight(n);
	}

	return n; // no balance needed
}



bool BSTB::search(NodeTB *n, string x) {
	if (x < n->data) {
		search(n->left, x);
	} else {
		if (x > n->data) {
			search(n->right, x);
		} else {
			cout << "data found" << endl;
			return true;
		}
	}

	cout << "data NOT found" << endl;
	return false;

}

//insert in the tree with n root and re balance
//TODO: may need to compare lengths in if statement
NodeTB *insert(string x, NodeTB *n) {
	if (!n) {
		return new NodeTB(x);
	}
	if (x < n->data) {
		n->left = insert(x, n->left);
	} else {
		n->right = insert(x, n->right);
	}
	return adjustBalances(n);
}

bool BSTB::insert(string x) {
	NodeTB *wNode = new NodeTB(x);

	if (search(wNode, x) == false) {
		cout << "word does not exist exists, adding: " << x << endl;
		insert(x, wNode);
		return true;
	}
	cout << "word " << x << " already exists in tree" << endl;

	return false;
}



//INORDER printing
void BSTB::printTreeio(NodeTB *n) {
	if (n != NULL) {
		printTreeio(n->left);
		cout << n->data << "\t";
		printTreeio(n->right);

	}

}

//PREORDER printing
void BSTB::printTreePre(NodeTB *n) {
	if (n != NULL) {
		cout << n->data << "\t";

		printTreePre(n->left);
		printTreePre(n->right);
	}

}

//POSTORDER printing
void BSTB::printTreePost(NodeTB *n) {
	if (n != NULL) {
		printTreePost(n->left);
		printTreePost(n->right);

		cout << n->data << "\t";
	}
}

