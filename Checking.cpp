/*
 * File:   Checking.cpp
 * Author: Liliana Darch
 * Created on May 25, 2022, 10:00 AM
 * Last modified on June 3, 2022 4:00PM by Liliana Darch
 * Purpose: Checking class implementation
 * 
 * g++ -o ./a Account.h Account.cpp Saving.h Saving.cpp Checking.h Checking.cpp AccountTest.cpp
 */

#include "Checking.h"


int Checking::count = 0;

Checking::Checking() : Account(){
    count++;
    setAccountNumber();
    Account::setAccountType("Checking");
}

Checking::Checking(float balance, float aInterest) : Account(balance, aInterest) {
    count++;
    setAccountNumber();
    Account::setAccountType("Checking");
}


void Checking::withdraw(float minusAmount) {
    if ((Account::getBalance() - minusAmount) < 0) {
        cout << "Transaction has been canceled." << endl;
        cout << "A service charge of $15 has been added to your account." << endl;

        Account::setBalance(Account::getBalance() - 15.00f);

        if (Account::getBalance() < 0) {
            cout << "You owe $" << Account::getBalance() << "to the bank" << endl;
        }
    }

    else {
        Account::withdraw(minusAmount);
    }
}
void Checking::deposit(float deposit){
	Account::deposit(deposit);
}

void Checking::monthlyProc() {
    Account::setMCharges(Account::getMCharges() + 5.00f + (Account::getWithPerMo() * 0.10f));
    Account::monthlyProc();
}

void Checking::setAccountNumber(){
    Account::setAcctNo("Checking" + to_string(count));
    Account::setAccountNumber(AccountNumber::hashNumber(getAcctNo()));
}
