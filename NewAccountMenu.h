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
    void displayHeader();           // Display title
    Account* createAccount();       // Create new account and pass as Account ptr
    int getOptions();               // Get menu options from user
private:
    int choice;                     // Holds choice for menu
    Account* newAccount;            // Pointer to new account
};

#endif /* NEWACCOUNTMENU_H */

