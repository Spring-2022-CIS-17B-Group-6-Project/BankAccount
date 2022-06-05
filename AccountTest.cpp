/*
 * File: AccountTest.cpp
 * Author: Joseph Hernandez
 * Created on 05/25/22 10:05PM
 * Last modified on June 3, 2022 6:20PM by Liliana Darch
 * Purpose: Test the account class to ensure it functions properly
 * 
 */

#include "Account.h"
#include "Checking.h"
#include "Saving.h"


int main(int argv, char** argc){
    // Start menu displaying options for opening a checking or savings account
    Checking newChecking;
    Checking checking2;
    Saving saving1;
    Saving saving2;
    
    newChecking.printAccountNumber();
    newChecking.deposit(500.00);
    newChecking.withdraw(100.00);
    newChecking.printTransactions();
    
    return 0;
}