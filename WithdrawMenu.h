/* 
 * File:   WithdrawMenu.h
 * Author: Joseph Hernandez
 *
 * Created on June 5, 2022, 10:41 PM
 */

#ifndef WITHDRAWMENU_H
#define WITHDRAWMENU_H

#include "Menu.h"
#include "Account.h"
#include "Checking.h"
#include "Saving.h"
#include <vector>

class WithdrawMenu : public Menu{
    public:
        void displayHeader();
        int getOptions();
        void makeWithdraw(vector<Account*>&);
    private:
        void printAccounts(vector<Account*>);
        Account* account;
};


#endif /* WITHDRAWMENU_H */

