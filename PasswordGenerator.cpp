/*
Kyiem Chandler
10/21/2021
Password Generator
Creating a program that can generate a password for your needs whether it be with only numbers, only letters
only special characters or a mix of all of them.
*/ 

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

using namespace std;
static int pl = 0;
//Try to create global/static variables to transfer customer needs into the generate pass function

//Get the users requirements for the password
int Needs();
int generatePass(int Needs());
//int optionsArray(response);

int main()
{
    int numChar;
    //get user to give you a minimum number of characters for the password
    cout << "Minimum number of characters: ";
    cin >> numChar;
    pl = numChar;
    cout << pl;
    Needs();
    generatePass(Needs(),pl);

    return 0;
}



int Needs()
{
    string needChar;
    string needNum;
    string needSpecChar;
    int response = 0;


    // Ask does it need user if password needs characters
    cout << "Does password need letters? (yes or no): ";
    cin >> needChar;
    if(needChar == "yes" || needChar == "Yes")
    {
        response = response + 1;
    }

    //Ask does user need numbers in password
    cout << "Does user need numbers (yes or no): ";
    cin >> needNum;
    if(needNum == "Yes" || needNum == "yes")
    {
        response = response + 2;
    }
    //Ask the user if password needs special characters
    cout << "Does password need special characters? (yes or no): ";
    cin >> needSpecChar;
    if(needSpecChar == "Yes" || needSpecChar == "yes")
    {
        response = response + 3;
    }
    system("clear");
    cout << "Minimum numbers: " << numChar << endl;
    cout << "Needs letters: " << needChar << endl;
    cout << "Needs special characters: " << needSpecChar << endl;

    return response;
}


// Creates the password based off of the needs
int generatePass(int Needs(),int pl)
{
    string numbers[] = "0123456789";
    string letters[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
    string chracters[] = "!@#$%&=";

    string password;

    while(strlen(password) < pl)
    {
        //Only needs letters in password
        if (response == 1)
        {
            int letter = rand() % letters[];
        }
        //only needs numbers
        if (response == 2)
        {
            int letter = rand() % letters[];
        }
        //needs letters and numbers
        if (response == 3)
        {   

            int number = rand() % letter[];
        }
        //Needs letters numbers and special characters
        if (response == 6)
        {
            int sc = (rand() % letter[]);
        }
    }
    return password;
}

//int optionsArray(response)
