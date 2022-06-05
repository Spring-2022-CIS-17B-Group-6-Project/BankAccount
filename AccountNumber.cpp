/*
 * File: AccountNumber.cpp
 * Author: Joseph Hernandez
 * Created on June 4, 2022, 11:54 PM
 * Purpose: Hash for account number
 * 
 */

#include "AccountNumber.h"

unsigned int AccountNumber::hashNumber(const string& accountNum){
    unsigned int b    = 378551;
    unsigned int a    = 63689;
    unsigned int hash = 0;

    for(int i = 0; i < accountNum.length(); i++){
       hash = hash * a + accountNum[i];
       a    = a * b;
    }

   return hash;
}