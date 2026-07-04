#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser()
{
    string username, password;

    cout << "\n===== REGISTRATION =====\n";

    cout << "Enter Username: ";
    cin >> username;

    ifstream checkFile("users.txt");

    string u, p;
    bool exists = false;

    while(checkFile >> u >> p)
    {
        if(u == username)
        {
            exists = true;
            break;
        }
    }

    checkFile.close();

    if(exists)
    {
        cout << "\nUsername already exists!\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    if(password.length() < 4)
    {
        cout << "\nPassword must be at least 4 characters long!\n";
        return;
    }

    ofstream file("users.txt", ios::app);

    if(!file)
    {
        cout << "\nError opening users.txt!\n";
        return;
    }

    file << username << " " << password << endl;

    file.close();

    cout << "\nRegistration Successful!\n";
    cout << "Welcome, " << username << "!\n";
}

void loginUser()
{
    string username, password;

    cout << "\n===== LOGIN =====\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    if(password.length() < 4)
    {
        cout << "\nPassword must be at least 4 characters long!\n";
        return;
    }

    ifstream file("users.txt");

    if(!file)
    {
        cout << "\nNo registered users found!\n";
        return;
    }

    string u, p;
    bool found = false;

    while(file >> u >> p)
    {
        if(u == username && p == password)
        {
            found = true;
            break;
        }
    }

    file.close();

    if(found)
    {
        cout << "\nLogin Successful!\n";
        cout << "Welcome back, " << username << "!\n";
    }
    else
    {
        cout << "\nInvalid Username or Password!\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n================================\n";
        cout << "          LOGIN SYSTEM\n";
        cout << "================================\n";
        cout << "1. Registration\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "\nThank you for using the Login System.\n";
                cout << "Goodbye!\n";
                break;

            default:
                cout << "\nInvalid Choice! Please try again.\n";
        }

    } while(choice != 3);

    return 0;
}
