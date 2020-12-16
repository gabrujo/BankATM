#include "Partition.h"
#include <iostream>

using namespace std;

Partition::Partition(ATM* _atm)
{
    atm = _atm;
    nextp = nullptr;
}

Partition* Partition::getNext()
{
    return nextp;
}

void Partition::setNext(Partition* nextptr)
{
    nextp = nextptr;
}

ATM* Partition::getATM()
{
    return atm;
}

ostream& operator<<(ostream& out, Partition& p)
{
    if (p.atm != nullptr) {
        cout <<"Partition with C"<<p.atm->getFirst()->getID()<<\
            "("<< p.atm->getFirst()-> getserviceTime()<<")"\
            " using ATM #" << p.atm->getNum() <<"->";
    }
    if (p.nextp != nullptr) {
        cout << *(p.nextp);
    }
    return out;
}
