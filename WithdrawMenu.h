/* 
 * File:   WithdrawMenu.h
 * Author: Joseph Hernandez
 *
 * Created on June 5, 2022, 10:41 PM
 */

#ifndef WITHDRAWMENU_H
#define WITHDRAWMENU_H

#include "Menu.h"

class WithdrawMenu : public Menu{
    public:
        void displayHeader();                   // Display Menu Title
        int getOptions();                       // Get options from menu
        void makeWithdraw(vector<Account*>&);   // Withdraw from selected account
    private:
        void printAccounts(vector<Account*>);   // Print off list of accounts
        int count;                              // Holds the number of accounts
                                                // To read
};


#endif /* WITHDRAWMENU_H */

