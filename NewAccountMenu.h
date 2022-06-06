/* 
 * File:   NewAccountMenu.h
 * Author: Joseph Hernandez
 *
 * Created on June 5, 2022, 6:14 PM
 */

#include <vector>
using namespace std;

#include "Menu.h"
#include "Checking.h"
#include "Saving.h"

#ifndef NEWACCOUNTMENU_H
#define NEWACCOUNTMENU_H

class NewAccountMenu :  public Account, public Menu{
public:
    void displayHeader();
    Account* createAccount();
    int getOptions();
private:
    int choice;
    Account* newAccount;
};

#endif /* NEWACCOUNTMENU_H */

