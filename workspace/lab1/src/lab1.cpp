//============================================================================
// Name        : file1.cpp
// Author      : James Galante, no partner
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include <stdlib>
#include <time.h>
using namespace std;

//Function declaration
void helloFunc();
int collatzConjecture(string x);
void collatzConjecture_B();
bool callByPointer(int *x, int *y, int *z);
bool perfectNumber(int x);
bool callByRef(int x, int y, int z);
void randomArray(int *arr, int size);
void printArray(int *arr2, int size);
void reverseArray(int *arr3, int size);
void minVal(int *arr4, int size);
void sumArray(int *arr5, int size);
void sortArray(int *arr6, int size);
void lowPass(int *arr11, int winSize, int arrLength);
void createMatrix(int **mat, int &a, int &b, int &c);

int main() {
	srand(time(NULL));
	//problem 1
	helloFunc();

	//problem 2
	string aNumber;
	cout << "Please enter an integer value: ";
	cin >> aNumber;
	collatzConjecture(aNumber);

	//problem 2b
	collatzConjecture_B();

	//PROBLEM 3

	//PROBLEM 4
	int pNum = 30;
	perfectNumber(pNum);

	//PROBLEM 3
	int rand1 = rand() % 10;
	int rand2 = rand() % 10;
	int rand3 = rand() % 10;

	cout << "num1: " << rand1 << " num2: " << rand2 << " num3: " << rand3
			<< endl;

	callByPointer(&rand1, &rand2, &rand3);

	//PROBLEM 5
	int rand4 = rand() % 10;
	int rand5 = rand() % 10;
	int rand6 = rand() % 10;
	cout << "num1: " << rand4 << " num2: " << rand5 << " num3: " << rand6
			<< endl;
	callByRef(rand4, rand5, rand6);

	//PROBLEM 6
	int randNum = rand() % 30 + 20;
	int nArray[randNum];
	randomArray(&nArray[0], randNum);

	//PROBLEM 11
	int randNum11 = rand() % 30 + 20;
	int Arr11[randNum11];

	int window = rand() % 5 + 3;
	lowPass(&Arr11[0], window, randNum11);

	//PROBLEM 12
	int **array;
	int x = -1;
	int y = -1;
	int z = -1;

	array = new int *[x];
	for (int i = 0; i < y; i++) {
		array[i] = new int[y];
		for (int j = 0; j < z; j++) {
			array[j] = new int[z];

		}
	}

	createMatrix(array, x, y, z);

	return 0;
}

//PROBLEM 1: hello world function
void helloFunc() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

}

//PROBLEM 2
int collatzConjecture(string x) {
	int x_int = std::stoi(x);
	int numberOfLoops = 0;

	while (x_int != 1) { // number is even
		if (x_int % 2 == 0) {
			x_int = x_int / 2;

		} else if (x_int % 2 != 0) { // number is odd
			x_int = (x_int * 3) + 1;

		} else if (x_int == 1) {  //number already = 1
			cout << "Your number = 1" << endl;
		}

		numberOfLoops = numberOfLoops + 1;

	}
	cout << "number of loops: " << numberOfLoops << endl;

	return numberOfLoops;

}

//PROBLEM 2B
void collatzConjecture_B() {
	string firstNumber;
	string secondNumber;

	cout << "Please Enter an integer: " << endl;
	cin >> firstNumber;
	cout << "Please Enter another integer: " << endl;
	cin >> secondNumber;

	int num1 = std::stoi(firstNumber);
	int num2 = std::stoi(secondNumber);

	if (num1 > num2) {
		while (num1 > num2) {
			num1 = num1 - 1;
			std::string num_str = std::to_string(num1);
			cout << "The number being inputed is: " << num1 << endl;
			cout << collatzConjecture(num_str) << endl;
			cout << "Collatz Conjecture is still working" << endl;
		}
	} else {
		while (num2 > num1) {
			num2 = num2 - 1;
			std::string num_str = std::to_string(num2);
			cout << "The number being inputed is: " << num2 << endl;
			cout << collatzConjecture(num_str) << endl;
			cout << "Collatz Conjecture is still working" << endl;
		}

	}
}

//PROBLEM 3
bool callByPointer(int *x, int *y, int *z) {
	if (*x < *y < *z) {
		return true;
	} else {
		return false;
	}
}

//PROBLEM 4
bool perfectNumber(int x) {
	x = x - 1;
	if (x >= 3) {
		int i = 1;
		int sum = 0;

		while (i < x) {
			if (x % i == 0) {
				sum = sum + i;
			}
			i++;
		}

		if (sum == x) {
			cout << i << " is a perfect number\n";
			return true, perfectNumber(x);
		} else {
			cout << i << " is not a perfect number\n";
			return false, perfectNumber(x);
		}
	}

}

//PROBLEM 5
bool callByRef(int x, int y, int z) {
	if (x < y < z) {
		return true;
	} else {
		return false;
	}
}

//PROBLEM 6
void randomArray(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		int max = 50;
		int min = -50;
		int randNum = rand() % (max - min + 1) + min;
		arr[i] = randNum;
	}
	cout << "Array 1 normal order: " << endl;

	printArray(&arr[0], size);
	reverseArray(&arr[0], size);
	minVal(&arr[0], size);
	sumArray(&arr[0], size);
	sortArray(&arr[0], size);
}

//PROBLEM 6B
void printArray(int *arr2, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr2[i] << " ";
	}

}

//PROBLEM 7
void reverseArray(int *arr3, int size) {
	cout << endl << "Array 1 reverse order: " << endl;
	int tempNum, i, k;
	for (i = 0, k = size - 1; i < size / 2; i++, k--) {
		tempNum = arr3[i];
		arr3[i] = arr3[k];
		arr3[k] = tempNum;

	}

	for (int i = 0; i < size; i++) {
		cout << arr3[i] << " ";
	}

	cout << endl << endl;
}

//PROBEM 8
void minVal(int *arr4, int size) {
	int min;
	for (int i = 0; i < size; i++) {
		if (arr4[i] < min) {
			min = arr4[i];
		}
	}

	cout << "The min value in the array is: " << min << endl;
}

//PROBLEM 9
void sumArray(int *arr5, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum = sum + arr5[i];
	}
	cout << "the sum of the array is: " << sum << endl;
}

//PROBLEM 10
void sortArray(int *arr6, int size) {

	int i, j, numOfSorts = 0;
	int temp;  // holding variable

	for (i = 1; (i <= size); i++) {
		for (j = 0; j < (size - 1); j++) {
			if (arr6[j + 1] > arr6[j]) {
				temp = arr6[j];    // swap elements
				arr6[j] = arr6[j + 1];
				arr6[j + 1] = temp;
				numOfSorts = numOfSorts + 1;  // indicates that a swap occurred.
			}
		}
	}

	cout << "sorted array: ";
	for (int i = size; i >= 1; i--)
		cout << arr6[i] << " ";

	cout << endl << "num of sorts: " << numOfSorts << endl << "size: " << size;

}
//PROBLEM 11
void lowPass(int *arr11, int winSize, int arrLength) {
	int LowPassArr[arrLength];

	cout << "window size: " << winSize << endl << "unorganized array: ";

	for (int i = 0; i < arrLength; i++) {
		int max = 50;
		int min = -50;
		int randNum = rand() % (max - min + 1) + min;
		arr11[i] = randNum;

		cout << arr11[i] << " , ";

	}  // filling array with random numbers

	cout << endl << "-------------------------------------------------------"
			<< endl;

	cout << endl << "low pass array: ";

	for (int j = 0; j < arrLength; j++) {
		int avg = 0;

		for (int k = 0; k < winSize; k++) {
			//objectsInWin = arr11[j] + arr11[j + k];

			avg = avg + (arr11[j + winSize / 2 - k]) / winSize;
			LowPassArr[j] = avg;

		}

		cout << LowPassArr[j] << " , ";

	}

}

//PROBLEM 12
void createMatrix(int **mat, int &a, int &b, int &c) {
	a = rand() % 5 + 2;
	b = rand() % 5 + 2;
	c = rand() % 5 + 2;

}
