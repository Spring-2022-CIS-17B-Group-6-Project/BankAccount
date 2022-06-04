/*
 * File:   Checking.cpp
 * Author: Liliana Darch
 * Created on May 25, 2022, 10:00 AM
 * Last modified on June 3, 2022 4:00PM by Liliana Darch
 * Purpose: Checking class implementation
 * 
 * g++ -o ./a Account.h Account.cpp Saving.h Saving.cpp Checking.h Checking.cpp AccountTest.cpp
 */

#include "Account.h"
#include "Checking.h"
#include <iostream>
using namespace std;

Checking::Checking(float balance, float aInterest) : Account(balance, aInterest) {

}


void Checking::withdraw(float minusAmount) {
    if ((Account::getBalance() - minusAmount) < 0) {                 // Check if the balance goes below $0
        cout << "Transaction has been canceled." << endl;
        cout << "A service charge of $15 has been added to your account." << endl;

        Account::setBalance(Account::getBalance() - 15.00f);

        if (Account::getBalance() < 0) {                           // Check if the balance is negative
            cout << "You owe $" << Account::getBalance() << "to the bank" << endl;
        }
    }

    else {                                          // Complete the transaction 
        Account::withdraw(minusAmount);
    }
}

void Checking::monthlyProc() {                      // Montly fee of $5 plus $0.10 per withdrawal 
    cout << "Monthly Services charges" << endl;
    Account::setMCharges(Account::getMCharges() + 5.00f + (Account::getWithPerMo() * 0.10f));
    cout << "$" << Account::getMCharges() << endl;
    Account::monthlyProc();
}
