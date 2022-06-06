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
                && mMenuChoice != 4 && mMenuChoice != 5){
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
        default: cout<<"Do nothing... Exiting..."<<endl;// Do nothing to end application
    }
    
    return 0;
}

void openAccount(vector<Account*> &accounts){
    NewAccountMenu newAccount;
    accounts.push_back(newAccount.createAccount());
    cout<<"Returning to main menu..."<<endl;
}

void printStatements(vector<Account*>accounts){
    for(auto acct : accounts){
        acct->printTransactions();
        cout<<"Ending Balance: $"<<acct->getBalance()<<endl;
    }
}