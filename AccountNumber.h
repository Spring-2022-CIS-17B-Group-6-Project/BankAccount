/* 
 * File:   AccountNumber.h
 * Author: Joseph Hernandez
 * Created on June 4, 2022, 11:45 PM
 */

#include<string>
using namespace std;

#ifndef ACCOUNTNUMBER_H
#define ACCOUNTNUMBER_H

class AccountNumber{
public:
    static unsigned int hashNumber(const string&);
};

#endif /* ACCOUNTNUMBER_H */

