#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


void showWelcome()
{
	cout << "WELCOME TO OUR PROGRAM!" << endl;
	cout << "To try it, you'll have to enter whole number!" << endl << endl;
}
void Menu()
{
	int choice;
	showWelcome();
	do
	{
		cout << endl
			<< "       MENU      \n" 
			<< "==================\n"
			<< " 1 - Create a user\n"
			<< " 2 - Edit a user\n"
			<< " 4 - Delete a user\n"
			<< " 5 - Exit.\n"
			<< " Enter your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("CLS");
			break;
		case 2:
			system("CLS");
			break;
		case 3:
			system("CLS");
			break;
		case 4:
			system("CLS");
			break;
		case 5:
			cout << "End of Program.\n";
			break;
		default:
			cout << "Not a Valid Choice. \n"
				<< "Choose again.\n";
			break;
		}

	} while (choice != 5);

}
