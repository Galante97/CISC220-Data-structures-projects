/*
 * Game.hpp
 *
 *  Created on: Nov 2, 2016
 *      Author: James
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include "BSTB.hpp"
#include "NodeTB.hpp"
#include <iostream>
using namespace std;

class Game {
	friend class NodeTB;
	friend class BSTB;

	BSTB *dict;
	int numletters;
	char *currletters; //the random set of letters
	int totalwords;
	BSTB *wordlist;
	int numright;


public:

	Game();

	void startGame();
	void readTreeFromFile(string dictfile);

	char * getLetters(int x);
	void getWords(string x);

	bool checkWLetters(string s);
	bool checkWordsForScore(string s);

};

#endif /* GAME_HPP_ */
