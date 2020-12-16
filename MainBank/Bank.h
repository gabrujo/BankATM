#ifndef BANK_h
#define BANK_h
#include "TrafficGenerator.h"
#include "StatisticsKeeper.h"
#include "SystemController.h"
#include "Timingwheel.h"


class Bank {
private:
	TrafficGenerator trafficGen;
	StatisticsKeeper statsKeeper;
	SystemController systemControl;
	vector<Customer>allCustomers;//vector of 200 Customers
	int atmNum;
	int simTime;
	string inputFile;

public:
	//Bank();
	void set_inputfile(string file);
	void set_atm_num(int atm);
	void get_user_input(); //get all the user specified values
	void set_sim_time(int time) { simTime = time; }
	void generate_customerbase(); 
	//void generate_initial_traffic();
	void simulate();
	void print_final_statistics(); //prints the final report of the simulation
	

};
#endif