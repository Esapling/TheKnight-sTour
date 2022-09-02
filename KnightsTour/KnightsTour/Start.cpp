#include "Header.h"

void Player::start() {
	cout << "\n...Starting game....\n";
	Initialize();
	arr[m][n] = counter;
	display2(arr);
	counter++; // one position has already been taken 
}