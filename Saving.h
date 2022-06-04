/*
 * File:   Saving.h
 * Author: Will Liu
 * Created on: May 26, 2022, 12:00 PM
 * Last modified on 05/27/2022 12:15PM
 * Purpose: Account abstract class description
 */

#ifndef SAVING_H
#define SAVING_H

#include <iostream>
#include <string> 
#include <vector>
#include "Account.h"
using namespace std;


class Saving : public Account {
    private:
        bool activeStatus;
        vector<string> transactionType;
        vector<float> transactionValue;
    public:
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
