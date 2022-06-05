/*
 * File: AccountTest.cpp
 * Author: Joseph Hernandez
 * Created on 05/25/22 10:05PM
 * Last modified on June 3, 2022 6:20PM by Liliana Darch
 * Purpose: Test the account class to ensure it functions properly
 * 
 */

#include "Checking.h"
#include "Saving.h"
#include <vector>
#include <c++/bits/stl_vector.h>

int main(int argv, char** argc){
    // Create a map to hold accounts
    vector<Account*> accounts;
    
    
    // Start menu displaying options for opening a checking or savings account
    Checking newChecking;
    Checking checking2;
    Saving saving1;
    Saving saving2;
    
    accounts.push_back(&newChecking);
    accounts.push_back(&checking2);
    accounts.push_back(&saving1);
    accounts.push_back(&saving2);

    newChecking.deposit(500.00);
    newChecking.withdraw(100.00);
    
    
    checking2.deposit(200.00);
    checking2.withdraw(100.00);
    checking2.withdraw(10.00);
    checking2.withdraw(20.00);
    checking2.deposit(150.00);
    checking2.deposit(25.00);
    
    
    saving1.deposit(500.00);
    saving1.withdraw(100.00);
    

    for(const auto& acct : accounts){
        acct->printTransactions();
    }
    
    return 0;
}