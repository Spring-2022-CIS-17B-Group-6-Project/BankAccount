/* 
 * File:   Account.cpp
 * Author: Joseph Hernandez
 * Created on May 18, 2022, 10:37 PM
 * Last modified on 05/25/2022 12:15PM
 * Purpose: Account class implementation
 */



#include "Account.h"

Account::Account(float balance, float aInterest) {
    this->balance = balance;            // Set balance
    this->aInterest = aInterest;        // Set annual interest
    this->depPerMo = 0;                 // Init deposits per month
    this->withPerMo = 0;                // Init withdraws per month
    this->mCharges = 0.0;               // Init monthly charges
}

void Account::deposit(float deposit) {
    balance += deposit;                 // Add deposit to balance
    depPerMo++;                         // Increment number of deposits per month
}

void Account::withdraw(float withdraw) {
    balance -= withdraw;                // Subtract withdraw from balance
    withPerMo++;                        // Increment number of withdraws per month
}

void Account::monthlyProc() {
    balance -= mCharges;                // Subtract monthly charges from balance
    
    calcInt();                          // Calculate Interest for month
    
    depPerMo  = 0;                      // Reset deposits per month
    withPerMo = 0;                      // Reset withdraws per month
    mCharges  = 0;                      // Reset monthly charges
}

void Account::calcInt() {
    float mInterest = aInterest / 12;
    mInterest *= balance;
    balance += mInterest;
}

void Account::setDepPerMo(unsigned int depPerMo){
    this->depPerMo = depPerMo;
}

void Account::setWithPerMo(unsigned int withPerMo){
    this->withPerMo = withPerMo;
}

void Account::setBalance(float balance){
    this->balance = balance;
}

void Account::setAInterest(float aInterest){
    this->aInterest = aInterest;
}

void Account::setMCharges(float mCharges){
    this->mCharges = mCharges;
}