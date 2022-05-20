a C++ program to convert an infix expression that
includes (, ), +, -, *, and / to postfix.  useing stacks to implement this conversion.
b. Write a C++ program to convert a postfix expression to infix.  Useing binary tree algorithms to implement this conversion.
a probabilistic C++ simulation of a queuing
system with several queues and several servers, one server for each queue, as in a grocery or discount
store. Because there are several lines, each arriving customer always joins the line that is currently the
shortest. If several lines are equally short, the new arrival may join any one of them. A line with a free
teller is "shorter" than one whose teller is occupied. Once in a line, a customer does not leave it until
served.
The program will read from the terminal the parameters of the simulation---how many queue/server
pairs (maximum 10), the longest time for a customer transaction, the probability that a customer arrives
during a single tick, the duration of the simulation, and a seed value for the random number generator.
It will simulate the queuing system for the specified duration, showing a picture of the system at every
clock tick, then report some statistics: the average time each customer waited, the longest time any
customer waited, the number of customers served, and the numbers of customers left in queues.
The number of queue/server pairs, of course, is at least 1. The probability that a customer arrives during
one tick is a percentage, thus an integer between 0 and 100. Each transaction's time is random,
uniformly distributed between one tick and a positive maximum value entered from the terminal
