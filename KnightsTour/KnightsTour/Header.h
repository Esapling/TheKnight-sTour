#pragma once
#include <iostream>
#include <array>
#include <random>
#include <ctime> 
#include <vector>
 

const int rowSize = 8;
const int colSize = 8;


using std::cout;
using std::endl;

void display2(std::array<std::array<int, colSize>, rowSize>& arr);


struct Player {
	int m, n, counter;
	Player()
		: m(0), n(0), counter(1)
	{ }
	std::default_random_engine myRandomEngine{ static_cast<unsigned int>(time(0)) };

	bool continueToMove = true; // this is defined to check 
	std::array<std::array<int, colSize>, rowSize> arr{}; // an 2d array that will hold the poistion of the knight
	std::vector<int> visitedPoints; 
	// this array will hold the option numbers that was tried and didnt satisfy the condition somehow 
	//so that those options are not tried again 
	void Initialize();
	void start();
	void move();
	bool check();
	void Go() {
		start();
		do {
			move();
		} while (check());
	}
};