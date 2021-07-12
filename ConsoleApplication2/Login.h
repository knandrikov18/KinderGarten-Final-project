#pragma once
#include <string>
#include <iostream>
using namespace std;
void registerUser(string name, string regPassword)
{

    cout << "Enter user name: ";
    cin >> name;
    cout << "Enter user password: ";
    cin >> regPassword;
}
void loginAdminSystem(string username, string userPassword)
{
    int loginAttempt = 0;
    while (loginAttempt < 2)
    {
        cout << "Please enter your user name: ";
        cin >> username;
        cout << "Please enter your user password: ";
        cin >> userPassword;

      if (username == "Admin" && userPassword == "admin123")
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

void loginUserSystem(string username, string userPassword)
{
    int loginAttempt = 0;
    while (loginAttempt < 2)
    {
        cout << "Please enter your user name: ";
        cin >> username;
        cout << "Please enter your user password: ";
        cin >> userPassword;

        if (username == "User" && userPassword == "user123")
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