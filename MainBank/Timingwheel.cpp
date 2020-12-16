#include "Timingwheel.h"
#include <iostream>

using namespace std;

Timingwheel::Timingwheel(int maxDelay)
{
	current_slot = 0;
	waitCount = 0;
	servTimeCount = 0;
	averageWaitingTime = 0;
	averageServiceTime = 0;
	custCount = 0;
	size = maxDelay + 1;
	slots = new Partition[size];
	/*for (int i = 0; i < size; i++) {
		slots[i] = NULL;
	}*/
}

void Timingwheel::insert(ATM* p1) {
	Customer* nextCust = p1->getFirst();
	if (nextCust == nullptr) {
		cout << "ATM #" << p1->getNum() << " has EMPTY queue. No one is serving."<<endl;
		return;
	}
	int servTime = nextCust->getserviceTime();
	cout <<"Customer #" << nextCust->getID() \
		 <<" with Service time = " << servTime \
		 <<" started using ATM #" << p1->getNum() << endl;
	Partition part(p1);
	//Partition is inserted in correct slot with calculated index: 
	int index = (current_slot + servTime) % size; //mod makes it circular
	std::cout << "Index: " << index << endl;
	Partition* current = &slots[index];
	if (current->getATM() == nullptr) {
		slots[index] = part;
	}
	else {
		while (current->getNext() != nullptr) {
			current = (current->getNext());
		}
		current->setNext(new Partition(part));
	}
}

void Timingwheel::schedule(int simulationTime)
{
	Partition* current = &slots[current_slot];
	Customer* servedCust;
	Customer* nextCust;
	ATM* curATM;	
	if (current->getATM() != nullptr) 
	{
		while (current != nullptr) 
		{
			curATM = current->getATM();
			//Removed Served customers
			servedCust = curATM->getFirst();
			servedCust->setexitTime(simulationTime);
			cout << "Customer #" << servedCust->getID() << " left ATM #" << curATM->getNum() << endl;
			int arrivalTime = servedCust->getarrivalTime();
			int endingTime = servedCust->getexitTime();
			int servTime = servedCust->getserviceTime();
			int startTime = endingTime - servTime;
			int waitingTime = startTime - arrivalTime; 
			waitCount += waitingTime; 
			servTimeCount += servTime; 
			custCount++;
			curATM->delCust();//removing servedCust
			//Add new customers to be served to the free ATM Partition:
			insert(curATM);
			current = (current->getNext());

		}	
		averageWaitingTime = waitCount / custCount;
		averageServiceTime = servTimeCount / custCount;
	}

}



void Timingwheel::clear_current_slot() {
	//cout << "Clearing current slot - SLOT #" << current_slot;
	slots[current_slot] = Partition();
}

ostream& operator<<(ostream& out, Timingwheel& tw)
{
	cout << endl<<"------------------TIMING WHEEL-------------------" << endl;
	for (int i = 0; i < tw.size; i++) {
		if (i == tw.current_slot) {
			cout << "CURRENT SLOT -> ";
		}
		else {
			cout << "                ";
		}
		cout << i << " " << tw.slots[i] << endl;
	}
	return out;
}
