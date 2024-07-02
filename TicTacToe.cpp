#include <iostream>
#include <ctime>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

int indexOf(string arr[], int len, string item)
{
	for (int j = 0; j < len; j++)
	{
		if (item == arr[j])
		{
			return j;
		}
	}
	return -1;
}

vector<string> removeItem(string arr[], int len, string item)
{
	vector<string> final;
	for (int j = 0; j < len; j++)
	{
		if (item != arr[j])
		{
			final.push_back(arr[j]);
		}
	}
	return final;
}

void doIt(string dt_[], int len)
{
	vector<string> dt(dt_, dt_ + len); // Convert array to vector

	bool whl = true;
	while (whl)
	{
		string input;
		cout << "Your turn::: ";
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::toupper);
		int ind = indexOf(dt.data(), dt.size(), input);
		if (ind == -1)
		{
			cout << "Try again!\n";
			cout << "Your turn::: ";
			cin >> input;
			transform(input.begin(), input.end(), input.begin(), ::toupper);
			ind = indexOf(dt.data(), dt.size(), input);
			if (ind == -1)
			{
				cout << "Exiting due to two wrong tries";
				exit(0);
			}
		}
		cout << input << " occupied\n";
		dt = removeItem(dt.data(), dt.size(), input); // Update dt using removeItem
		srand(time(NULL));
		int random = rand();
		cout << random<<"\n";
		random=random%(sizeof(dt)/sizeof (dt[0]));
		cout << random;
		string dta=dt[random];
		dt = removeItem(dt.data(), dt.size(), dta);
		cout << "Robot occupied " << dta <<"\n";
		cout << "FOLLOWING ARE LEFT:-\n";
		for (const string &jk : dt)
		{
			cout << jk << "\n";
		}
		if (dt.empty())
		{ // Check if dt is empty
			whl = false;
		}
	}
}

int main(int argc, char *argv[])
{
	cout << "      ||||||| •• TIC TAC TOE BY AMAN ADLAKHA •• |||||||\n";
	cout << "THE INDEX OF THE GAMEBOARD ARE:-\n";
	cout << "|T1| |T2| |T3|\n";
	cout << "|M1| |M2| |M3|\n";
	cout << "|B1| |B2| |B3|\n";

	string data[9] = {"T1", "T2", "T3", "M1", "M2", "M3", "B1", "B2", "B3"};

	doIt(data, 9);

	return 0;
}