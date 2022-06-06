/*
 * File: Menu.cpp
 * Author: Joseph Hernandez
 * Created on 06/05/2022, 5:36 PM
 * Purpose: Menu Class Implementation
 */


#include "Menu.h"
#include "MainMenu.h"

void MainMenu::displayHeader(){
    cout<<setw(53)<<"Welcome to the DHL Banking System"<<endl;
    cout<<setw(12)<<"-";
    for(int i =0;i<49;i++){
        cout<<"-";
    }
    cout<<endl<<endl;
    cout<<setw(55)<<"Please select from the following options:"<<endl;
}

int MainMenu::getOptions(){
    int choice;
    displayHeader();
    cout<<setw(40)<<"1. Create New Account"<<endl;
    cout<<setw(29)<<"2. Deposit"<<endl;
    cout<<setw(30)<<"3. Withdraw"<<endl;
    cout<<setw(38)<<"4. Print Statements"<<endl;
    cout<<setw(31)<<"5. New Month"<<endl;
    cout<<setw(26)<<"6. Exit"<<endl;
    cout<<setw(12)<<"-";
    for(int i =0;i<49;i++){
        cout<<"-";
    }
    cout<<endl;
    cout<<setw(26)<<"Selection: ";
    cin>>choice;

    return choice;
}