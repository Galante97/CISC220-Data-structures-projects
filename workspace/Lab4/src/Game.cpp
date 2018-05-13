/*
 * Game.cpp
 *
 *  Created on: Nov 2, 2016
 *      Author: James
 */
#include "Game.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

Game::Game() {
	dict = NULL;
	numletters = 0;
	currletters = NULL;
	totalwords = 0;
	wordlist = NULL;
	numright = 0;

} //constructor

void Game::readTreeFromFile(string dictfile) {

	dict = new BSTB();
	string word;

	ifstream file(dictfile.c_str()); // converts a string to a character array string word;
	while (!file.eof()) { // checks for end of file
		file >> word;
		if (!file.eof()) {
			dict->insert(word);
		}
	}

	startGame();

	return;
}

void Game::startGame() {
	cout << "How many letters do you want? " << endl;
	cin >> numletters;

	wordlist = new BSTB();
	getLetters(numletters);

	cout << "Your letters are: ";
	for (int i = 0; i < numletters; i++) {
		cout << currletters[i] << "," << endl;
	}
	cout << "Start creating words! (type \"-1\" when you can't think of more words)" << endl;

	string userWord;
	while (userWord != "-1") {
		cin >> userWord;

		if (checkWLetters(userWord) == true) {
			getWords(userWord);


		} else {
			cout << "Your word \"" << userWord
					<< "\" contains letters that are not allowed" << endl;
		}
	}

	if (userWord == "-1") {
		cout << "Game Over!" << endl;
		cout << "Your score is: " << numright <<endl;
		cout << "You had " << totalwords << " total correct words, they were: " << endl;
		wordlist->printTreeio(wordlist->root);
	}

	startGame();
}

//creates random list of letters
char* Game::getLetters(int x) {
	currletters = new char[x];

	const char* const az = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char* const vowel = "AEIOU";

	int randVowel = rand() % 4;
	currletters[0] = vowel[randVowel];

	for (int i = 1; i < x; i++) {
		int randLetter = rand() % 25;
		currletters[i] = az[randLetter];
	}

	return currletters;
}

//adds users words to wordlist tree
void Game::getWords(string x) {
	if (checkWordsForScore(x) == true) {
		wordlist->insert(x);
			totalwords++;
	} else {
		cout << "word not in dictionary" << endl;

	}
}

//checks to see if letters in user entered word is in currletters
bool Game::checkWLetters(string s) {
	bool letterMatched = false;

	for (int j = 0; j < s.size(); j++) {
		for (int i = 0; i < numletters; i++) {
			if (s[j] == currletters[i]) {
				letterMatched = true;
			}
		}
		if (letterMatched == true) {
			letterMatched = false;
			continue;
		} else {
			//contains letter(s) that is not in currletter
			break;

		}
	}

	return true;
}


//scores
bool Game::checkWordsForScore(string s) {
	if (dict->search(dict->root, s) == true) {
		numright = numright + 3;
		return true;
	} else {
		numright = numright - 6;
		return false;
	}

}

