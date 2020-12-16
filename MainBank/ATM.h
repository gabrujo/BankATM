#ifndef ATM_h
#define ATM_h

#include <queue>
#include "Customer.h"
#include <iostream>

class ATM {
private:
	int number;
	int cashLeft;
	queue<Customer> custs;
public:
	ATM(int num = -1, int cash = 10000) { number = num; cashLeft = cash; }
	int getNum() { return number; }
	int getCashLeft() { return cashLeft; }
	bool addCust(Customer cust); //enqueue Customer
	void delCust() { custs.pop(); }//deque Customer
	Customer* getFirst();//return first Customer in queue or nullptr if not there
	int getCustNum() { return custs.size(); }
	//refillCash()


};
#endif // !ATM_h