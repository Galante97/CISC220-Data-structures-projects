/*
 * lab2lottery.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: James
 */

#include "lab2lottery.hpp"

#include <iostream>
using namespace std;

Owner *makeOwner() {
	struct Owner owner;

	int randStores = rand() % 10 + 1;
	owner.NumStores = randStores;
	owner.Stores[owner.NumStores];

	for (int i = 0; i <= randStores; i++) {
		owner.Stores[i] = makeStore();
	} //making stores and filling the list with them

	return &owner;
}

Store makeStore() {
	struct Store store;
	int numID = rand() % 100 + 1;
	store.id = numID;

	int randCustNum = rand() % 10 + 1;
	store.Numcust = randCustNum;

	for (int i = 0; i <= store.Numcust; i++) {
		store.Customerlist[i] = makeCustomer();
	}

	return store;
}

Customer makeCustomer() {
	struct Customer customer;

	int id = rand() % 1000 + 1;
	customer.id = id;

	int numTickets = rand() % 20 + 1;
	customer.numberOfTickets = numTickets;

	//customer.lotterynums[customer.numberOfTickets][3];

	bool lotNumEqual = true;

	for (int i = 0; i <= customer.numberOfTickets; i++) {

		int lotterNum1 = rand() % 9 + 0;
		int lotterNum2 = rand() % 9 + 0;
		int lotterNum3 = rand() % 9 + 0;

		while (lotNumEqual == true) {

			if ((lotterNum1 || lotterNum2 != lotterNum3)
					&& (lotterNum1 != lotterNum2)) {
				lotNumEqual = false;
			} else {
				lotterNum1 = rand() % 9 + 0;
				lotterNum2 = rand() % 9 + 0;
				lotterNum3 = rand() % 9 + 0;
			}
		} // checking to see if any of the numbers are the same as each other

		for (int j = 0; j <= 1; i++) {
			customer.lotterynums[customer.numberOfTickets][j] = lotterNum1;
			customer.lotterynums[customer.numberOfTickets][j + 1] = lotterNum2;
			customer.lotterynums[customer.numberOfTickets][j + 2] = lotterNum3;
		}

	}

	return customer;
}

void getWinners(int winners[]) {
	int lotterNum1 = rand() % 9 + 0;
	int lotterNum2 = rand() % 9 + 0;
	int lotterNum3 = rand() % 9 + 0;
	bool lotNumEqual = true;

	while (lotNumEqual == true) {

		if ((lotterNum1 || lotterNum2 != lotterNum3)
				&& (lotterNum1 != lotterNum2)) {
			lotNumEqual = false;
		} else {
			lotterNum1 = rand() % 9 + 0;
			lotterNum2 = rand() % 9 + 0;
			lotterNum3 = rand() % 9 + 0;
		}
	} // checking to see if any of the numbers are the same as each other

	winners[0] = lotterNum1;
	winners[1] = lotterNum2;
	winners[2] = lotterNum3;

}

int checkwin(int *nums, int *winners) {
	int matchingNumbers = 0;
	for (int i = 0; i <= 3; i++) {
		if (nums[0] == winners[i]) {
			matchingNumbers = matchingNumbers + 1;
		}
		if (nums[1] == winners[i]) {
			matchingNumbers = matchingNumbers + 1;
		}
		if (nums[2] == winners[i]) {
			matchingNumbers = matchingNumbers + 1;
		}

	}
	return matchingNumbers;
}

void findWinners(Owner *owner, int *ls) {

	cout << "Total lottery tickets sold: " << owner->TotalSold << endl;
	cout << "Winning numbers: " << ls << endl;

	cout << "Store: " << owner->Stores->id << endl;
	cout << "Customer: " << owner->Stores->Customerlist->id << endl;
	cout << "Ticket: " << owner->Stores->Customerlist->lotterynums << endl;
	cout << "total count for this store is: " << owner->Stores->NumWinners
			<< endl;
}

