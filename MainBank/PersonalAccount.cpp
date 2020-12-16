#include "PersonalAccount.h"

PersonalAccount::PersonalAccount(string fn, string ln)//implicitly calls Account()
{
	personalID = lastpersonalID; // starts assigning IDs from 1 and goes up using static count currentID
	lastpersonalID++;
	firstName = fn;
	lastName = ln;
	SSN = generateSSN();
}

int PersonalAccount::generateSSN() {
	int i = 0, j = 0;
	i = rand() % 9 + 1;
	for (int k = 1; k < 4; k++) {
		i = i * 10 + rand() % 10;      //Generate the next 3 digits.
	}
	for (int k = 0; k < 5; k++) {
		j = j * 10 + rand() % 10;      //Generate the 5 digits of the lower part.
	}
	int res = i * 1000 + j;
	return res;
}