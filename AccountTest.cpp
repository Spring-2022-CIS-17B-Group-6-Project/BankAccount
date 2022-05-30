/*
 * File: AccountTest.cpp
 * Author: Joseph Hernandez
 * Created on 05/25/22 10:05PM
 * Last modified on 
 * Purpose: Test the account class to ensure it functions properly
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "Account.h"
#include "Checking.h"
#include "Saving.h"

int main(int argv, char** argc){
    float balance, aInterest;
    
    balance = 500.00;
    aInterest = 2.5;
    
    Account newAccount(balance, aInterest);
    
    newAccount.deposit(500.00);
    newAccount.withdraw(250.00);
    newAccount.setDepPerMo(15);
    
    cout << "Your account number is: " << newAccount.getAccountNumber() << endl;

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
    
    cout <<endl<<endl;
    
    // Checking account test
    
    Checking newChecking(500.00f,0.85f);
    
    cout << "Your checking account number is: " << newChecking.getAccountNumber() << endl;
    
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
    
    cout << endl << endl;
    // Savings account
    Saving newSavings(300.00f, 8.7f);
    cout << "Your saving account number is: " << newSavings.getAccountNumber() << endl;
    
    cout <<"Savings balance                      = $"<<newSavings.getBalance()<<endl;
    
    newSavings.deposit(300.00);
    newSavings.deposit(150.00);
    newSavings.deposit(50.00);
    
    cout<<"Savings Balance after $500 deposit   = $"<<newSavings.getBalance()<<endl;
    
    newSavings.withdraw(500.00);
    newSavings.withdraw(500.00); // This should cause the account to go negative
    
    newSavings.withdraw(5.00);//Attempt to withdraw $5 from balance -$200
    
    newSavings.deposit(250.00);// Bring account back to $50
    
    cout<<"Account balance                      = $"<<newSavings.getBalance()<<endl;
    
    newSavings.withdraw(5.00);
    cout<<"Account balance                      = $"<<newSavings.getBalance()<<endl;
    
    cout <<"Checking before transfer = $"<<newChecking.getBalance()<<endl;
    cout <<"Savings before transfer  = $"<<newSavings.getBalance()<<endl;
    
    
    newChecking.transfer(newSavings, 100.00);
    
    cout <<"Transfer $100.00 from checking into savings"<<endl;
    cout <<"Checking balance = $"<<newChecking.getBalance()<<endl;
    cout <<"Saving balance   = $"<<newSavings.getBalance()<<endl;
    
    cout<<"Attempting to transfer $250.00 from savings to checking..."<<endl;
    
    newSavings.transfer(newChecking,250.00);
    
    cout<<"Calling newSavings.monthlyProc()"<<endl;
    newSavings.monthlyProc();
    cout<<"New account info:" <<endl;
    cout<<"\tBalance             = $" << fixed << setprecision(2) << newSavings.getBalance()  << endl;
    cout<<"\tAnnual Interest     = " << newSavings.getAInterest() << "%" << endl;
    cout<<"\tMonthly Charges     = $" << newSavings.getMCharges() << endl;
    cout<<"\tDeposits per month  = " << newSavings.getDepPerMo()  << endl;
    cout<<"\tWithdraws per month = " << newSavings.getWithPerMo() << endl;
    
    return 0;
}