#include "Header.h"


void display2(std::array<std::array<int, colSize>, rowSize>& arr) {

	for (auto const& row : arr)
	{
		cout << "\t\t";
		for (auto const& element : row)
			std::cout << element << " ";
		cout << "\n";
	}
}

int main()
{

	Player game_1;
	cout << " !! Welcome to the Knight's Tour Problem !!" << endl;
	cout << "Lets see if the Knight that has L-shaped moves in the chess game can visit each and every square once and only once " << endl;
	game_1.Go();

}
