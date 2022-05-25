
/* 
 * File:   Checking.h
 * Author: Liliana Darch
 * Created on May 24, 2022, 3:00 PM
 * Last modified on 
 * Purpose: Checking class description
 */

#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"

class  Checking : public Account{
    public:
        Checking(float, float);
        void withdraw (float);
        void monthlyProc();
};

#endif /* CHECKING_H */