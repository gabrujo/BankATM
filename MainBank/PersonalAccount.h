#include <iostream>
#include <string>
#include "Account.h"
#ifndef PERSONALACCOUNT_H_
#define PERSONALACCOUNT_H_

static int lastpersonalID = 1;

class PersonalAccount: public Account {
private:
	int personalID;
	string firstName;
	string lastName;
	int SSN; //9 digit 
	int generateSSN();
public:
	PersonalAccount(string f ="John", string l="Black");
};
#endif