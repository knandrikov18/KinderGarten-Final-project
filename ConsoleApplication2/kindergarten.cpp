#include <iostream>
#include <string>
#include <vector>
#include "Header.h"
#include "Login.h"
using namespace std;
struct USER_DATA
{
	string userName;
	string password;
	int id;
	string firstName;
	string lastName;
	string address;
	string childName;
	int yearOfChild;
};
void InsertData(USER_DATA* user)
{
	cout << "Username: ";
	cin >> user->userName;
	cout << endl;
	cout << "Password: ";
	cin >> user->password;
	cout << endl;
	cout << "Enter id: ";
	cin >> user->id;
	cout << endl;
	cout << "Enter first name: ";
	cin >> user->firstName;
	cout << endl;
	cout << "Enter last name: ";
	cin >> user->lastName;
	cout << endl;
	cout << "Enter address: ";
	cin >> user->address;
	cout << endl;
	cout << "Enter child name: ";
	cin >> user->childName;
	cout << endl;
	cout << "Enter child age: ";
	cin >> user->yearOfChild;
	cout << endl;

}

int main()
{
  
	Menu();

}
 