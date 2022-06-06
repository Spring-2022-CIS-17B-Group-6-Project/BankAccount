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
        void displayHeader();
        int getOptions();
        void makeDeposit(vector<Account*>&);
    private:
        void printAccounts(vector<Account*>);
        int count;
};

#endif /* DEPOSITMENU_H */

