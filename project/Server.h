#pragma once
#include<iostream>
#include "LinkedQueue.h"
#include"Customer.h"
class Server
{
public:
	Server();
	~Server();
	void SetQueue(LinkedQueue<Customer*>*);
	bool IsAvailable();
	void SetTimeToFinish(int);
	int GetTimeTOFinish();
	void UpdateTime();
	LinkedQueue<Customer*>* GetWaitingQueue();
private:
	LinkedQueue<Customer*>* WaitingQueue;
	int TimeToFinish = 0;
};




