/*
 * File: AccountTest.cpp
 * Author: Joseph Hernandez
 * Created on 05/25/22 10:05PM
 * Last modified on June 5, 2022 6:24 PM by Joseph Hernandez
 * Purpose: Bank System Application
 * 
 */

#include <vector>

#include "Checking.h"
#include "Saving.h"
#include "MainMenu.h"
#include "NewAccountMenu.h"

void openAccount(vector<Account*>&);
void printStatements(vector<Account*>);

int main(int argv, char** argc){
    // Create a map to hold accounts
    vector<Account*> accounts;
    int mMenuChoice;
    
    // Display Main Menu
    MainMenu mainMenu;

mainMenu_start:    
    // Display Main Menu and get user input
    try{
        mMenuChoice = mainMenu.getOptions();
        if(mMenuChoice!=1 && mMenuChoice !=2 && mMenuChoice != 3 
                && mMenuChoice != 4 && mMenuChoice != 5 && mMenuChoice != 6){
            throw mMenuChoice;
        }
    }catch(int e){
        cout<<"ERROR: Incorrect Selection. Exiting Program..."<<endl;
        return 0;
    }
    
    // Branch off to each case for Main Menu
    switch(mMenuChoice){
        case 1: openAccount(accounts);
                goto mainMenu_start;// Open Account Menu
        case 2: cout<<"Deposit Menu"<<endl;break;// Deposit to account menu
        case 3: cout<<"Withdraw Menu"<<endl;break;// Withdraw from account menu
        case 4: printStatements(accounts);break;// Print Transactions
        case 5: //New month? Need to have new month for monthyProc
        default: cout<<"Do nothing... Exiting..."<<endl;// Do nothing to end application
    }
    
    return 0;
}

void openAccount(vector<Account*> &accounts){
    int error = 187;
    int choice;
loop:
    try{
        NewAccountMenu newAccount;
        Account* account = newAccount.createAccount();
        if(&(*account) == nullptr){
            throw error;
        }
        accounts.push_back(account);
    }catch(int e){
        cout<<"No Account created"<<endl;
    }
    cout<<"Would you like to create a new account?"<<endl;
    cout<<"1. Create new account"<<endl;
    cout<<"2. Back to main menu"<<endl;
    cin>>choice;
    if(choice == 1){
        goto loop;
    }
    else{
        cout << "Exiting to main menu..."<<endl;
    }
}

void printStatements(vector<Account*>accounts){
    for(auto acct : accounts){
        acct->printTransactions();
        cout<<"Ending Balance: $"<<acct->getBalance()<<endl;
    }
}