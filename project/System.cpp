#include"System.h"
#include<iostream>
#include <fstream>
System::System()
{
}

System ::~System()
{
}

void System::Load(std::string x)
{
	

	std::fstream Data;
	Data.open(x);
	if (Data.is_open()) {
		Data >> NumOfQueues >> ArrivalProp >> MaxTrans >> SimTime >> Seed;
		 ArrOfServers = new Server[NumOfQueues];
		 ArrOfWaiting = new LinkedQueue<Customer*>[NumOfQueues];
		
	
	}
	else
	{
		cout << "faild to open file\n";
	}

}

void System::Exicute()
{
	std::cout << "Enter the File Name\n";
	std::string x;
	std::cin >> x;
	Load(x);
	cout << NumOfCustServed;
	Customer* newCust;
	int CTick = 0;
	while (CTick <= SimTime)
	{
		if (Arrival(CTick))
		{
			srand(Seed);
			int x = (1 + (rand() % MaxTrans));

			newCust = new Customer(CTick, x ) ;
			
		}
		else
		{
			newCust = nullptr;
		}

		if (newCust) SetInWaiting(newCust);


		Assign(CTick);


		UpdateTime();


		Print(CTick);


		CTick++;
	}
	NumOfWaiting();
	cout << "The Number Of Customers Served IS >>>>>     " << NumOfCustServed << "    <<<<<\n";
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "the average waiting time (number of ticks) of the customers who were served IS >>>>" << (TotalWating / NumOfCustServed) << "<<<<<\n";
	cout << endl;
	cout << endl;
	cout << "the longest time any one customer waited IS >>>>" << TheLongestWaiting << "<<<<<\n";
	cout << endl;
	cout << endl;
	cout << "the number of customers left in queues when the simulation terminated IS >>>>>" << NumOfCustLeft << "<<<<<\n";

}

bool System::Arrival(int x)
{
	srand(x);
	if (1+( rand() % 100) <= ArrivalProp ) {
		return true;
	}
	else
	{
		return false;
	}
}

void System::SetInWaiting(Customer* x)
{
	if (x) {
		/*for (int i = 0; i < NumOfQueues; i++) {
			/*if (ArrOfServers[i].IsAvailable()&& ArrOfWaiting[i].GetCount() == 0)
			{
				ArrOfServers[i].SetTimeToFinish(x->GetTransTime());
				NumOfCustServed++;
				delete x;
				return;
			}

		}*/
		int Short = ArrOfWaiting[0].GetCount();
		
		int n = 0;
		for (int i = 0 ; i < NumOfQueues; i++) {
			if (Short > ArrOfWaiting[i].GetCount()) {
				Short = ArrOfWaiting[i].GetCount();
				n = i;
			}
		}
		ArrOfWaiting[n].enqueue(x);
	}
	
}

void System::Assign(int x)
{
	for (int i = 0; i < NumOfQueues; i++) {
		if (ArrOfServers[i].IsAvailable())
		{
			Customer* Nextserv;
			if (ArrOfWaiting[i].dequeue(Nextserv)) {
				ArrOfServers[i].SetTimeToFinish(Nextserv->GetTransTime());
				cout << Nextserv->GetTransTime() << endl;
				TotalWating = Nextserv->GetWaitingTime(x) + TotalWating;
				NumOfCustServed++;
				if (Nextserv->GetWaitingTime(x) > TheLongestWaiting) {
					TheLongestWaiting = Nextserv->GetWaitingTime(x);
					delete Nextserv;
				}
			}
		}
	}

}

void System::Print(int x)
{
	Customer* prin;
	cout << "Current Tick is >>>>" << x << "<<<<\n";
	for (int i = 0; i < NumOfQueues; i++) {
		cout << "SERVER number     " << i + 1 << "     Will Finish after   " << ArrOfServers[i].GetTimeTOFinish() << endl;
		cout << "   Its Queue Of Waiting Customers is   ";
		LinkedQueue<Customer*> Pr(ArrOfWaiting[i]);
		while (Pr.dequeue(prin)){
			cout <<"    "<< prin->GetArrivalTime() << "     ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	cout << endl;
}

void System::UpdateTime()
{
	for (int  i = 0; i <NumOfQueues ; i++)
	{
		ArrOfServers[i].UpdateTime();
		
	}

}

void System::NumOfWaiting()
{
	
	Customer* m;
	for (int i = 0; i < NumOfQueues; i++) {
		while (ArrOfWaiting[i].dequeue(m)) {
			NumOfCustLeft++;
		}
	}
	
}
