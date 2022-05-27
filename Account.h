/* 
 * File:   Account.h
 * Author: Joseph Hernandez
 * Created on May 18, 2022, 10:37 PM
 * Last modified on 05/25/2022 12:15PM
 * Purpose: Account abstract class description
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H



class Account{

    public:
        Account(float, float);
        virtual void deposit(float);
        virtual void withdraw(float);
        void transfer(Account&,float);
        virtual void monthlyProc();
        
        inline unsigned int getDepPerMo() {return depPerMo;}
        inline unsigned int getWithPerMo() {return withPerMo;}
        inline float getBalance() {return balance;}
        inline float getAInterest() { return aInterest;}
        inline float getMCharges() {return mCharges;}
        
        void setDepPerMo(unsigned int);
        void setWithPerMo(unsigned int);
        void setBalance(float);
        void setAInterest(float);
        void setMCharges(float);
        
        
    protected:
        void calcInt();

        unsigned int depPerMo;          // Deposits per month
        unsigned int withPerMo;         // Withdraws per month
        float balance;                  // Balance of account
        float aInterest;                // Annual interest
        float mCharges;                 // Monthly Charges
};




#endif /* ACCOUNT_H */

