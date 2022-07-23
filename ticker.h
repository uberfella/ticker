#pragma once


class Ticker 
{
public :
	void fetchLetter(std::vector<std::vector<char>>& inputArray, char letter[][5]);
	void printVector(std::vector<std::vector<char>>& vector);
	void makeVectorMove(std::vector<std::vector<char>>& canvas, std::vector<std::vector<char>>& inputArray);
};