#pragma once
#include<iostream>
#include"LinkedQueue.h"
#include"Customer.h"
#include "Server.h"

class System 
{
public:
	System ();
	~System ();
	void Load(std::string);
	void Exicute();
	bool Arrival(int);
	void SetInWaiting(Customer*);
	void Assign(int);
	void Print(int);
	void UpdateTime();
	void NumOfWaiting();

private:
	int TotalWating = 0; // Sum Of All waiting time of customers
	int NumOfQueues = 0; // numper of pairs Queues/ servers
	int ArrivalProp = 0; //The probability that a customer arrives in one tick (%)
	int MaxTrans = 0; //The maximum duration of a transaction in ticks:
	int Seed = 0; //a random number seed:
	int SimTime = 0; //The duration of the simulation in ticks:
	int NumOfCustServed = 0; //the number of customers served
	int AverageWaiting = 0; //the average waiting time (number of ticks) of the customers who were served
	int TheLongestWaiting = 0 ; // the longest time any customer waited
	int NumOfCustLeft = 0; //the number of customers left in queues when the simulation terminated.
	Server*ArrOfServers; // LIst of Servers
	LinkedQueue<Customer*>* ArrOfWaiting;// List of waiting customer Queues
};

