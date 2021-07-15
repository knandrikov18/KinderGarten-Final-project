#include <iostream>
#include <string>
using namespace std;
struct USER_DATA
{
	string username;
	string password;
	int id;
	string firstName;
	string lastName;
	string address;
	string childName;
	int yearOfChild;
};

// Checks if Admin username and password are correct
bool checkLogInAdmin(string UserName, string pass) 
{
	string admin = "admin";
	string adminPass = "adminpass";
	if (UserName == admin and adminPass == pass)
	{
		cout << "Welcome, admin!\nAccess Granted!" << endl;
		return true;
	}
}

// Keeps user's data in a structure of arrays
void createUser(USER_DATA* users, int userCounter, USER_DATA newOrder, int maxId) {
	newOrder.id = maxId;
	users[userCounter] = newOrder;
}

// Creates id for every user
int getUserId(USER_DATA* user, int& userCounter, int id)
{
	for (int i = 0; i < userCounter; i++)
	{
		if (user[i].id == id)
		{
			return i;
		}
	}

	return -1;
}

// Updates user's data
void updateUser(USER_DATA* user, int& userCounter, USER_DATA newUser, int& maxId)
{
	int index = getUserId(user, userCounter, maxId);
	user[index] = newUser;
}

// Deletes user's data by their ID
void deleteUser(USER_DATA* user, int& userCounter, int id) {

	int index = getUserId(user, userCounter, id);
	for (int i = index; i < userCounter - 1; i++)
	{
		user[i] = user[i + 1];
	}
	userCounter--;
	system("CLS");
	cout << "User has been deleted successfully!" << endl;
}


USER_DATA getOrder(USER_DATA* user, int& userCounter, int id)
{
	int index = getUserId(user, userCounter, id);

	return user[index];
}

// Checks if the created id is identical with the written id
bool checkIfIdIsValid(USER_DATA* user, int& userCounter, int Id)
{
	int index = getUserId(user, userCounter, Id);
	if (index == -1)
	{
		cout << "Enter valid ID: ";
		return false;
	}
	else
	{
		return true;
	}
}

// Shows all user's data that has been inputted
void showUserMenu(USER_DATA* user, int& userCounter, int& maxId)
{
	cout << "\nList of users: " << endl;
	for (int i = 0; i < userCounter; i++)
	{
		cout << "User's id: " << user[i].id << endl;
		cout << "User's First name: " << user[i].firstName << endl;
		cout << "User's Last name: " << user[i].lastName << endl;
		cout << "User's address: " << user[i].address << endl;
		cout << "User's child's name: " << user[i].childName << endl;
		cout << "Year of child: " << user[i].yearOfChild << endl;
		cout << endl;
	}
}

// Shows all user's data by last name
int getUserByLastName(USER_DATA* users,int& userCounter)
{
	string lastName;
	cout << "Enter Last Name: ";
	cin >> lastName;
	for (int i = 0; i < userCounter; i++)
	{
		if (users[i].lastName == lastName)
		{
			cout << "User's id: " << users[i].id << endl;;
			cout << "User's Username: " << users[i].username<< endl;
			cout << "User's Password: " << users[i].password<< endl;
			cout << "User's First name: " << users[i].firstName<< endl;
			cout << "User's Last Name: " << users[i].lastName<< endl;
			cout << "User's Address: " << users[i].address<< endl;
			cout << "User's Child Name: " << users[i].childName<< endl;
			cout << "User's Year of child: " << users[i].yearOfChild<< endl;
		}
	}
	return -1;
}

// Shows all user's data by Child's name
int getUserByChildName(USER_DATA* users, int& userCounter)
{
	string childName;
	cout << "Enter Child Name: ";
	cin >> childName;
	for (int i = 0; i < userCounter; i++)
	{
		if (users[i].childName == childName)
		{
			cout << "User's id: " << users[i].id << endl;;
			cout << "User's Username: " << users[i].username << endl;
			cout << "User's Password: " << users[i].password << endl;
			cout << "User's First name: " << users[i].firstName << endl;
			cout << "User's Last Name: " << users[i].lastName << endl;
			cout << "User's Address: " << users[i].address << endl;
			cout << "User's Child Name: " << users[i].childName << endl;
			cout << "User's Year of child: " << users[i].yearOfChild << endl;
		}
	}
	return -1;
}

// Inputs user's data
void userMenu(USER_DATA* user, int& userCounter, int& maxId) {
	USER_DATA uSer;

	cout << "Username: ";
	cin >> uSer.username;

	cout << "Password: ";
	cin >> uSer.password;

	cout << "Enter first name: ";
	cin >> uSer.firstName;
	cout << endl;
	cout << "Enter last name: ";
	cin >> uSer.lastName;
	cout << endl;
	cout << "Enter address: ";
	cin >> uSer.address;
	cout << endl;
	cout << "Enter child name: ";
	cin >> uSer.childName;
	cout << endl;
	cout << "Enter child age: ";
	while (!(cin >> uSer.yearOfChild) or uSer.yearOfChild > 5)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\nEnter correct Year: ";
	}
	createUser(user, userCounter, uSer, maxId);
	userCounter++;
	maxId++;
}

// Edits user's data by their id
void editUser(USER_DATA* user, int& userCounter) {
	int userId;
	cout << "\nEnter user ID: ";
	cin >> userId;
	bool a = checkIfIdIsValid(user, userCounter, userId);
	if (a == false)
	{
		cin >> userId;
	}
	USER_DATA users = getOrder(user, userCounter, userId);

	cout << "\n1. First name: " << endl;
	cout << "2. Last name: " << endl;
	cout << "3. Adress: " << endl;
	cout << "4. Child name: " << endl;
	cout << "5. Child age : " << endl;
	cout << "Which field you want to edit: ";

	int edit;
	cin >> edit;

	switch (edit) {
	case 1: {
		cout << "First name: ";
		cin >> users.firstName;
		updateUser(user, userCounter, users, userId);
		break;
	}
	case 2: {
		cout << "Last name: ";
		cin >> users.lastName;
		updateUser(user, userCounter, users, userId);
		break;
	}
	case 3: {
		cout << "Address: ";
		cin >> users.address;
		updateUser(user, userCounter, users, userId);
		break;
	}
	case 4: {
		cout << "Child name: ";
		cin >> users.childName;
		updateUser(user, userCounter, users, userId);
		break;
	}
	case 5: {
		cout << "Year of child: ";
		cin >> users.yearOfChild;
		updateUser(user, userCounter, users, userId);
		break;
	}
	default: {
		cout << "Invalid field!" << endl;
		break;
	}
	}
}

// Deletes user's data by typing it's id
void deleteUserId(USER_DATA* user, int& userCounter, int& maxId) {
	int userId;

	cout << "Enter user Id: ";
	cin >> userId;

	deleteUser(user, userCounter, userId);
}

// MAIN MENU
bool showMainMenu(USER_DATA* user, int& userCounter, int& maxId)
{

	int choice;
	string adminName;
	string adminPassword;
	string usName;
	string userPassword;
	cout << "\n===MAIN MENU===" << endl;
	cout << "1. User Menu" << endl;
	cout << "2. Show Users" << endl;
	cout << "3. Edit User Order" << endl;
	cout << "4. Delete User Order" << endl;
	cout << "5. Get User By Parent Last Name" << endl;
	cout << "6. Get User By Child Name" << endl;
	cout << "9. Exit" << endl;
	cout << "Your choice: ";

	cin >> choice;

	switch (choice) {
	case 1: {
		system("CLS");
		userMenu(user, userCounter, maxId);
		break;
	}
	case 2: {
		system("CLS");
		showUserMenu(user, userCounter, maxId);
		break;
	}
	case 3: {
		system("CLS");
		editUser(user, userCounter);
		break;
	}
	case 4: {
		system("CLS");
		deleteUserId(user, userCounter, maxId);
		break;
	}
	case 5:
	{
		system("CLS");
		getUserByLastName(user, userCounter);
		break;
	}
	case 6:
	{
		system("CLS");
		getUserByChildName(user, userCounter);
		break;
	}
	case 9: {
		return false;
	}
	}
}

int main()
{
	cout << "WELCOME TO OUR PROGRAM!" << endl;
	cout << "To try it, you'll have to enter whole number!" << endl << endl;
	int userCount = 0;
	int maxId = 1;
	USER_DATA user[10];

	bool mainMenu = true;
	string admin;
	string adminpass;
	cout << "Insert Username: ";
	while (!(cin >> admin) or admin != "admin")
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\nEnter correct adminusername: ";
	}
	cout << "Insert Password: ";
	while (!(cin >> adminpass) or adminpass != "adminpass")
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\nEnter correct adminpass: ";
	}
	bool isAdmina = checkLogInAdmin(admin, adminpass);
	if (isAdmina == true)
	{
		do {
			mainMenu = showMainMenu(user, userCount, maxId);
		} while (mainMenu);
	}
}