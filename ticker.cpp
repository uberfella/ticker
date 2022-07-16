/*
1) Procedural moving single character from the right to the left designed in the most stupid way ✓
2) Moving single character from the right to the left with for loops using arrays of specific size ✓
3) Adding while loop that uses arrays of any size ✓
4) Adding 4 lines, refactoring program to use two-dimensional arrays ✓
	4.1) Procedural moving of predefined letter from the right to the left designed in the most stupid way ✓
	4.2) Adding while loop ✓
5) Reading and showing multiple letters - so-called words
	5.1) Counting string input size, testing different letters. We need the input size to know what size of input array we create (don't need anymore with vectors) ✓
	5.2) For loops for reading the input and creating input char array ✓
		5.2.0) Copying a coulpe of two-dimensional arrays into one with a function ✓
6) Refactoring most of the arrays to vectors because of unstable results with raw arrays ✓
*/

#include <thread>  
#include <string>
#include <chrono>
#include <vector>
#include "letters.h"
#include <iostream>

int inputSize = 0;
int inputRow = 0;
int inputColumn = 0;
int columnPivot = 0;

void caseFunc(std::vector<std::vector<char>>& inputArray, char letter[][5]);
void print(std::vector<std::vector<char>>& vector);
void moveChar(std::vector<std::vector<char>>& canvas, std::vector<std::vector<char>>& inputArray);

int main()
{
	std::thread thread;

	std::string stringInput;
	std::getline(std::cin, stringInput);

	inputSize = stringInput.size();

	std::vector<char> input;

	for (int i = 0; i < inputSize; i++) {
		input.push_back(stringInput[i]);
	}

	inputRow = 0; inputColumn = 0; columnPivot = 5;

	std::vector<std::vector<char>> inputArray(5, std::vector<char>(inputSize * 5, '.'));

	for (int z = 0; z < inputSize; z++) {
		switch (input[z]) {
		case 'A':
			caseFunc(inputArray, characterA);
			break;
		case 'B':
			caseFunc(inputArray, characterB);
			break;
		case 'C':
			caseFunc(inputArray, characterC);
			break;
		case 'D':
			caseFunc(inputArray, characterD);
			break;
		case 'E':
			caseFunc(inputArray, characterE);
			break;
		case 'F':
			caseFunc(inputArray, characterF);
			break;
		case 'G':
			caseFunc(inputArray, characterG);
			break;
		case 'H':
			caseFunc(inputArray, characterH);
			break;
		case 'I':
			caseFunc(inputArray, characterI);
			break;
		case 'J':
			caseFunc(inputArray, characterJ);
			break;
		case 'K':
			caseFunc(inputArray, characterK);
			break;
		case 'L':
			caseFunc(inputArray, characterL);
			break;
		case 'M':
			caseFunc(inputArray, characterM);
			break;
		case 'N':
			caseFunc(inputArray, characterN);
			break;
		case 'O':
			caseFunc(inputArray, characterO);
			break;
		case 'P':
			caseFunc(inputArray, characterP);
			break;
		case 'Q':
			caseFunc(inputArray, characterQ);
			break;
		case 'R':
			caseFunc(inputArray, characterR);
			break;
		case 'S':
			caseFunc(inputArray, characterS);
			break;
		case 'T':
			caseFunc(inputArray, characterT);
			break;
		case 'U':
			caseFunc(inputArray, characterU);
			break;
		case 'V':
			caseFunc(inputArray, characterV);
			break;
		case 'W':
			caseFunc(inputArray, characterW);
			break;
		case 'X':
			caseFunc(inputArray, characterX);
			break;
		case 'Y':
			caseFunc(inputArray, characterY);
			break;
		case 'Z':
			caseFunc(inputArray, characterZ);
			break;
		case ',':
			caseFunc(inputArray, characterComma);
			break;
		case '.':
			caseFunc(inputArray, characterPeriod);
			break;
		default:
			caseFunc(inputArray, characterSpace);
			break;
		}
	}

	std::vector<std::vector<char>> canvas(5, std::vector<char>(25, '.'));

	std::cout << canvas[0].size() << std::endl;

	moveChar(canvas, inputArray);

}

void caseFunc(std::vector<std::vector<char>>& inputArray, char letter[][5]) {
	for (int i = 0; i < 5; i++) {
		for (int q = columnPivot - 5; q < columnPivot; q++) {
			inputArray[i][q] = letter[inputRow][inputColumn];
			inputColumn++;
		}
		inputColumn = 0;
		inputRow++;
	}
	inputRow = 0;
	columnPivot += 5;
}

void print(std::vector<std::vector<char>>& vector) {
	for (int i = 0; i < 5; i++) {
		for (int q = 0; q < vector[0].size(); q++) {
			std::cout << vector[i][q];
		}
		std::cout << "" << std::endl;
	}

	std::this_thread::sleep_for(std::chrono::nanoseconds(100000000));
	system("cls");
}

void moveChar(std::vector<std::vector<char>>& canvas, std::vector<std::vector<char>>& inputArray) {

	int p = 0;
	int temp = 0;
	int start = 0;

	for (int i = canvas[0].size() - 1; i >= 0; i--) {

		p = i;
		temp = i;

		canvas[0][i] = inputArray[0][0];
		canvas[1][i] = inputArray[1][0];
		canvas[2][i] = inputArray[2][0];
		canvas[3][i] = inputArray[3][0];
		canvas[4][i] = inputArray[4][0];

		while (p < canvas[0].size() - 1) {
			if (start + 1 < inputSize * 5) {
				++i;
				++start;
				canvas[0][i] = inputArray[0][start];
				canvas[1][i] = inputArray[1][start];
				canvas[2][i] = inputArray[2][start];
				canvas[3][i] = inputArray[3][start];
				canvas[4][i] = inputArray[4][start];
			}
			else {
				++i;
				canvas[0][i] = '.';
				canvas[1][i] = '.';
				canvas[2][i] = '.';
				canvas[3][i] = '.';
				canvas[4][i] = '.';
			}
			p++;
		}

		print(canvas);

		std::cout << " " << std::endl;

		i = temp;

		start = 0;
	}

	int limit = inputSize * 5;
	int v = 0;
	for (int i = 0; i < inputSize * 5; i++) {
		while (v < limit && v < canvas[0].size()) {
			if (v + i + 1 != inputSize * 5) {
				canvas[0][v] = inputArray[0][v + i + 1];
				canvas[1][v] = inputArray[1][v + i + 1];
				canvas[2][v] = inputArray[2][v + i + 1];
				canvas[3][v] = inputArray[3][v + i + 1];
				canvas[4][v] = inputArray[4][v + i + 1];
			}
			else {
				canvas[0][v] = '.';
				canvas[1][v] = '.';
				canvas[2][v] = '.';
				canvas[3][v] = '.';
				canvas[4][v] = '.';
				break;
			}
			v++;
		}
		v = 0;

		print(canvas);

		std::cout << " " << std::endl;

	}
}