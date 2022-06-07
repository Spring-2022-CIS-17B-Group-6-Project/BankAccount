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
#include "WithdrawMenu.h"
#include "DepositMenu.h"

void openAccount(vector<Account*>&);
void printStatements(vector<Account*>);
void withdrawMenu(vector<Account*>);
void depositMenu(vector<Account*>);
void newMonth(vector<Account*>);



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
        // Branch off to each case for Main Menu
        switch(mMenuChoice){
            case 1: openAccount(accounts);
                    goto mainMenu_start;// Open Account Menu
            case 2: depositMenu(accounts);
                    goto mainMenu_start;// Deposit to account menu
            case 3: withdrawMenu(accounts);
                    goto mainMenu_start;// Withdraw from account menu
            case 4: printStatements(accounts);// Print Transactions
                    goto mainMenu_start;
            case 5: newMonth(accounts);
                    goto mainMenu_start;

            default: cout<<endl<<setw(61)<<"Exiting..."<<endl;// end application
    }
    }catch(int e){
        cout<<"ERROR: Incorrect Selection. Exiting Program..."<<endl;
        return 0;
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
        cout<<setw(61)<<"No Account created..."<<endl;
    }
    cout<<endl;
    cout<<setw(53)<<"Would you like to create a new account?"<<endl;
    cout<<setw(40)<<"1. Create new account"<<endl;
    cout<<setw(39)<<"2. Back to main menu"<<endl;
    cout<<setw(26)<<"Selection: ";
    cin>>choice;
    if(choice == 1){
        goto loop;
    }
    else{
        cout<<setw(61)<< "Exiting to main menu..."<<endl<<endl;
    }
}

void printStatements(vector<Account*>accounts){
    int error = 007;
    try{
        if(accounts.empty()){
            throw error;
        }
        for(auto acct : accounts){
            acct->printTransactions();
            cout<<setw(52)<<"Balance: $"<<
                    fixed<<setprecision(2)<<acct->getBalance()<<endl<<endl;
        }
        cout<<setw(12)<<"-";
        for(int i =0;i<49;i++){
            cout<<"-";
        }
        cout<<endl<<endl;
    }
    catch(int e){
        cout<<setw(61)<<"No Accounts Exists..."<<endl;
        return;
    }
}

void withdrawMenu(vector<Account*> accounts){
    int error = 555;
    withdraw_start:
    try{
        if(accounts.empty()){
            throw error;
        }
        int choice;
        // We want to make sure that there are are accounts in the vector,
        // if vector is null, then we do not want to call withdrawMenu
        WithdrawMenu withdrawMenu;
        withdrawMenu.makeWithdraw(accounts);
        cout<<setw(51)<<"Would you like to make a new withdraw?"<<endl;
        cout<<setw(40)<<"1. Make new withdraw"<<endl;
        cout<<setw(40)<<"2. Back to Main Menu"<<endl;
        cout<<endl;
        cout<<setw(26)<<"Selection: ";
        cin>>choice;
        if(choice == 1) goto withdraw_start;
    }
    catch(int e){
        cout<<setw(61)<<"Error: No Accounts Exist..."<<endl<<endl;
        return;
    }
    
}

void depositMenu(vector<Account*> accounts){
    int error = 8675; 
deposit_start:
    
    try{
        if(accounts.empty()){
            throw error;
        }
        int choice;
        // We want to make sure that there are are accounts in the vector,
        // if vector is null, then we do not want to call withdrawMenu
        DepositMenu depositMenu;
        depositMenu.makeDeposit(accounts);
        cout<<setw(42)<<"Would you like to make a new deposit?"<<endl;
        cout<<setw(37)<<"1. Make new deposit"<<endl;
        cout<<setw(38)<<"2. Back to Main Menu"<<endl;
        cout<<endl;
        cout<<setw(26)<<"Selection: ";
        cin>>choice;
        if(choice == 1) goto deposit_start;
    }
    catch(int e){
        cout<<setw(61)<<"No Accounts Exitst..."<<endl<<endl;
        return;
    }
}

void newMonth(vector<Account*> accounts){
    int error = 2233;
    try{
        if(accounts.empty()){
            throw error;
        }
        for(auto acct : accounts){
            acct->printTransactions();
            cout<<setw(30)<<"Deposits: "<<acct->getDepPerMo()<<endl;
            cout<<setw(30)<<"Withdraws: "<<acct->getWithPerMo()<<endl;
            cout<<setw(43)<<"Ending Balance: $"<<
                    fixed<<setprecision(2)<<acct->getBalance()<<endl;
            acct->monthlyProc();
        }
        cout<<setw(12)<<"-";
        for(int i =0;i<49;i++){
            cout<<"-";
        }
        cout<<endl<<endl;
    }
    catch(int e){
        cout<<setw(61)<<"No Accounts Exists..."<<endl<<endl;
        return;
    }
        
}