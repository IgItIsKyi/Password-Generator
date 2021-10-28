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
#include <string>
#define LETTERS 52
#define NUMBERS 10
#define SCHARACTERS 8

using namespace std;
static int pl = 0;
static int response = 0;
//Try to create global/static variables to transfer customer needs into the generate pass function

//Get the users requirements for the password
int Needs();
string generatePass(int Needs(), int pl);
//int optionsArray(response);

int main()
{
    int numChar;
    //get user to give you a minimum number of characters for the password
    cout << "Minimum number of characters: ";
    cin >> numChar;
    pl = numChar;
    Needs();
    generatePass(Needs,pl);

    return 0;
}



int Needs()
{
    string needChar;
    string needNum;
    string needSpecChar;


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
    cout << "Needs letters: " << needChar << endl;
    cout << "Needs numbers: " << needNum << endl;
    cout << "Needs special characters: " << needSpecChar << endl;

    return response;
}


// Creates the password based off of the needs
string generatePass(int Needs(),int pl)
{
    int buildpass;
    int rdm; 
    char numbers[NUMBERS] = {'0','1','2','3','4','5','6','7','8','9'};
    char letters[LETTERS] = {'A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z'};
    char characters[SCHARACTERS] = {'!','@','#','$','%','&','=','-'};

    string password = "";

    while(password.length() < pl)
    {
        //Only needs letters in password
        if (response == 1)
        {
            buildpass = (rand() % 3) + 1;
            for(int i = 0; i < buildpass; i++)
            {
                rdm = rand() % LETTERS;
                char letter = letters[rdm];
                password = password + letter;
            }
        }
        //only needs numbers
        if (response == 2)
        {
            buildpass = (rand() % 3) + 1;
            for(int i = 0; i < buildpass; i++)
            {
                rdm = rand() % NUMBERS;
                char number = numbers[rdm];
                password = password + number;
            }
        }
        //needs letters and numbers
        if (response == 3)
        {   
            buildpass = (rand() % 3) + 1;
            for(int i = 0; i < buildpass; i++)
            {
                rdm = rand() % LETTERS;
                char letter = letters[rdm];
                password = password + letter;
            }            
            buildpass = (rand() % 3) + 1;
            for(int i = 0; i < buildpass; i++)
            {
                rdm = rand() % NUMBERS;
                char number = numbers[rdm];
                password = password + number;
            }
        }
        //Needs letters numbers and special characters
        if (response == 6)
        {
            buildpass = (rand() % 3) + 1;
            for(int i = 0; i < buildpass; i++)
            {
                rdm = rand() % LETTERS;
                char letter = letters[rdm];
                password = password + letter;
            }            
            buildpass = (rand() % 3) + 1;
            for(int i = 0; i < buildpass; i++)
            {
                rdm = rand() % NUMBERS;
                char number = numbers[rdm];
                password = password + number;
            }
            buildpass = (rand() % 2) + 1;
            for(int i = 0; i < buildpass; i++)
            {
                rdm = rand() % SCHARACTERS;
                char sc = characters[rdm];
                password = password + sc;
            }
        } 
    }
    system("clear");
    cout << "Generated password is: " << password << endl;
    return password;
}

//int optionsArray(response)
