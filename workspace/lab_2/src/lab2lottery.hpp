/*
 * lab2lottery.hpp
 *
 *  Created on: Sep 21, 2016
 *      Author: James
 */

#ifndef LAB2LOTTERY_HPP_
#define LAB2LOTTERY_HPP_
#include <time.h>


struct Customer {
	int id;
	int numberOfTickets;
	int **lotterynums;
};
//CustomerInfo

struct Store {
	int id;
	int Numcust;
	Customer *Customerlist;
	int numSold;
	int NumWinners[3];

};
//storeInfo

struct Owner {
	Store *Stores;
	int NumStores;
	int TotalSold;
	int TotalWinners[3];

};
//OwnerInfo


//Func declaration
Owner *makeOwner();
Store makeStore();
Customer makeCustomer();
void getWinners(int winners[]);
void findWinners(Owner *owner, int *ls);
int checkwin(int *nums, int *winners);

#endif /* LAB2LOTTERY_HPP_ */
