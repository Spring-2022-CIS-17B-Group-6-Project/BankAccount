/*
 * File: AccountTest.cpp
 * Author: Joseph Hernandez
 * Created on 05/25/22 10:05PM
 * Last modified on 
 * Purpose: Test the account class to ensure it functions properly
 */

#include <iostream>
using namespace std;

#include "Account.h"
#include "Checking.h"

int main(int argv, char** argc){
    float balance, aInterest;
    
    balance = 500.00;
    aInterest = 2.5;
    
    Account newAccount(balance, aInterest);
    
    newAccount.deposit(500.00);
    newAccount.withdraw(250.00);
    newAccount.setDepPerMo(15);
    
    cout<<"Deposits per month               = " << newAccount.getDepPerMo() << endl;
    newAccount.setWithPerMo(3);
    
    cout<<"Withdraws per month              = "<< newAccount.getWithPerMo() << endl;
    
    
    cout<<"Account balance                  = $" << newAccount.getBalance()<<endl;
    
    newAccount.setBalance(1800);
    cout<<"New account balance              = $" << newAccount.getBalance()<<endl;
    
    newAccount.setMCharges(45.00);
    
    cout<<"Original annual interest rate    = " << newAccount.getAInterest() << "%"<<endl;
    
    newAccount.setAInterest(3.5);
    
    cout<<"New annual interest rate         = " << newAccount.getAInterest() << "%" << endl;
    
    
    cout<<"Calling newAccount.monthlyProc()"<<endl;
    newAccount.monthlyProc();
    cout<<"New account info:" <<endl;
    cout<<"\tBalance             = $" << newAccount.getBalance()  << endl;
    cout<<"\tAnnual Interest     = " << newAccount.getAInterest() << "%" << endl;
    cout<<"\tMonthly Charges     = $" << newAccount.getMCharges() << endl;
    cout<<"\tDeposits per month  = " << newAccount.getDepPerMo()  << endl;
    cout<<"\tWithdraws per month = " << newAccount.getWithPerMo() << endl;
    
    
    // Checking account test
    
    Checking newChecking(500.00,0.85);
    cout<<"Checking balance                            = $"<<newChecking.getBalance()<<endl;
    
    newChecking.deposit(250.00);
    cout <<"Checking balance after $250.00 deposit      = $"<<newChecking.getBalance()<<endl;
    
    newChecking.withdraw(100.00);
    cout <<"Checking balance after $100.00 withdraw     = $"<<newChecking.getBalance()<<endl;
    
    newChecking.deposit(100.00);
    newChecking.deposit(350.00);
    
    newChecking.withdraw(75.00);
    newChecking.withdraw(125.00);
    cout <<"Checking balance                            = $"<<newChecking.getBalance()<<endl;
    
    cout << "Monthly Charges     = $" << newChecking.getMCharges() << endl;
    cout << "Deposits per month  = " << newChecking.getDepPerMo() << endl;
    cout << "Withdraws per month = "<< newChecking.getWithPerMo() << endl;
    
    
    
    cout<<"Calling newChecking.monthlyProc()"<<endl;
    newChecking.monthlyProc();
    cout<<"New account info:" <<endl;
    cout<<"\tBalance             = $" << newChecking.getBalance()  << endl;
    cout<<"\tAnnual Interest     = " << newChecking.getAInterest() << "%" << endl;
    cout<<"\tMonthly Charges     = $" << newChecking.getMCharges() << endl;
    cout<<"\tDeposits per month  = " << newChecking.getDepPerMo()  << endl;
    cout<<"\tWithdraws per month = " << newChecking.getWithPerMo() << endl;
    
    
    
    return 0;
}