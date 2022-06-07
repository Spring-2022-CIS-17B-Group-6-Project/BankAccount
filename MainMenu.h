/* 
 * File:   MainMenu.h
 * Author: Joseph Hernandez
 *
 * Created on June 5, 2022, 5:38 PM
 */
#include <iostream>
#include <iomanip>

using namespace std;

#include "Menu.h"

#ifndef MAINMENU_H
#define MAINMENU_H



class MainMenu : public Menu{
public:
    void displayHeader();       // Display Title
    int getOptions();           // Get menu options from user
};

#endif /* MAINMENU_H */

