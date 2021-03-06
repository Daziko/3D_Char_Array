#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

int main()
{
	string line;
	ifstream infile;
	string dataarray[5][2];
	char charArray[5][2][12];
	int orderArray[5] = { 0, 1, 2, 3, 4 };

	infile.open("file.txt");

	size_t group = 0;
	size_t member = 0;
	size_t lineCharacter = 0;

	while (infile.eof() == false) 
	{
		getline(infile, line); 

		if (line == "")
		{
			group++;
			member = 0;
			continue;
		}

		dataarray[group][member] = line;

		for (size_t i = 0; i < line.length(); i++)
		{
			charArray[group][member][lineCharacter] = line[i];
			lineCharacter++;
		}

		lineCharacter = 0;
		member++;

	}
	infile.close();
	random_device rd; // obtain a random number from hardware
	mt19937 eng(rd()); // seed the generator

	shuffle(begin(orderArray), end(orderArray), eng);

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t memberIndex = 0; memberIndex < 2; memberIndex++)
		{
			for (size_t lineIndex = 0; lineIndex < 12; lineIndex++)
			{
				char actualCharacter = charArray[orderArray[i]][memberIndex][lineIndex];

				if (static_cast<int>(actualCharacter) != -52)
				{
					cout << actualCharacter;
				}				
			}

			cout << '\n';
		}
		cout << '\n';
	}

	cin.get();
    return 0;
}



