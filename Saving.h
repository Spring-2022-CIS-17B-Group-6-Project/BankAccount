/*
 * File:   Saving.h
 * Author: Will Liu
 * Created on: May 26, 2022, 12:00 PM
 * Last modified on 05/27/2022 12:15PM
 * Purpose: Account abstract class description
 */
#include "Account.h"
#include "AccountNumber.h"

#ifndef SAVING_H
#define SAVING_H

class Saving : public Account{
    private:
    bool activeStatus;              // Account status
    void setAccountNumber();        // Set account number
    
    static int count;               // Count the number of objects
    
    public:
        Saving();                   // Default constructor
        Saving(float, float);       // Constructor with params
        bool getActiveStatus(){return activeStatus;};   // Get account status
        
        void withdraw(float);       // Withdraw
        void deposit(float);        // Deposit
        void monthlyProc();         // Monthly Procedures
        
        void setTransactionType(const string&); // Set the type of transaction
        void setTransactionValue(float);        // Set transaction amount
        void PrintTranactionLog();              // Print transaction log
        void setBalance(float);                 // Set the balance
};

#endif /* SAVING_H */
