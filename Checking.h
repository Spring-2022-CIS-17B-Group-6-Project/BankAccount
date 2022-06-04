
/* 
 * File:   Checking.h
 * Author: Liliana Darch
 * Created on May 24, 2022, 3:00 PM
 * Last modified on 
 * Purpose: Checking class description
 */

#ifndef CHECKING_H
#define CHECKING_H

#include <iostream>
#include <string> 
#include <vector>
#include "Account.h"
using namespace std;


class  Checking : public Account{
    private: 
        vector<string> transactionType;
        vector<float> transactionValue;
    public:
        Checking(float, float);
        void withdraw (float);
        void monthlyProc();
        void setTransactionType(const string&);
        void setTransactionValue(float);
        void PrintTranactionLog();
};

#endif /* CHECKING_H */
