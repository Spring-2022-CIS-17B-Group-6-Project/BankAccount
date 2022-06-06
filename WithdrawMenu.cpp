
#include "WithdrawMenu.h"


void WithdrawMenu::displayHeader(){
    cout<<endl<<setw(12)<<"-";
    for(int i =0;i<49;i++){
        cout<<"-";
    }
    cout<<endl;
    cout<<setw(25)<<"Withdraw Menu:"<<endl;
}

int WithdrawMenu::getOptions(){
    return 0;
}

void WithdrawMenu::makeWithdraw(vector<Account*> &accounts){
    int exception = 100;
    float amount;
    int index;
    
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
    try{
        if(index>count || index < 0){
            throw exception;
        }
    }catch(int e){
        cout<<setw(20)<<"Not valid selection..."<<endl;
        return;
    }
    cout<<endl<<endl;
    cout<<setw(37)<<"Enter withdraw amount: ";
    cin>>amount;
    // Branch statement for which account to make withdraw from
    if(accounts[index]->getAcctType() == "Checking"){
        // Checking withdraw function
        accounts[index]->withdraw(amount);
        cout<<endl<<setw(30)<<"-";
        cout<<setw(24)<<"New balance: $"<<
                fixed<<setprecision(2)<<accounts[index]->getBalance()<<endl<<endl;
    }
    else if(accounts[index]->getAcctType() == "Saving"){
        // Saving withdraw function
        accounts[index]->withdraw(amount);
        cout<<endl<<setw(30)<<"-";
        cout<<setw(24)<<"New balance: $"<<
                fixed<<setprecision(2)<<accounts[index]->getBalance()<<endl;
    }
}

void WithdrawMenu::printAccounts(vector<Account*> accounts){
    int count = 0;
    int width;
    for(auto acct: accounts){
        cout<<setw(20)<<++count<<". "<<acct->getAcctNo();
        if(acct->getAcctType() == "Checking") width = 23;
        else if(acct->getAcctType() == "Saving") width = 25;
        cout<<setw(width)<<right<<"Balance: $"<<
                fixed<<setprecision(2)<<acct->getBalance()<<endl;
    }
}