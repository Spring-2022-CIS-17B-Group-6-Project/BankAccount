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
    bool activeStatus;
    void setAccountNumber();
    
    static int count;
    
    public:
        Saving();
        Saving(float, float);
        bool getActiveStatus(){return activeStatus;};
        
        void withdraw(float); 
        void deposit(float); 
        void monthlyProc(); 
        
        void setTransactionType(const string&);
        void setTransactionValue(float);
        void PrintTranactionLog();
        
};

#endif /* SAVING_H */
