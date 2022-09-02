#include "Header.h"

bool Player::check() {
	if (counter == 64)
	{
		cout << "\nWell Done, You successively visited all squares \n";
		return false;
	}
	else if (continueToMove == false) {
		cout << "\nAfter " << counter << " there is no places left to move \n";
		return false;
	}
	else {
		return true;
	}
}