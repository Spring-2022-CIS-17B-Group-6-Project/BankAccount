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
    
    
    checking2.printAccountNumber();
    checking2.deposit(200.00);
    checking2.withdraw(100.00);
    checking2.withdraw(10.00);
    checking2.withdraw(20.00);
    checking2.deposit(150.00);
    checking2.deposit(25.00);
    checking2.printTransactions();
    
    
    saving1.printAccountNumber();
    saving1.deposit(500.00);
    saving1.withdraw(100.00);
    saving1.printTransactions();
    
    
    return 0;
}