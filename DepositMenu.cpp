/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "DepositMenu.h"

void DepositMenu::displayHeader(){
    cout<<setw(24)<<"Deposit Menu:"<<endl;
}

int DepositMenu::getOptions(){
    return 0;
}

void DepositMenu::makeDeposit(vector<Account*> &accounts){
    displayHeader();
    float amount;
    int index;
    printAccounts(accounts);
    cout<<"Select account: ";
    cin>>index;
    index--;
    cout<<"Enter deposit amount: $";
    cin>>amount;
    // Branch statement for which account to make withdraw from
    if(accounts[index]->getAcctType() == "Checking"){
        // Checking withdraw function
        accounts[index]->deposit(amount);
        cout<<"New balance: $"<<accounts[index]->getBalance()<<endl;
    }
    else if(accounts[index]->getAcctType() == "Saving"){
        // Saving withdraw function
        accounts[index]->deposit(amount);
        cout<<"New balance: $"<<accounts[index]->getBalance()<<endl;
    }
}

void DepositMenu::printAccounts(vector<Account*> accounts){
    int count = 0;
    for(auto acct: accounts){
        cout<<++count<<". "<<acct->getAcctNo()<<endl;
    }
}