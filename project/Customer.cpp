#include"Customer.h"


Customer::Customer(int Ariv ,int Tran)
{
	ArivalTime = Ariv;
	TransTime = Tran;

}

Customer::~Customer()
{
}



int Customer::GetTransTime()
{
	return TransTime;
}

int Customer::GetWaitingTime(int x)
{
	WaitingTime = x - ArivalTime;
	return WaitingTime ;
}

int Customer::GetArrivalTime()
{
	return ArivalTime;
}
