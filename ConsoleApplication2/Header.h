#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Login.h"
using namespace std;

void adminMenu()
{
	int choice;

		cout << endl
			<< "       MENU      \n"
			<< "==================\n"
			<< " 1 - Create a user\n"
			<< " 2 - Edit a user\n"
			<< " 3 - See list of users\n"
			<< " 4 - Delete a user by id\n"
			<< " 5 - Edit user by id\n"
			<< " 6 - Exit\n"
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
			system("CLS");
			break;
		case 6:
			cout << endl;
			cout << "End of Program.\n";
			break;
		default:
			cout << "Not a Valid Choice. \n"
				<< "Choose again.\n";
			break;
		}


}
void userMenu()
{
	int choice;

	cout << endl
		<< "       MENU      \n"
		<< "==================\n"
		<< " 1 -  \n"
		<< " 2 - \n"
		<< " 3 - \n"
		<< " 3 - Exit\n"
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
		cout << endl;
		cout << "End of Program.\n";
		break;
	default:
		cout << "Not a Valid Choice. \n"
			<< "Choose again.\n";
		break;
	}


}

void showWelcome()
{
	cout << "WELCOME TO OUR PROGRAM!" << endl;
	cout << "To try it, you'll have to enter whole number!" << endl << endl;
}
void mainMenu()
{ 
	string username, userPassword;

	system("CLS");
	int choice;
	showWelcome();

		cout << endl
			<< "       MENU      \n" 
			<< "==================\n"
			<< " 1 - Register admin \n"
			<< " 2 - Login as admin\n"
			<< " 3 - Login as user\n" 
			<< " 4 - Exit\n"
			<< " Enter your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:  
			system("CLS");
			break;
		case 2:
			system("CLS");
			loginAdminSystem(username, userPassword);
			adminMenu();
			break;
		case 3:
			system("CLS");
			//loginUserSystem(username, userPassword);
			userMenu();
			break;
		case 4:
			cout << endl;
			cout << "End of Program.\n";
			break;
		default:
			cout << "Not a Valid Choice. \n"
				<< "Choose again.\n";
			break;
		}



}


