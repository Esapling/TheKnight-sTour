#include "Header.h"

void Player::move() {
	std::uniform_int_distribution<unsigned int > random_option{ 1, 8 };
	int option{ -1 };
	bool out_of_range = true;

	visitedPoints.assign(8, -1); // fill array 9 times with -1
	int last_option_value = -1; // prevents getting the same value for option 
	while (out_of_range)
	{
		while (true)
		{
			option = random_option(myRandomEngine); 
			// randomly select an L shaped move if not possible then select another one 
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
				cout << "\n" << " option " << option << " is called \n\n";
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
			if (m - 2 >= 0 && n + 1 <= 7 && arr[m - 2][n + 1] == 0)
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
			if (m + 1 <= 7 && n - 2 >= 0 && arr[m + 1][n - 2] == 0)
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
			if (m - 1 >= 0 && n - 2 >= 0 && arr[m - 1][n - 2] == 0)
			{
				m = m - 1;
				n = n - 2;
				out_of_range = false;
				cout << "\n" << " option " << option << " is called \n\n";

			}
			else {
				cout << "\n" << "  option" << option << " is called  but didnt satisfy the condition \n\n";
				visitedPoints[option - 1] = 1;
			}
			break;
		}
		// here we are checking if each and every option is tried so that we dont have an infinite loop.
		bool isEachOptionTried = true;
		for (int i = 0; i < (int)visitedPoints.size(); i++)
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
			break;
		}
	}

	arr[m][n] = counter;
	cout << counter << ". movement is done \n\n";
	counter++;
	display2(arr);

}

