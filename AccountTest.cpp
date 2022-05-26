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
    
    
    cout<<"Calling monthlyProc()"<<endl;
    newAccount.monthlyProc();
    cout<<"New account info:" <<endl;
    cout<<"\tBalance             = $" << newAccount.getBalance()  << endl;
    cout<<"\tAnnual Interest     = " << newAccount.getAInterest() << "%" << endl;
    cout<<"\tMonthly Charges     = $" << newAccount.getMCharges() << endl;
    cout<<"\tDeposits per month  = " << newAccount.getDepPerMo()  << endl;
    cout<<"\tWithdraws per month = " << newAccount.getWithPerMo() << endl;
    
    return 0;
}