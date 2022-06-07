/* 
 * File:   DepositMenu.h
 * Author: Joseph Hernandez
 *
 * Created on June 6, 2022, 1:41 AM
 */

#ifndef DEPOSITMENU_H
#define DEPOSITMENU_H

#include "Menu.h"


class DepositMenu : public Menu{
    public:
        void displayHeader();                   // Display title
        int getOptions();                       // Get options from user
        void makeDeposit(vector<Account*>&);    // Deposit into selected account
    private:
        void printAccounts(vector<Account*>);   // Print accounts
        int count;                              // Hold number of accounts
};

#endif /* DEPOSITMENU_H */

