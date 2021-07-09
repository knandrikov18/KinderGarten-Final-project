#pragma once
#include <string>
#include <iostream>
using namespace std;
bool registerUser()
{
}
bool loginAdminSystem(string username, string userPassword)
{
    int loginAttempt = 0;
    while (loginAttempt < 5)
    {
        cout << "Please enter your user name: ";
        cin >> username;
        cout << "Please enter your user password: ";
        cin >> userPassword;

      if (username == "Admin" && userPassword == "admin123")
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
    if (loginAttempt == 5) {
        cout << "Too many login attempts! The program will now terminate.";
   }
    return 0;
    cout << "Thank you for logging in.\n";
    cout << endl;
}

//bool loginUserSystem(string username, string userPassword)
//{
//    int loginAttempt = 0;
//    while (loginAttempt < 5)
//    {
//        cout << "Please enter your user name: ";
//        cin >> username;
//        cout << "Please enter your user password: ";
//        cin >> userPassword;
//
//        if (username == "User" && userPassword == "user123")
//        {
//            cout << "Welcome User!\n";
//            break;
//        }
//        else
//        {
//            cout << "Invalid login attempt. Please try again.\n" << '\n';
//            loginAttempt++;
//        }
//    }
//    if (loginAttempt == 5) {
//        cout << "Too many login attempts! The program will now terminate.";
//    }
//    return 0;
//    cout << "Thank you for logging in.\n";
//    cout << endl;
//}