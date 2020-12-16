#include "ATM.h"

bool ATM::addCust(Customer cust)
{
    /*add the Customer to customer queue.
    return true if this customer is first, false otherwise */
    bool ifFirst = false;
    if (custs.size() == 0) {
        ifFirst = true;
    }
    custs.push(cust); 
    return ifFirst;
}

Customer* ATM::getFirst()
{
    /*returns first Customer in queue or nullptr if noone is there*/
    if(custs.size()!=0){
        return &(custs.front()); 
    }
    return nullptr;
}
