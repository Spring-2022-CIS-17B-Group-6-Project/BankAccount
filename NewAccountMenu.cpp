/*
 * File: NewAccountMenu.cpp
 * Author: Joseph Hernandez
 * Created on June, 5, 2022, 6:24 PM
 */

#include "NewAccountMenu.h"

void NewAccountMenu::displayHeader(){
    cout<<"Create Account Menu:"<<endl;
}

Account* NewAccountMenu::createAccount(){
    displayHeader();
    Checking *newChecking;
    Saving *newSaving;
    int choice;
    float balance;
    float interest;
    choice = getOptions();
    // Dislpay options for user
    
    switch(choice){
        case 1:
        {// Logic for creating new checking account
            newChecking = new Checking();
            cout<<"Enter initial deposit amount: ";
            cin>>balance;
            cout<<"Enter annual interest rate: ";
            cin>>interest;
            newChecking->setBalance(balance);
            newChecking->setAInterest(interest);
            newAccount = newChecking;
            return newAccount;
        }
        case 2:
            // Logic for creating new saving account
            newSaving = new Saving();
            cout<<"Enter initial balance: ";
            cin>>balance;
            cout<<"Enter annual interest rate: ";
            cin>>interest;
            newSaving->setBalance(balance);
            newSaving->setAInterest(interest);
            newAccount = newSaving;
            return newAccount;
    }
    newChecking = nullptr;
    newAccount = newChecking;
    return newAccount;
}


int NewAccountMenu::getOptions(){
    int choice;
    
    cout<<"1. Create Checking Account"<<endl;
    cout<<"2. Create Saving Accout"<<endl;
    cout<<"3. Exit Back to Main Menu"<<endl;
    cin>>choice;

    return choice;
}

