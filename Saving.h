/* 
 * File:   Saving.h
 * Author: Will Liu
 * Created on: May 26, 2022, 12:00 PM
 * Last modified on 05/27/2022 12:15PM
 * Purpose: Account abstract class description
 */
 
#ifndef SAVING_H
#define SAVING_H

#include "Account.h"

class Saving : public Account {
    private:
        bool activeStatus;
    public:
        Saving(float, float);
        bool getActiveStatus(){return activeStatus;};
        
        void withdraw(float); 
        void deposit(float); 
        void monthlyProc(int); 
};

#endif /* SAVING_H */
