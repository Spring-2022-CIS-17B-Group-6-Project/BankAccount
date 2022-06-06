/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "DepositMenu.h"

void DepositMenu::displayHeader(){
    cout<<endl<<setw(12)<<"-";
    for(int i =0;i<49;i++){
        cout<<"-";
    }
    cout<<endl;
    cout<<setw(27)<<"Deposit Menu:"<<endl;
}

int DepositMenu::getOptions(){
    return 0;
}

void DepositMenu::makeDeposit(vector<Account*> &accounts){
    int exception = 100;
    float amount;
    int index;
    count=0;
    
    displayHeader();
    
    printAccounts(accounts);
    cout<<setw(12)<<"-";
    for(int i =0;i<49;i++){
        cout<<"-";
    }
    cout<<endl;
    cout<<setw(30)<<"Select account: ";
    cin>>index;
    index--;
    cout<<endl<<endl;
    try{
        if(index>count || index < 0){
            throw exception;
        }
    }catch(int e){
        cout<<setw(61)<<"Not valid selection..."<<endl<<endl;
        return;
    }
    cout<<setw(37)<<"Enter deposit amount: $";
    cin>>amount;
    // Branch statement for which account to make withdraw from
    if(accounts[index]->getAcctType() == "Checking"){
        // Checking withdraw function
        accounts[index]->deposit(amount);
        cout<<endl<<setw(30)<<"-";
        cout<<setw(24)<<"New balance: $"<<
                fixed<<setprecision(2)<<accounts[index]->getBalance()<<endl<<endl;
    }
    else if(accounts[index]->getAcctType() == "Saving"){
        // Saving withdraw function
        accounts[index]->deposit(amount);
        cout<<endl<<setw(30)<<"-";
        cout<<setw(24)<<"New balance: $"<<
                fixed<<setprecision(2)<<accounts[index]->getBalance()<<endl<<endl;
    }
}

void DepositMenu::printAccounts(vector<Account*> accounts){
    int width;
    for(auto acct: accounts){
        cout<<setw(20)<<++count<<". "<<acct->getAcctNo();
        if(acct->getAcctType() == "Checking") width = 23;
        else if(acct->getAcctType() == "Saving") width = 25;
        cout<<setw(width)<<right<<"Balance: $"<<
                fixed<<setprecision(2)<<acct->getBalance()<<endl;
    }
}