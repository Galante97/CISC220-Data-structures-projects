//============================================================================
// Name        : Lab3.cpp
// Author      : James Galante
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>
#include "LLNode.hpp"
#include "LLPQ.hpp"
#include "LLHuff.hpp"

#include <stdio.h>
using namespace std;


int main() {
	cout << "reading file" << endl;
	LLHuff code("tests.txt");
	code.ReadFile();
	code.pq->printLLPQ();
	code.pq->sortLL();
	code.pq->printLLPQ();
	code.MakeHuff();
	code.compressFile();
	code.ReadAscii();
	return 0;
}
