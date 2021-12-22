/*
Kyiem Chandler
10/21/2021
Password Generator
Creating a program that can generate a password for your needs whether it be with only numbers, only letters
only special characters or a mix of all of them.
*/ 

#include <iostream>
#include <fstream>
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
// Creates the password based off of the Needs function
string generatePass(int Needs(), int pl);


int main()
{
    int numChar;
    string view = "view";
    string another = "yes";
    srand(time(NULL));
    fstream myFile;
    while(another != "no" || another == "No")
    {

    
        //get user to give you a minimum number of characters for the password
        std::cout << "Minimum number of characters: ";
        cin >> numChar;
        pl = numChar;
        Needs();
        generatePass(Needs,pl);
       std::cout << "Need another password?" << endl;
        cin >> another;
        response = 0;
    }
    std::cout << "Do you want to view old generated passwords?" << endl;
    cin >> view;
    while(view != "yes" || view != "Yes")  //Views genPasswords file to show all created passwords.
    {
        myFile.open("genPasswords.txt",ios::in); //Read file
        if(myFile.is_open())
        {
            string line;
            while ( getline(myFile,line))
            {
                std::cout << line << endl;
            }
            myFile.close();
        }
    return 0;
    }
}



int Needs()
{
    string needChar;
    string needNum;
    string needSpecChar;


    // Ask does it need user if password needs characters
    std::cout << "Does password need letters? (yes or no): ";
    cin >> needChar;
    if(needChar == "yes" || needChar == "Yes")
    {
        response = response + 1;
    }

    //Ask does user need numbers in password
    std::cout << "Does password need numbers (yes or no): ";
    cin >> needNum;
    if(needNum == "Yes" || needNum == "yes")
    {
        response = response + 2;
    }
    //Ask the user if password needs special characters
    std::cout << "Does password need special characters? (yes or no): ";
    cin >> needSpecChar;
    if(needSpecChar == "Yes" || needSpecChar == "yes")
    {
        response = response + 4;
    }
    system("clear");
    std::cout << "Needs letters: " << needChar << endl;
    std::cout << "Needs numbers: " << needNum << endl;
    std::cout << "Needs special characters: " << needSpecChar << endl;
    if(response != 1 && response != 2 && response != 3 && response != 7)
    {
        system("clear");
        std::cout << "Invalid option configuration. Go through choices again.\n";
        response = 0;

        Needs();
    }
    else {
        return response;  
    }
}


// Creates the password based off of the needs
string generatePass(int Needs(),int pl)
{
    fstream myFile;
    int buildpass;
    int rdm; 
    char numbers[NUMBERS] = {'0','1','2','3','4','5','6','7','8','9'};
    char letters[LETTERS] = {'A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z'};
    char characters[SCHARACTERS] = {'!','@','#','$','%','&','=','-'};

    string password = "";
    string date = "";

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
        if (response == 7)
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
            buildpass = 1;
            for(int i = 0; i < buildpass; i++)
            {
                rdm = rand() % SCHARACTERS;
                char sc = characters[rdm];
                password = password + sc;
            }
        } 
    }
    system("clear");
    std::cout << "Generated password is: " << password << endl;
    std::cout << "What is today's date?" << endl;
    cin >> date;
    myFile.open("genPasswords.txt",ios::app); // Append  mode.
    if (myFile.is_open())
    {
        myFile << password << "  " << date << endl;
        myFile.close();
    }

    return password;
}

