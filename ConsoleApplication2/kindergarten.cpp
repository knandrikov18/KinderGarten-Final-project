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
bool isAdmin(string UserName, string pass)
{
	string admin = "admin";
	string adminPass = "adminpass";
	if (UserName == admin and adminPass == pass)
	{
		cout << "Welcome, admin!\nAccess Granted!" << endl;
		return true;
	}
}
void createUser(USER_DATA* user, int& userCount, USER_DATA newOrder, int& maxId) {
	newOrder.id = maxId;
	user[userCount] = newOrder;
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
bool checkIsIdValid(USER_DATA* user, int& userCount, int Id)
{
	int index = getUserById(user, userCount, Id);
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

void showUserMenu(USER_DATA* user, int& userCount, int& maxId)
{
	cout << "\n List of users: " << endl;
	for (int i = 0; i < userCount; i++)
	{
		cout << "User's First name: " << user[i].firstName << endl;
		cout << "User's Last name: " << user[i].lastName << endl;
		cout << "User's address: " << user[i].address << endl;
		cout << "User's id: " << user[i].id << endl;
		cout << "User's child's name: " << user[i].childName << endl;
		cout << "Year of child: " << user[i].yearOfChild << endl;
		cout << endl;
	}
}

int getUserByLastName(USER_DATA* users,int& userCount)
{
	string lastName;
	cout << "Enter Last Name: ";
	cin >> lastName;
	for (int i = 0; i < userCount; i++)
	{
		if (users[i].lastName == lastName)
		{
			cout << "Customer's id: " << users[i].id << endl;;
			cout << "Customer's Username: " << users[i].username<< endl;
			cout << "Customer's Password: " << users[i].password<< endl;
			cout << "Customer's First name: " << users[i].firstName<< endl;
			cout << "Customer's Last Name: " << users[i].lastName<< endl;
			cout << "Customer's Address: " << users[i].address<< endl;
			cout << "Customer's Child Name: " << users[i].childName<< endl;
			cout << "Customer's Year of child: " << users[i].yearOfChild<< endl;
		}
	}
	return -1;
}

int getUserByChildName(USER_DATA* users, int& userCount)
{
	string childName;
	cout << "Enter Last Name: ";
	cin >> childName;
	for (int i = 0; i < userCount; i++)
	{
		if (users[i].childName == childName)
		{
			cout << "Customer's id: " << users[i].id << endl;;
			cout << "Customer's Username: " << users[i].username << endl;
			cout << "Customer's Password: " << users[i].password << endl;
			cout << "Customer's First name: " << users[i].firstName << endl;
			cout << "Customer's Last Name: " << users[i].lastName << endl;
			cout << "Customer's Address: " << users[i].address << endl;
			cout << "Customer's Child Name: " << users[i].childName << endl;
			cout << "Customer's Year of child: " << users[i].yearOfChild << endl;
		}
	}
	return -1;
}



void userMenu(USER_DATA* user, int& userCount, int& maxId) {
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
	cin >> uSer.yearOfChild;
	cout << "Year of Child: ";
	while (!(cin >> uSer.yearOfChild) or uSer.yearOfChild < 6)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\nEnter correct Year: ";
	}
	createUser(user, userCount, uSer, maxId);
	userCount++;
	maxId++;
}
void editUser(USER_DATA* user, int& userCount) {
	int userId;
	cout << "\nEnter user ID: ";
	cin >> userId;
	bool a = checkIsIdValid(user, userCount, userId);
	if (a == false)
	{
		cin >> userId;
	}
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
		cin >> users.firstName;
		updateUser(user, userCount, users, userId);
		break;
	}
	case 2: {
		cout << "Last name: ";
		cin >> users.lastName;
		updateUser(user, userCount, users, userId);
		break;
	}
	case 3: {
		cout << "Address: ";
		cin >> users.address;
		updateUser(user, userCount, users, userId);
		break;
	}
	case 4: {
		cout << "Child name: ";
		cin >> users.childName;
		updateUser(user, userCount, users, userId);
		break;
	}
	case 5: {
		cout << "Year of child: ";
		cin >> users.yearOfChild;
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

bool showMainMenu(USER_DATA* user, int& userCount, int& maxId)
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
		userMenu(user, userCount, maxId);
		break;
	}
	case 2: {
		showUserMenu(user, userCount, maxId);
		break;
	}
	case 3: {
		editUser(user, userCount);
		break;
	}
	case 4: {
		deleteUserId(user, userCount, maxId);
		break;
	}
	case 5:
	{
		getUserByLastName(user, userCount);
		break;
	}
	case 6:
	{
		getUserByChildName(user, userCount);
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
	bool isAdmina = isAdmin(admin, adminpass);
	if (isAdmina == true)
	{
		do {
			mainMenu = showMainMenu(user, userCount, maxId);
		} while (mainMenu);
	}
}