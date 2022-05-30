/*
 * File:   Checking.cpp
 * Author: Liliana Darch
 * Created on May 25, 2022, 10:00 AM
 * Last modified on May 25, 2022 11:19PM by Joseph Hernandez
 * Purpose: Checking class implementation
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

    else if (minusAmount <= 0) {                       // Check if customer is going to withdraw a negative number
        cout << "Please enter the amount you would like to withdraw." << endl;
        // I will adding input validation here to make sure that
        // user doesn't input a negative number
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
