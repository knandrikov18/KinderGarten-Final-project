#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void accessCheck()
{
	while ()
	{
		if ()
		{

		}
		else
		{

		}
	}

}

int Menu()
{
	char selection;
	cout << "\n Menu";
	cout << "\n========";
	cout << "\n 1. Create user";
	cout << "\n 2. Edit user";
	cout << "\n 3. Delete user";
	cout << "\n 4. Exit";
	cout << "\n Enter selection: ";

	cin >> selection;
	switch (selection)
	{

	case 1: {cout << "\n To create a user\n"; }

		  break;

	case 2: {cout << "\n To edit a user"; }
		  break;

	case 3: {cout << "\n To delete"; }
		  break;

	case 4: {cout << "\n To exit the menu"; }

		  break;
	default: cout << "\n Invalid selection";

	}
	cout << "\n";
	return 0;
}