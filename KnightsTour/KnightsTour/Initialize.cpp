#include "Header.h"

void Player::Initialize() {
	// random position using random engine 
	std::uniform_int_distribution<unsigned int> randomPost{ 0,7 };
	m = randomPost(myRandomEngine);
	n = randomPost(myRandomEngine);

}