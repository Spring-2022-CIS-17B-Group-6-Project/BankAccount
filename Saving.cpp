/*
 * File:   Savings.cpp
 * Author: Will Liu
 * Created on May 26, 2022, 12:00 PM
 * Last modified on:
 * Purpose: Savings class implementation
 */


#include "Account.h"
#include "Saving.h"
#include <iostream>
using namespace std;

Saving::Saving(float balance, float aInterest) : Account(balance, withPerMo) {
    activeStatus = false;
    if (balance >= 25) {
        activeStatus = true;
    }
}

void Saving::withdraw(float withdrawAmnt) {
    if (!activeStatus) {
        cout << "Your account balance is $" << Account::balance << "\n"
            << "Please deposit more money before withdrawing." << endl;
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
    if (!activeStatus && depositAmnt >= 25) activeStatus = true;

    Account::deposit(depositAmnt);


}

void Saving::monthlyProc() {
    // Check number of withdraws, if withPerMo > 4, then $1 * (withPerMo - 4) + mCharges
    if (Account::getWithPerMo() > 4)
        Account::setMCharges(Account::getMCharges() + (Account::getWithPerMo() - 4));

    Account::monthlyProc();

    // Check if account is below $25. If balance < $25, then activeStatus = false
    if (Account::getBalance() < 25) activeStatus = false;
}
