
/* 
 * File:   Checking.h
 * Author: Liliana Darch
 * Created on May 24, 2022, 3:00 PM
 * Last modified on 
 * Purpose: Checking class description
 */

#include "Account.h"
#include "AccountNumber.h"



#ifndef CHECKING_H
#define CHECKING_H



class  Checking : public Account{      
    private:
    void setAccountNumber();            // Sets the account number
    
    static int count;                   // Counts how many objects created
    
    public:
        Checking();                     // Default Constructor
        Checking(float, float);         // Constructor to take in bal and interest
        void withdraw (float);          // Withdraws from account
        void deposit (float);           // Deposits to account
        void monthlyProc();             // Monthly Procedures to cal interest
                                        // and deduct any monthly charges
        
        inline string getAcctNum() {return Account::getAcctNo();} // Returns acct name
};

#endif /* CHECKING_H */
