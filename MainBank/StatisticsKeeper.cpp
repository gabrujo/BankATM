#include <iostream>
#include "StatisticsKeeper.h"

StatisticsKeeper::StatisticsKeeper() {

}

void StatisticsKeeper::report(Timingwheel obj, int duration, int noATMS) 
{
	cout << "\n\n*******************************************************************" << endl;
	cout << "************************ FINAL STATISTICS *************************" << endl;
	cout << "Duration of simulation is " << duration<<endl;
	cout << "Number of ATMs is " << noATMS<<endl;
	cout<< "Total number of customers served is "<< obj.getCustCount() << endl;
	cout << "The average service time is "<<obj.getAvgServTime()<<endl;
	cout << "The average waiting time is " <<obj.getAvgWaitTime()<< endl;
	cout << "********************************************************************" << endl;
	cout << "********************************************************************" << endl << endl;

}



