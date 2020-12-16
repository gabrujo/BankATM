#include "Bank.h"

void Bank::set_inputfile(string file)
{
	inputFile = file;
	trafficGen = TrafficGenerator(inputFile);
	//trafficGen.displayInfo();
}

void Bank::set_atm_num(int atm)
{
	atmNum = atm;
	int maxTime = trafficGen.maxServiceTime(); //for debug
	systemControl = SystemController(atmNum, maxTime);
}


void Bank::generate_customerbase()
{
	allCustomers = trafficGen.initCustomerBase();
	cout << "Generated customer base: " << allCustomers.size() << endl;
}

void Bank::simulate()
{
	systemControl.startSim(simTime, trafficGen.getDynCust(), allCustomers);
}

void Bank::get_user_input() {
	int ATMs = 0, timeT = 0;
	string fname = "";
	cout << "Please specify input file name:\n";
    cin >> fname;
	set_inputfile(fname);
	cout << "Number of ATMs:\n";
	cin >> ATMs; 
	set_atm_num(ATMs);
	cout << "Simulation time:\n";
	cin >> timeT;
	set_sim_time(timeT);
}

void Bank::print_final_statistics() {
	statsKeeper.report(systemControl.getTimingWheel(), simTime, atmNum);
}
