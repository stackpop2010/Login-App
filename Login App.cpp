// Login App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool IsLoggedIn()
{
    string username, password, un, pw;

    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else {
        return false;
    }
}



int main()
{
    int choice;

    cout << "1: Register\n2: Login\n3: Recover password\nYour choice: "; cin >> choice;
    if (choice == 1) {
        string username, password, secret;
        cout << "Select a username: "; cin >> username;
        cout << "Select a password: "; cin >> password;
        cout << "In case you forget your password, let's set a recovery qustion. What's your favorite animal? "; cin >> secret;

        ofstream file;
        file.open(username + ".txt");

        file << username << endl << password << endl << secret;
        file.close();

        main();

    }
    else if (choice == 2) {
        bool status = IsLoggedIn();
        if (!status)
        {
            cout << "False Login!" << endl;
            main();
        }
        else {
            cout << "Succesfully logged in!" << endl;
            system("PAUSE");
            return 1;
        }

    }

    else if (choice == 3) {
        string UN, un, pw, sc, sc_input, pw2;
        cout << "What is your username? "; cin >> UN;
        ifstream read(UN + ".txt");
        getline(read, un);
        getline(read, pw);
        getline(read, sc);

        cout << "What is your favorite animal? "; cin >> sc_input;

        if (sc == sc_input) {
            cout << "Input new password "; cin >> pw2;
            cout << "New password saved." << endl;
            ofstream file2;
            file2.open(UN + ".txt");
            file2 << UN << endl << pw2 << endl << sc_input;
            file2.close();

            main();
        }

        else {
            cout << "Invalid input, try again" << endl;
            main();
        }
    
    }

    else {
        cout << "Invalid entry, try again.";
        main();

    }
   
}

