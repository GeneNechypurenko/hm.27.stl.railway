#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>

#include "AIRS.h"

using namespace std;

int main()
{
	AIRS airs;

	vector<AIRS>trains;

	string filename = "save.bin";

	try
	{
		airs.load(filename, trains);
	}
	catch (const char* error)
	{
		cout << endl << error << endl << endl;
	}

	system("pause");

	int select = 0;

	const char* menu[] = { "1. Add", "2. Print", "3. Exit" };

	while (true)
	{
		system("cls");

		for (int i = 0; i < 3; i++)
		{
			cout << menu[i] << endl;
		}

		select = _getch();

		switch (select)
		{
		case '1':

			system("cls");
			airs.add(trains);
			system("pause");

			break;

		case '2':

			system("cls");
			airs.show(trains);
			system("pause");

			break;

		case '3':

			system("cls");
			try
			{
				airs.save(filename, trains);
			}
			catch (const char* error)
			{
				cout << endl << error << endl << endl;
			}
			system("pause");

			return 0;
		}
	}
	return 0;
}