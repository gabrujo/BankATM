#include <iostream>
#include <string>
#ifndef TRANSACTION_H_
#define TRANSACTION_H_
using namespace std;

enum class TransactionType { Deposit = 1, Transfer, Withdraw };

class Transaction {
private:
	double amount;
	TransactionType type;
public:
	Transaction(double amount, TransactionType transactionType = TransactionType::Deposit);//Withdraw by default
};

#endif
