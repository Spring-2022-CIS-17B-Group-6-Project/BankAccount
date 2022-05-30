/*
*	File: User.h
*	Author: Joseph Hernandez
*	Created on 05/30/22 12:15AM
*	Last modified on
*	Purpose: User class definition
*/


#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
public:
	User();							// Default constructor with no params
	User(string, string);			// Constructor to set fName and lName
	User(string, string, string);	// Constructor to set fName, lName, and loginID

	
	string setFName(string);
	string setLName(string);
	string setLoginID(string);
	string setPassword(string);
	
	inline void getFName() const { return fName; }
	inline void getLName() const { return lName; }
	inline void getLoginID() const { return loginID; }

	void verifyCredentials(string, string);		// Takes in loginID and password

private:
	string fName;	// First name
	string lName;	// Last name
	string loginID;	// Login ID
	string passWd;	// Password

};

#endif /* USER_H */
