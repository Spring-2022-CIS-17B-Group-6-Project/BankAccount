/*
 * File: AccountTest.cpp
 * Author: Joseph Hernandez
 * Created on 05/25/22 10:05PM
 * Last modified on June 3, 2022 6:20PM by Liliana Darch
 * Purpose: Test the account class to ensure it functions properly
 * 
 */

#include "Account.h"
#include "Checking.h"
#include "Saving.h"

// Function Prototypes
void account(float, float);
void checkAccount();
void savingAccount();

void CheckingDeposit(Checking& );
void CheckingWithdraw(Checking& );
void CheckingCharges(Checking& );



int main(int argv, char** argc){
    float balance, aInterest;
    
    balance = 500.00;
    aInterest = 2.5;
    
    int choose;  // Holds the option the user selects

    do{
        //Display the menu
        cout<<endl;
        cout<<"*********** BANK ACCOUNT ***********"<<endl<<endl;
        cout<<"Press 1 - ACCOUNT "<<endl;
        cout<<"Press 2 - CHECKING ACCOUNT"<<endl;
        cout<<"Press 3 - SAVINGS ACCOUNT"<<endl;
        cout<<"Press 4 - EXIT BANK ACCOUNT PROGRAM"<<endl;
        cout<<endl;
        cout<<"Please select an option: ";
        cin >> choose;
        
        //Menu
        switch(choose){
            case 1:account(balance, aInterest);break;
            case 2:checkAccount();break;
            case 3:savingAccount();break;
            default:cout<<"Exiting the Main Menu"<<endl;
        }

    } while(choose>=1 && choose<=3);

    return 0;
}





//---------------------------------------------------//
//           ACCOUNT TEST FUNCTIONS                  //
//---------------------------------------------------//


void account(float balance, float aInterest) {
    Account newAccount(balance, aInterest);
    
    newAccount.deposit(500.00);
    newAccount.withdraw(250.00);
    newAccount.setDepPerMo(15);
    
    //cout << "Your account number is: " << newAccount.getAccountNumber() << endl;

    cout<<"Deposits per month               = " << newAccount.getDepPerMo() << endl;
    newAccount.setWithPerMo(3);
    
    cout<<"Withdraws per month              = "<< newAccount.getWithPerMo() << endl;
    
    
    cout<<"Account balance                  = $" << newAccount.getBalance()<<endl;
    
    newAccount.setBalance(1800);
    cout<<"New account balance              = $" << newAccount.getBalance()<<endl;
    
    newAccount.setMCharges(45.00);
    
    cout<<"Original annual interest rate    = " << newAccount.getAInterest() << "%"<<endl;
    
    newAccount.setAInterest(3.5);
    
    cout<<"New annual interest rate         = " << newAccount.getAInterest() << "%" << endl;
    
    
    cout<<"Calling newAccount.monthlyProc()"<<endl;
    newAccount.monthlyProc();
    cout<<"New account info:" <<endl;
    cout<<"\tBalance             = $" << newAccount.getBalance()  << endl;
    cout<<"\tAnnual Interest     = " << newAccount.getAInterest() << "%" << endl;
    cout<<"\tMonthly Charges     = $" << newAccount.getMCharges() << endl;
    cout<<"\tDeposits per month  = " << newAccount.getDepPerMo()  << endl;
    cout<<"\tWithdraws per month = " << newAccount.getWithPerMo() << endl;
    
    cout <<endl<<endl;
    
}





//---------------------------------------------------//
//           CHECKING TEST MENU                      //
//---------------------------------------------------//

void checkAccount() {
    Checking newChecking(500.00f, 0.85f);
    //cout << "Your checking account number is: " << newChecking.getAccountNumber() << endl;

    cout << "Checking balance                            = $" << newChecking.getBalance() << endl;

    int chooseChecking;  // Holds the option

    //Initialize variables here
    do {
        //Display the menu
        cout << endl;
        cout << "*********** TEST CHECKING ***********" << endl << endl;
        cout << "Press 1 - DEPOSIT" << endl;
        cout << "Press 2 - WITHDRAW" << endl;
        cout << "Press 3 - CHARGES" << endl;
		cout << "Press 4 - BACK TO MAIN EXIT" << endl;
        cout << endl;
        cout << "Please select an option: ";
        cin >> chooseChecking;

        //Menu
        switch (chooseChecking) {
        case 1:CheckingDeposit(newChecking); break;
        case 2:CheckingWithdraw(newChecking); break;
        case 3:CheckingCharges(newChecking); break;
        default:cout << "Exiting the Checking Menu" << endl;
        }

    } while (chooseChecking >= 1 && chooseChecking <= 3);
}

//---------------------------------------------------//
//           CHECKING TEST FUNCTIONS                 //
//---------------------------------------------------//

    // DEPOSIT IN CHECKING ACCOUNT
    void CheckingDeposit(Checking& newChecking){
    
        float depositAmnt;
        cout<<"Please enter the amount you would like to deposit: $";
        cin>>depositAmnt;

        newChecking.deposit(depositAmnt);
        cout <<"Checking balance after " <<  depositAmnt <<" deposit     = $"<<newChecking.getBalance()<<endl;
    }

    // WITHDRAW IN CHECKING ACCOUNT
    void CheckingWithdraw(Checking& newChecking){
        float minusAmount;
        cout<<"Please enter the amount you would like to withdraw: $";
        cin>>minusAmount;

        newChecking.withdraw(minusAmount);
        cout <<"Checking balance after " <<  minusAmount <<" withdraw     = $"<<newChecking.getBalance()<<endl;
    }

    // BALANCE IN CHECKING ACCOUNT
    void CheckingCharges(Checking& newChecking){
        cout<<endl;
        newChecking.monthlyProc();
        cout << endl << endl;
    }

	

    
//---------------------------------------------------//
//            SAVINGS TEST FUNCTIONS                 //
//---------------------------------------------------//

void savingAccount() {
    cout << endl << endl;
    // Savings account
    Saving newSavings(300.00f, 8.7f);
    //cout << "Your saving account number is: " << newSavings.getAccountNumber() << endl;
    
    cout <<"Savings balance                      = $"<<newSavings.getBalance()<<endl;
    
    newSavings.deposit(300.00);
    newSavings.deposit(150.00);
    newSavings.deposit(50.00);
    
    cout<<"Savings Balance after $500 deposit   = $"<<newSavings.getBalance()<<endl;
    
    newSavings.withdraw(500.00);
    newSavings.withdraw(500.00); // This should cause the account to go negative
    
    newSavings.withdraw(5.00);//Attempt to withdraw $5 from balance -$200
    
    newSavings.deposit(250.00);// Bring account back to $50
    
    cout<<"Account balance                      = $"<<newSavings.getBalance()<<endl;
    
    newSavings.withdraw(5.00);
    cout<<"Account balance                      = $"<<newSavings.getBalance()<<endl;
    
    //cout <<"Checking before transfer = $"<<newChecking.getBalance()<<endl;
    cout <<"Savings before transfer  = $"<<newSavings.getBalance()<<endl;
    
    
    //newChecking.transfer(newSavings, 100.00);
    
    cout <<"Transfer $100.00 from checking into savings"<<endl;
    //cout <<"Checking balance = $"<<newChecking.getBalance()<<endl;
    cout <<"Saving balance   = $"<<newSavings.getBalance()<<endl;
    
    cout<<"Attempting to transfer $250.00 from savings to checking..."<<endl;
    
    //newSavings.transfer(newChecking,250.00);
    
    cout<<"Calling newSavings.monthlyProc()"<<endl;
    newSavings.monthlyProc();
    cout<<"New account info:" <<endl;
    cout<<"\tBalance             = $" << fixed << setprecision(2) << newSavings.getBalance()  << endl;
    cout<<"\tAnnual Interest     = " << newSavings.getAInterest() << "%" << endl;
    cout<<"\tMonthly Charges     = $" << newSavings.getMCharges() << endl;
    cout<<"\tDeposits per month  = " << newSavings.getDepPerMo()  << endl;
    cout<<"\tWithdraws per month = " << newSavings.getWithPerMo() << endl;
    
}