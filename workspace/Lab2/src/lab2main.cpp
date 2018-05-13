/*
 * lab2main.cpp
 *
 *  Created on: Oct 4, 2016
 *      Author: James
 */

#include <iostream>
using namespace std;

#include <time.h>
#include <stdlib.h>

#include "lab2Lottery.hpp"

int main() {

	cout << "test";

	srand(time(NULL));

	Owner *me = makeOwner();
	int winners[3] = { 0, 0, 0 };
	getWinners(winners);

	for (int i = 0; i < 3; i++) {
		cout << winners[i] << endl;
	}

	findWinners(me, winners);

	cout << "won with 1 number: " << me->TotalWinners[0] << endl;
	cout << "won with 2 numbers: " << me->TotalWinners[1] << endl;
	cout << "won with 3 numbers: " << me->TotalWinners[2] << endl;

	return 0;
}



