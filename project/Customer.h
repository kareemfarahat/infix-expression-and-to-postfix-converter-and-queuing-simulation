#pragma once
#include <iostream>
class Customer
{
public:
	Customer(int , int );
	~Customer();
	int GetTransTime();
	int GetWaitingTime(int);
	int GetArrivalTime();
private:
	int ArivalTime;
	int TransTime = 0;
	int WaitingTime;
};

