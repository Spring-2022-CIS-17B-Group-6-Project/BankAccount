/*
 * File:   Savings.cpp
 * Author: Will Liu
 * Created on May 26, 2022, 12:00 PM
 * Last modified on:
 * Purpose: Savings class implementation
 */

#include "Saving.h"

int Saving::count = 0;

Saving::Saving(): Account(){
    count++;
    activeStatus = false;
    setAccountNumber();
    Account::setAccountType("Saving");
}

Saving::Saving(float balance, float aInterest) : Account(balance, aInterest) {
    count++;
    activeStatus = false;
    if (Account::getBalance() >= 25) {
        activeStatus = true;
    }
    setAccountNumber();
    Account::setAccountType("Saving");
}

void Saving::withdraw(float withdrawAmnt) {
    if (!activeStatus) {
        cout << "Your account balance is $" << Account::getBalance() << "\n"
            << "Your account is inactive under $25. Please deposit more money before withdrawing." << endl;
    }
    else {
        Account::withdraw(withdrawAmnt);
        if (Account::getBalance() < 0) {
            activeStatus = false;
            cout << "Your account is negative" << endl;
        }
    }
}

void Saving::deposit(float depositAmnt) {
    // Check if account is not active, if not active and depositAmnt >= 25
    // then acvtiveStatus = true;
    if (activeStatus==false && depositAmnt >= 25) {
        activeStatus = true;
    }
    
    Account::deposit(depositAmnt);
}

void Saving::monthlyProc() {
    int numberWith = Account::getWithPerMo();
    
    // Check number of withdraws, if withPerMo > 4, then $1 * (withPerMo - 4) + mCharges
    if (numberWith > 4){
        numberWith-=4;
        Account::setMCharges(Account::getMCharges() + numberWith);
    }
    cout<<setw(30)<<"Monthly Service Charges: $"<<
            fixed<<setprecision(2)<<Account::getMCharges()<<endl;
    Account::monthlyProc();

    // Check if account is below $25. If balance < $25, then activeStatus = false
    if (Account::getBalance() < 25) activeStatus = false;
}

void Saving::setAccountNumber(){
    Account::setAcctNo("Saving" + to_string(count));
    Account::setAccountNumber(AccountNumber::hashNumber(getAcctNo()));
}

void Saving::setBalance(float amount){
    if(amount >= 25) activeStatus = true;
    Account::setBalance(amount);
}