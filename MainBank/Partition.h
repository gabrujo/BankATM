#ifndef PARTITION_h
#define PARTITION_h

#include "ATM.h"

class Partition
{
	private:
		ATM* atm;
		Partition* nextp; 	
	public:
		Partition(ATM* _atm = nullptr);
		friend ostream& operator<<(ostream&, Partition&);
		Partition* getNext();
		void setNext(Partition* nextptr);
		ATM* getATM();
		//we won't ever need to set ATM, so no setATM
};

#endif