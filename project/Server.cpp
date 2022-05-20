#include "Server.h"
 bool Server::IsAvailable()
{
     if (TimeToFinish == 0)
     {
         return true;
     }
	return false;
}

 void Server::SetTimeToFinish(int x)
 {
     TimeToFinish = x;
     
 }

 int Server::GetTimeTOFinish()
 {
     return TimeToFinish;
 }

 void Server::UpdateTime()
 {
     if (TimeToFinish > 0)
     TimeToFinish--;
 }

 LinkedQueue<Customer*>* Server::GetWaitingQueue()
 {
     return WaitingQueue;
 }

 
 Server::Server()
 {
 }

 Server::~Server()
 {
 }

 void Server::SetQueue(LinkedQueue<Customer*>* x) 
 {
     WaitingQueue = x;
 }

