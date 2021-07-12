#pragma once
#include <iostream>
#include <string>
#include "Login.h"
#include "Header.h"
using namespace std;
void mainMenu()
{
	string username, userPassword;

	system("CLS");
	int choice;
	showWelcome();
	cout << endl
		<< "       MENU      \n"
		<< "==================\n"
		<< " 1 - Register user \n"
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
		loginUserSystem(username, userPassword);
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