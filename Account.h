 /*
 * File:   Account.h
 * Author: Joseph Hernandez
 * Created on May 18, 2022, 10:37 PM
 * Last modified on 05/25/2022 12:15PM
 * Purpose: Account abstract class description
 */
#include <iostream>
#include <iomanip>
#include <list>

#include "Transactions.h"

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {

public:
    Account();                              // Default constructo
    Account(float, float);                  // Constructor with params
    virtual void deposit(float);            // Deposit to account
    virtual void withdraw(float);           // Withdraw from account
    void transfer(Account&, float);         // Transfer between accounts
    virtual void monthlyProc();             // Monthly procedure

    // Gets the number of deposits per month and withdraws per month
    inline unsigned int getDepPerMo() const { return depPerMo; }
    inline unsigned int getWithPerMo() const { return withPerMo; }
    
    
    //inline unsigned int getAccountNumber() const { return accountNumber; }
    
    // Get the balance
    inline float getBalance() const { return balance; }
    // Get the annual interest rate
    inline float getAInterest() const { return aInterest; }
    // Get the monthly charges
    inline float getMCharges() const { return mCharges; }
    // Get the account name
    inline string getAcctNo() const {return acctNo;}
    // Get the account type
    inline string getAcctType() const {return accountType;}
    // Get the account number
    inline unsigned int getAccountNum() {return accountNumber;}

    
    // Set the number of deposits per month
    void setDepPerMo(unsigned int);
    // Set the number of withdraws per month
    void setWithPerMo(unsigned int);
    // Set the balance in the accout
    virtual void setBalance(float);
    // Set the annual interest rate
    void setAInterest(float);
    // Set monthly charges
    void setMCharges(float);
    // Set the account number
    virtual void setAccountNumber (unsigned int);
    // Set the account name
    void setAcctNo(string);
    
    // Set the account type
    void setAccountType(string);
    
    // Print account number
    void printAccountNumber();
    // Print account transactions list
    void printTransactions();
    
    
private:
    void calcInt();                 // Calculate the interest earned
    unsigned int depPerMo;          // Deposits per month
    unsigned int withPerMo;         // Withdraws per month
    float balance;                  // Balance of account
    float aInterest;                // Annual interest
    float mCharges;                 // Monthly Charges

    string accountType;             // Account type
    
    unsigned int accountNumber;     // Account number
    string acctNo;                  // Account name
    
    list<Transactions> transactionList; // List of transactions

    
};


#endif /* ACCOUNT_H */

