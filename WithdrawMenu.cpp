
#include "WithdrawMenu.h"


void WithdrawMenu::displayHeader(){
    cout<<setw(25)<<"Withdraw Menu:"<<endl;
}

int WithdrawMenu::getOptions(){
    return 0;
}

void WithdrawMenu::makeWithdraw(vector<Account*> &accounts){
    float amount;
    int index;
    cout<<"Select from accounts:"<<endl;
    printAccounts(accounts);
    cin>>index;
    index--;
    cout<<"Enter withdraw amount: ";
    cin>>amount;
    // Branch statement for which account to make withdraw from
    if(accounts[index]->getAcctType() == "Checking"){
        // Checking withdraw function
        accounts[index]->withdraw(amount);
        cout<<"New balance: $"<<accounts[index]->getBalance()<<endl;
    }
    else if(accounts[index]->getAcctType() == "Saving"){
        // Saving withdraw function
        accounts[index]->withdraw(amount);
        cout<<"New balance: $"<<accounts[index]->getBalance()<<endl;
    }
}

void WithdrawMenu::printAccounts(vector<Account*> accounts){
    int count = 0;
    for(auto acct: accounts){
        cout<<++count<<". "<<acct->getAcctNo()<<endl;
    }
}