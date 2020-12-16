#include "Transaction.h"

Transaction::Transaction(double am, TransactionType transType)
{
	type = transType;
	amount = am;
}
