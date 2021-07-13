#include <iostream>
#include <string>
using namespace std;
bool option1Check = false;
struct USER_DATA
{
	string userName;
	string password;
	int id = 1;
	string firstName;
	string lastName;
	string address;
	string childName;
	int yearOfChild;
};

void createUser(USER_DATA* user, int& userCount, USER_DATA newOrder, int& maxId) {
	newOrder.id = maxId;
	user[userCount] = newOrder;
	userCount++;
	maxId++;
}

int getUserById(USER_DATA* user, int& userCount, int id)
{
	for (int i = 0; i < userCount; i++)
	{
		if (user[i].id == id)
		{
			return i;
		}
	}

	return -1;
}
void updateUser(USER_DATA* user, int& userCount, USER_DATA newUser, int& maxId)
{
	int index = getUserById(user, userCount, maxId);
	user[index] = newUser;
}

void deleteUser(USER_DATA* user, int& userCount, int id) {

	int index = getUserById(user, userCount, id);
	for (int i = index; i < userCount - 1; i++)
	{
		user[i] = user[i + 1];
	}
	userCount--;

}
USER_DATA getOrder(USER_DATA* user, int& userCount, int id)
{
	int index = getUserById(user, userCount, id);
	if (index != id)
	{
		cout << "Enter valid ID";
		cin >> index;
	}
	return user[index];
}


void showUser(USER_DATA* user, int& userCount, int& maxId)
{
	cout << "\n List of users: " << endl;
	for (int i = 0; i < userCount; i++)
	{
		cout << "User First name: " << user[i].firstName << endl;
		cout << "User Last name: " << user[i].lastName << endl;
		cout << "User address: " << user[i].address << endl;
		cout << "User id: " << user[i].id << endl;
		cout << "User child's name: " << user[i].childName << endl;
		cout << "Year of child: " << user[i].yearOfChild << endl;
	}
}

void inputUserData(USER_DATA* user, int& userCount, int& maxId) {
	USER_DATA uSer;

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
	createUser(user, userCount, uSer, maxId);
}
void editUser(USER_DATA* user, int& userCount) {
	int userId;
	cout << "\nEnter user ID: ";
	cin >> userId;

	USER_DATA users = getOrder(user, userCount, userId);

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
		cin >> user->firstName;
		updateUser(user, userCount, users, userId);
		break;
	}
	case 2: {
		cout << "Last name: ";
		cin >> user->lastName;
		updateUser(user, userCount, users, userId);
		break;
	}
	case 3: {
		cout << "Address: ";
		cin >> user->address;
		updateUser(user, userCount, users, userId);
		break;
	}
	case 4: {
		cout << "Child name: ";
		cin >> user->childName;
		updateUser(user, userCount, users, userId);
		break;
	}
	case 5: {
		cout << "Year of child: ";
		cin >> user->yearOfChild;
		updateUser(user, userCount, users, userId);
		break;
	}
	default: {
		cout << "Invalid field!" << endl;
		break;
	}
	}
}
void deleteUserId(USER_DATA* user, int& userCount, int& maxId) {
	int userId;

	cout << "Enter user Id: ";
	cin >> userId;

	deleteUser(user, userCount, userId);
}
void loginAdminSystem(string adminName, string adminPassword)
{
	int loginAttempt = 0;
	while (loginAttempt < 2)
	{
		cout << "Please enter your admiName: ";
		cin >> adminName;
		cout << "Please enter your user password: ";
		cin >> adminPassword;

		if (adminName == "Admin" && adminPassword == "admin123")
		{
			cout << "Welcome Admin!\n";
			break;
		}
		else
		{
			cout << "Invalid login attempt. Please try again.\n" << '\n';
			loginAttempt++;
		}
	}
	if (loginAttempt == 2) {
		cout << "Too many login attempts! The program will now terminate.";
	}
	cout << endl;
	cout << "Thank you for logging in.\n";

}
void loginUserSystem(string usName, string userPassword)
{
	int loginAttempt = 0;
	while (loginAttempt < 2)
	{
		cout << "Please enter your user name: ";
		cin >> usName;
		cout << "Please enter your user password: ";
		cin >> userPassword;

		if (usName == "User" && userPassword == "user123")
		{
			cout << "Welcome User!\n";
			break;
		}
		else
		{
			cout << "Invalid login attempt. Please try again.\n" << '\n';
			loginAttempt++;
		}
	}
	if (loginAttempt == 2) {
		cout << "Too many login attempts! The program will now terminate.";
	}
	cout << "Thank you for logging in.\n";
	cout << endl;
}
void adminMenu(USER_DATA* user, int& userCount, USER_DATA newOrder, int& maxId, int id)
{
	int choice;
	cout << endl
		<< "       MENU      \n"
		<< "==================\n"
		<< " 1 - Create a user\n"
		<< " 2 - Edit a user\n"
		<< " 3 - See list of users\n"
		<< " 4 - Delete a user by id\n"
		<< " 5 - Exit\n"
		<< " Enter your choice : ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		system("CLS");
		inputUserData(user, userCount, maxId);
		adminMenu(user, userCount, newOrder, maxId, id);
		break;
	case 2:
		system("CLS");
		editUser(user, userCount);
		adminMenu(user, userCount, newOrder, maxId, id);
		break;
	case 3:
		system("CLS");
		showUser(user, userCount, maxId);
		adminMenu(user, userCount, newOrder, maxId, id);
		break;
	case 4:
		system("CLS");
		deleteUserId(user, userCount, id);
		adminMenu(user, userCount, newOrder, maxId, id);
		break;
	case 5:
		cout << endl;
		cout << "End of Program.\n";
		break;
	default:
		cout << "Not a Valid Choice. \n"
			<< "Choose again.\n";
		break;
	}


}
void userMenu(USER_DATA* user, int& userCount, int& maxId, USER_DATA newOrder)
{
	int choice;

	cout << endl
		<< "       MENU      \n"
		<< "==================\n"
		<< " 1 - View created list of children \n"
		<< " 2 - Create a user"
		<< " 3 - Exit\n"
		<< " Enter your choice : ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		system("CLS");
		showUser(user, userCount, maxId);
		userMenu(user, userCount, maxId, newOrder);
		break;
	case 2:
		system("CLS");
		inputUserData(user, userCount, maxId);
		userMenu(user, userCount, maxId, newOrder);
		break;

	case 3:
		cout << endl;
		cout << "End of Program.\n";
		break;
	default:
		cout << "Not a Valid Choice. \n"
			<< "Choose again.\n";
		break;
	}


}
bool showMainMenu(USER_DATA* user, int& userCount, int& maxId, USER_DATA newOrder, int id)
{

	int choice;
	string adminName;
	string adminPassword;
	string usName;
	string userPassword;
	cout << "\n===MAIN MENU===" << endl;
	cout << "1. Login as admin" << endl;
	cout << "2. Login as user" << endl;
	cout << "9. Exit" << endl;
	cout << "Your choice: ";

	cin >> choice;

	switch (choice) {
	case 1: {
		system("CLS");
		loginAdminSystem(adminName, adminPassword);
		adminMenu(user, userCount, newOrder, maxId, id);
		break;
	}
	case 2: {
		system("CLS");
		loginUserSystem(usName, userPassword);
		userMenu(user, userCount, maxId, newOrder);
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
	int maxId = 0;
	USER_DATA user[500];
	USER_DATA newOrder;
	int id = 0;
	bool mainMenu;

	do {
		mainMenu = showMainMenu(user, userCount, maxId, newOrder, id);
	} while (mainMenu);
}