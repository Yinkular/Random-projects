// THe program groups teams together randomly in a standard vs format

// 1 indexing used

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

typedef pair<string, string> vs;

int main()
{
	srand(time(NULL));

	int number_of_teams;

	cout << "Enter number of teams" << endl;
	cin >> number_of_teams;

	vector<string> teamNames(number_of_teams+1);

	cout << "Enter team names" << endl;

	// get team names
	for (int i = 1; i<=number_of_teams; i++)
	{
		cout << "Team" << i << endl;
		cin >> teamNames[i];
	}

	vector<int> randomPairing(number_of_teams+1);
	vector<bool> check(number_of_teams+1,false);

	int random_number;
	// generate random numbers
	// make sure they are unique
	for (int i = 1; i <= number_of_teams; i++)
	{
		random_number = rand() % number_of_teams + 1;

		while (check[random_number])
		{
			random_number = rand() % number_of_teams + 1;
		}

		randomPairing[i] = random_number;
		check[random_number] = true;
	}

	int mid = number_of_teams / 2;
	
	vector<vs> matchUp((number_of_teams / 2)+1);
	int count = 1;

	// create pairs of teams to face each other
	for (int i = 1; i < number_of_teams; i+=2)
	{
		matchUp[count] = { teamNames[randomPairing[i]], teamNames[randomPairing[i+1]]};
		count++;
	}

	// print out the teams facing each other
	for (int i = 1; i <=mid; i++)
	{
		cout << matchUp[i].first << " Vs " << matchUp[i].second << endl;
	}

	system("pause");
	return 0;
}