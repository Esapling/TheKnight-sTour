#include <iostream>
#include <array>
#include <random>
#include <ctime> 
#include <vector>
using std::cout;
using std::endl;

const int rowSize = 8;
const int colSize = 8;
void display2(std::array<std::array<int, colSize>, rowSize>& arr);
struct Player {
	int m, n, counter;
	Player()
		: m(0), n(0), counter(1)
	{ }
	std::default_random_engine myRandomEngine{ static_cast<unsigned int>(time(0)) };
	bool continueToMove = true;
	std::array<std::array<int, colSize>, rowSize> arr{}; // an 2d array that will hold the poistion of the knight

	void Initialize() {
		// random position using random engine 
		std::uniform_int_distribution<unsigned int> randomPost{ 0,7 };
		m = randomPost(myRandomEngine);
		n = randomPost(myRandomEngine);
	}
	void start() {
		cout << "\n...Starting game....\n";
		Initialize();
		arr[m][n] = counter;
		display2(arr);
		counter++; // one position has already been taken 
	}
	void move()
	{
		// the knight in chess game has L-shaped moves 
		// assume the knight is at m,n position,
		// then it can either move +-2 in y-axis and +-1 in x-axis
		// or it can move +-2 in x-axis and +-1 in y-axis
		// start(); randomly initialize
		//  lastly bound checking : if m or n >= 8 return move until we can stay insiide board
		// also check if new position has already been selected by if arr[m][n] != 0 
		// if it s been already selected than change 
		// if there is not any possible places to go just stop and simply return last counter to see
		// how many movement the knight could go 
		// and check if counter reaches 64 then well done !! 
 		std::uniform_int_distribution<unsigned int > random_option{ 1, 8 };
		int option{ -1 };
		bool out_of_range = true;
		std::vector<int> visitedPoints; // this array will hold the option numbers that was tried and didnt satisfy the condition somehow so that those options are not  tried again 
		// and if this array reaches 8 size that means The knights doesnt have any possible point 
		visitedPoints.assign(8, -1); // fill array 9 times with -1
		int last_option_value = -1; // prevents getting the same value for option 
		while (out_of_range)
		{
			while (true)
			{
				option = random_option(myRandomEngine); // randomly select an L shaped move if not possible then select another one 
												// possible that can be selected the same unacceptable movement again and again !!! not any checking 
				
				if (visitedPoints[option - 1] == -1 && option != last_option_value)
				{
					last_option_value = option;
					break;
				}
				
			}
			switch (option) {
			case 1:
				if (m + 2 <= 7 && n + 1 <= 7 && arr[m + 2][n + 1] == 0)
				{
					m = m + 2;
					n = n + 1;
					out_of_range = false;
					cout << "\n" << " option " << option <<" is called \n\n";
				}
				else {
					cout << "\n" << "  option" << option << " is called  but didnt satisfy the condition \n\n";

					visitedPoints[option - 1] = 1;

				}
				break;
			case 2:
				if (m + 2 <= 7 && n >= 1 && arr[m + 2][n - 1] == 0)
				{
					m += 2;
					n -= 1;
					out_of_range = false;
					cout << "\n" << " option " << option << " is called \n\n";

				}
				else {
					cout << "\n" << "  option" << option << " is called  but didnt satisfy the condition \n\n";

					visitedPoints[option - 1] = 1;
				}
				break;
			case 3:
				if (m - 2 >= 0 && n + 1 <= 7 && arr[m - 2][n + 1 ] == 0)
				{
					m -= 2;
					n += 1;
					out_of_range = false;
					cout << "\n" << " option " << option << " is called \n\n";

				}
				else {
					cout << "\n" << "  option" << option << " is called  but didnt satisfy the condition \n\n";

					visitedPoints[option - 1] = 1;
				}
				break;
			case 4:
				if (m - 2 >= 0 && n - 1 >= 0 && arr[m - 2][n - 1] == 0)
				{
					m = m - 2;
					n = n - 1;
					out_of_range = false;
					cout << "\n" << " option " << option << " is called \n\n";

				}
				else {
					cout << "\n" << "  option" << option << " is called  but didnt satisfy the condition \n\n";

					visitedPoints[option - 1] = 1;
				}
				break;
			case 5:
				if (m + 1 <= 7 && n + 2 <= 7 && arr[m + 1][n + 2] == 0)
				{
					m = m + 1;
					n = n + 2;
					out_of_range = false;
					cout << "\n" << " option " << option << " is called \n\n";

				}
				else {
					cout << "\n" << "  option" << option << " is called  but didnt satisfy the condition \n\n";

					visitedPoints[option - 1] = 1;
				}
				break;
			case 6:
				if (m + 1 <= 7 && n - 2 >= 0 && arr[m+1][n-2] == 0)
				{
					m += 1;
					n -= 2;
					out_of_range = false;
					cout << "\n" << " option " << option << " is called \n\n";

				}
				else {
					cout << "\n" << "  option" << option << " is called  but didnt satisfy the condition \n\n";

					visitedPoints[option - 1] = 1;
				}
				break;
			case 7:
				if (m - 1 >= 0 && n + 2 <= 7 && arr[m - 1][n + 2] == 0)
				{
					m -= 1;
					n += 2;
					out_of_range = false;
					cout << "\n" << " option " << option << " is called \n\n";

				}
				else {
					cout << "\n" << "  option" << option << " is called  but didnt satisfy the condition \n\n";

					visitedPoints[option - 1] = 1;
				}
				break;
			case 8:
				if (m - 1 >= 0 && n - 2 >= 0 && arr[m-1][n-2] == 0)
				{
					m = m - 1;
					n = n - 2;
					out_of_range = false;
					cout << "\n" << " option " << option << " is called \n\n";

				}
				else {
					cout << "\n"  << "  option" << option << " is called  but didnt satisfy the condition \n\n";
					visitedPoints[option - 1] = 1;
				}
				break;
			}
			// here we are checking if each and every option is tried so that we dont have an infinite loop.
			bool isEachOptionTried = true;
			for (int i = 0; i < (int) visitedPoints.size(); i++)
			{
				if (visitedPoints[i] == -1) {
					isEachOptionTried = false;
					break;
				}
			}
			if (isEachOptionTried)
			{
				cout << " \nEach option is tried and there is no any possible places to go for the Knight \n\n";
				continueToMove = false; 
				break ;
			}
		}
		/*if (arr[m][n] != 0)
		{ // problem is when this if statement works it does not downgrade the values of m and n 
			cout << "This place has already been visited \n\n";
			return move();
		}*/
		arr[m][n] = counter;
		cout << counter << ". movement is done \n\n";
		counter++; 
	display2(arr);
	
	}
	bool check() {
		if (counter == 64)
		{
			cout << "\nWell Done, You successively visited all squares \n";
			return false;
		}
		else if(continueToMove == false) {
			cout << "\nAfter " << counter << " There is no places left to move \n";
			return false;
		}
		else {
			return true;
		}
	}
	void Go() {
		start();
		do {
			move();
		} while(check());
	}
};
void display2(std::array<std::array<int, colSize>, rowSize>& arr) {

	for (auto const& row : arr)
	{
		for (auto const& element : row)
			std::cout << element << " ";
		cout << "\n";
	}
}

/*Player start() {
	Player game_1;
	// assign the knight a random position 
	//game_1.Initialize();
	//game_1.arr[game_1.m][game_1.n] = 1;
	//display2(arr);
	cout << "\n\n";

	return game_1;
}*/
// void Player::move() {}
/*
void displayChessBoard() {
	cout << "\n\n\n\t\t";
	cout << " ";
	for (int i = 1; i <= 8; i++)
	{
		std::cout << " " << i;
	}
	cout << "\n";
	for (int i = 1; i <= 8; i++)
	{
		cout << "\t\t" << i;
		for (int j = 1; j <= 8; j++)
		{
			cout << "| ";
		}
		cout << "|";
		cout << "\n";
	}
	cout << "\n\n\n";
}*/


int main()
{
	
	Player game_1;
	cout << " !! Welcome to the Knight's Tour Problem !!" << endl;
	cout << "Lets see if the Knight that has L-shaped moves in the chess game can visit each and every square once and only once " << endl;
	game_1.Go();

}
