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

Saving::Saving(float balance, int withPerMo) : Account(balance, withPerMo){
    if((Account::balance) < 25){
        this->activeStatus = false;
    } else{
        this->activeStatus = true;
    }
}

void Saving::withdraw(float withdrawAmnt){
    if (!activeStatus){
        cout << "Your account balance is lower than $25. Please deposit more money before withdrawing." << endl;
        
    } else {
        Account::withdraw(withdrawAmnt);
    }
}
void Saving::deposit(float depositAmnt){
    if (!activeStatus){
        cout << "Your account balance is lower than $25. Please deposit more money before withdrawing." << endl;
        Account::balance += depositAmnt;
        cout<< "new balance: " << newBalance<< endl;
        if(Account::balance > 25){
            this->activeStatus = true;
        }
    } else {
        Account::deposit(depositAmnt);
    }
}
