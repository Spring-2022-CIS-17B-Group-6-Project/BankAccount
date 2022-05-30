/*
 * File:   Account.h
 * Author: Joseph Hernandez
 * Created on May 18, 2022, 10:37 PM
 * Last modified on 05/25/2022 12:15PM
 * Purpose: Account abstract class description
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Account {

public:
    Account(float, float);
    virtual void deposit(float);
    virtual void withdraw(float);
    void transfer(Account&, float);
    virtual void monthlyProc();

    inline unsigned int getDepPerMo() const { return depPerMo; }
    inline unsigned int getWithPerMo() const { return withPerMo; }
    //inline unsigned int getAccountNumber() const { return accountNumber; }
    inline float getBalance() const { return balance; }
    inline float getAInterest() const { return aInterest; }
    inline float getMCharges() const { return mCharges; }
    

    void setDepPerMo(unsigned int);
    void setWithPerMo(unsigned int);
    void setBalance(float);
    void setAInterest(float);
    void setMCharges(float);

    static unsigned int count;

private:
    void calcInt();
    unsigned int depPerMo;          // Deposits per month
    unsigned int withPerMo;         // Withdraws per month
    float balance;                  // Balance of account
    float aInterest;                // Annual interest
    float mCharges;                 // Monthly Charges

    std::string accountNumber;      // Account number will have form
                                    // Loc number-account type-count number-RNG 
};


#endif /* ACCOUNT_H */

