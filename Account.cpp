/*
 * File:   Account.cpp
 * Author: Joseph Hernandez
 * Created on May 18, 2022, 10:37 PM
 * Last modified on 05/25/2022 12:15PM
 * Purpose: Account class implementation
 */


#include "Account.h"

Account::Account(){
    this->balance = 0.0;
    this->aInterest = 0.0;
    this->depPerMo = 0;                 // Init deposits per month
    this->withPerMo = 0;                // Init withdraws per month
    this->mCharges = 0.0;               // Init monthly charges
}

Account::Account(float balance, float aInterest) {
    this->balance = balance;            // Set balance
    this->aInterest = aInterest;        // Set annual interest
    this->depPerMo = 0;                 // Init deposits per month
    this->withPerMo = 0;                // Init withdraws per month
    this->mCharges = 0.0;               // Init monthly charges

    //count++;                    // Keep track of each account

    //this->accountNumber = count;
}


void Account::deposit(float deposit) {
    Transactions transaction;
    transaction.amount = deposit;
    transaction.t_Type = "Deposit ";
    transactionList.push_back(transaction);
    
    balance += deposit;                 // Add deposit to balance
    depPerMo++;                         // Increment number of deposits per month
}

void Account::withdraw(float withdraw) {
    Transactions transaction;
    transaction.amount = withdraw;
    transaction.t_Type = "Withdraw";
    transactionList.push_back(transaction);
    
    balance -= withdraw;                // Subtract withdraw from balance
    withPerMo++;                        // Increment number of withdraws per month
}

void Account::transfer(Account& toAccount, float amount) {
    if (this->getBalance() - amount < 0) {
        cout << "Cannot transfer $" << amount << "\n"
            << "Your account only has $" << this->getBalance() << endl;
        cout << "Cancelling request..." << endl << endl;
    }
    else {
        this->setBalance(this->getBalance() - amount);
        toAccount.setBalance(toAccount.getBalance() + amount);
    }
}


void Account::monthlyProc() {
    balance -= mCharges;                // Subtract monthly charges from balance

    if (balance > 0) {
        calcInt();                      // Calculate Interest for month only if balance > 0
    }

    depPerMo = 0;                      // Reset deposits per month
    withPerMo = 0;                      // Reset withdraws per month
    mCharges = 0;                      // Reset monthly charges
}

void Account::calcInt() {
    float mInterest = aInterest / 12.0;
    mInterest *= balance;
    balance += mInterest;
}



void Account::setDepPerMo(unsigned int depPerMo) {
    this->depPerMo = depPerMo;
}

void Account::setWithPerMo(unsigned int withPerMo) {
    this->withPerMo = withPerMo;
}

void Account::setBalance(float balance) {
    this->balance = balance;
}

void Account::setAInterest(float aInterest) {
    this->aInterest = aInterest;
}

void Account::setMCharges(float mCharges) {
    this->mCharges = mCharges;
}

void Account::setAccountNumber(unsigned int accountNumber){
    this->accountNumber = accountNumber;
}

void Account::setAcctNo(string acctNo){
    this->acctNo = acctNo;
}

void Account::setAccountType(string accountType){
    this->accountType = accountType;
}

void Account::printAccountNumber(){
    cout<<getAcctNo()<<endl;
    cout<<"Account Number: "<<getAccountNum()<<endl;
}

void Account::printTransactions(){
    printAccountNumber();
    cout<<"Statement:"<<endl;
    for(auto ta : transactionList){
        cout<<setw(12)<<ta.t_Type<<setw(8)<<"$"<<ta.amount<<endl;
    }
    cout<<endl;
}