/*
 * File: AccountTest.cpp
 * Author: Joseph Hernandez
 * Created on 05/25/22 10:05PM
 * Last modified on June 3, 2022 6:20PM by Liliana Darch
 * Purpose: Test the account class to ensure it functions properly
 * 
 */

#include <vector>

#include "Checking.h"
#include "Saving.h"
#include "MainMenu.h"


int main(int argv, char** argc){
    // Create a map to hold accounts
    vector<Account*> accounts;
    int mMenuChoice;
    
    // Display Main Menu
    MainMenu mainMenu;
    

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
    
    
    switch(mMenuChoice){
        case 1: cout<<"Open Account Menu..."<<endl;break;// Open Account Menu
        case 2: cout<<"Deposit Menu"<<endl;break;// Deposit to account menu
        case 3: cout<<"Withdraw Menu"<<endl;break;// Withdraw from account menu
        case 4: cout<<"Print Transactions Menu"<<endl;break;// Print Transactions
        default: cout<<"Do nothing... Exiting..."<<endl;// Do nothing to end application(goto?)
    }
    
    return 0;
}
