
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
    void setAccountNumber();
    
    static int count;
    
    public:
        Checking();
        Checking(float, float);
        void withdraw (float);
        void deposit (float);
        void monthlyProc();
        
        inline string getAcctNum() {return Account::getAcctNo();}
        
};

#endif /* CHECKING_H */
