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
#include <iostream>
#include "letters.h"

int inputSize = 0;
int inputRow = 0;
int inputColumn = 0;
int columnPivot = 5;

void fetchLetter(std::vector<std::vector<char>>& inputArray, char letter[][5]);
void printVector(std::vector<std::vector<char>>& vector);
void makeVectorMove(std::vector<std::vector<char>>& canvas, std::vector<std::vector<char>>& inputArray);

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

	std::vector<std::vector<char>> inputVector(5, std::vector<char>(inputSize * 5, '.'));

	for (int z = 0; z < inputSize; z++) {
		switch (input[z]) {
		case 'A':
			fetchLetter(inputVector, characterA);
			break;
		case 'B':
			fetchLetter(inputVector, characterB);
			break;
		case 'C':
			fetchLetter(inputVector, characterC);
			break;
		case 'D':
			fetchLetter(inputVector, characterD);
			break;
		case 'E':
			fetchLetter(inputVector, characterE);
			break;
		case 'F':
			fetchLetter(inputVector, characterF);
			break;
		case 'G':
			fetchLetter(inputVector, characterG);
			break;
		case 'H':
			fetchLetter(inputVector, characterH);
			break;
		case 'I':
			fetchLetter(inputVector, characterI);
			break;
		case 'J':
			fetchLetter(inputVector, characterJ);
			break;
		case 'K':
			fetchLetter(inputVector, characterK);
			break;
		case 'L':
			fetchLetter(inputVector, characterL);
			break;
		case 'M':
			fetchLetter(inputVector, characterM);
			break;
		case 'N':
			fetchLetter(inputVector, characterN);
			break;
		case 'O':
			fetchLetter(inputVector, characterO);
			break;
		case 'P':
			fetchLetter(inputVector, characterP);
			break;
		case 'Q':
			fetchLetter(inputVector, characterQ);
			break;
		case 'R':
			fetchLetter(inputVector, characterR);
			break;
		case 'S':
			fetchLetter(inputVector, characterS);
			break;
		case 'T':
			fetchLetter(inputVector, characterT);
			break;
		case 'U':
			fetchLetter(inputVector, characterU);
			break;
		case 'V':
			fetchLetter(inputVector, characterV);
			break;
		case 'W':
			fetchLetter(inputVector, characterW);
			break;
		case 'X':
			fetchLetter(inputVector, characterX);
			break;
		case 'Y':
			fetchLetter(inputVector, characterY);
			break;
		case 'Z':
			fetchLetter(inputVector, characterZ);
			break;
		case ',':
			fetchLetter(inputVector, characterComma);
			break;
		case '.':
			fetchLetter(inputVector, characterPeriod);
			break;
		case '\'':
			fetchLetter(inputVector, characterApostrophe);
			break;
		default:
			fetchLetter(inputVector, characterSpace);
			break;
		}
	}

	std::vector<std::vector<char>> canvas(5, std::vector<char>(100, '.'));

	makeVectorMove(canvas, inputVector);

}

void fetchLetter(std::vector<std::vector<char>>& inputArray, char letter[][5]) {
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

void printVector(std::vector<std::vector<char>>& vector) {
	for (int i = 0; i < 5; i++) {
		for (int q = 0; q < vector[0].size(); q++) {
			std::cout << vector[i][q];
		}
		std::cout << "" << std::endl;
	}

	std::this_thread::sleep_for(std::chrono::nanoseconds(100000000));
	system("cls");
}

void makeVectorMove(std::vector<std::vector<char>>& canvas, std::vector<std::vector<char>>& inputVector) {

	int p = 0;
	int temp = 0;
	int start = 0;

	for (int i = canvas[0].size() - 1; i >= 0; i--) {

		p = i;
		temp = i;

		canvas[0][i] = inputVector[0][0];
		canvas[1][i] = inputVector[1][0];
		canvas[2][i] = inputVector[2][0];
		canvas[3][i] = inputVector[3][0];
		canvas[4][i] = inputVector[4][0];

		while (p < canvas[0].size() - 1) {
			if (start + 1 < inputSize * 5) {
				++i;
				++start;
				canvas[0][i] = inputVector[0][start];
				canvas[1][i] = inputVector[1][start];
				canvas[2][i] = inputVector[2][start];
				canvas[3][i] = inputVector[3][start];
				canvas[4][i] = inputVector[4][start];
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

		printVector(canvas);

		std::cout << " " << std::endl;

		i = temp;

		start = 0;
	}

	int limit = inputSize * 5;
	int v = 0;
	for (int i = 0; i < inputSize * 5; i++) {
		while (v < limit && v < canvas[0].size()) {
			if (v + i + 1 != inputSize * 5) {
				canvas[0][v] = inputVector[0][v + i + 1];
				canvas[1][v] = inputVector[1][v + i + 1];
				canvas[2][v] = inputVector[2][v + i + 1];
				canvas[3][v] = inputVector[3][v + i + 1];
				canvas[4][v] = inputVector[4][v + i + 1];
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

		printVector(canvas);

		std::cout << " " << std::endl;

	}
}