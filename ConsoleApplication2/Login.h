#pragma once
#include <string>
#include <iostream>
using namespace std;
void loginSystem(string lname, string lpassword)
{
	cout << "Login Name: ";
	cin >> lname;
	cout << "Login Password: ";
	cin >> lpassword;
	if (lname == "vip3r" && lpassword == "4lif3")
	{
		cout << "Welcome," << ' ' << lname << "!" << '\n';

	}
	else
	{
		cout << "Bad Login Name/Password" << '\n';

	}

	cin.get();

	cout << "correct password";
}