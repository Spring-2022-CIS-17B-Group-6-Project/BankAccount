/* 
 * File:   Menu.h
 * Author: Joseph Hernandez
 *
 * Created on June 5, 2022, 4:31 PM
 */

#ifndef MENU_H
#define MENU_H

class Menu{
public:
    virtual void displayHeader() = 0;
    virtual int getOptions() = 0;
};

#endif /* MENU_H */

