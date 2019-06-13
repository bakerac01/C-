// CIS 251 - Programming project 7 by Alan Baker
// Project is an example of queries in a simulation environment

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "queue.h"

using namespace std;

int main()
{

srand(time(NULL)); //seeds the random  number generator 


queue HealthTime; //stack that will be used




    int total_minutes = 10,    // total number of minutes in the simulation
        print_minutes = 1,    // print results every print_minutes minutes
        max_number_of_bags = 400,  // largest number of luggage bags on a flight
                                   // bag amounts will be randomly  
                                   // set from 50 to max_number_of_bags)
        add_flights = 3,           // number of flights landing each minute 
        total_bags = 400,    // total number of bags the baggage carrousel can handle per minute
        baggage_carrousels,   // number of baggage luggage carrousels
        random = 0,
		sum = 0;			//used for the random number generation   
 
   cout << "Please enter the number of baggage carrousels: ";
   cin >> baggage_carrousels;
   cout << endl;
   
   for (int min = 1; min <= total_minutes; min++)
   	{
   		for (int i = 0; i < add_flights; i++)
   		{
   			random = rand() % (max_number_of_bags - 50 + 1) + 50;
   			HealthTime.enqueue(random);					//enques the random number
		   }
		   
		for (int b = 0; b < baggage_carrousels; b++)
		{
			sum = 0;
			while(sum <= total_bags)
			{
				sum = sum + HealthTime.peek();
				if (sum < total_bags && !HealthTime.empty() )
				{
				HealthTime.dequeue();
				}else{
				break;
				}
			}
		   } 
		if(min % print_minutes == 0 )  
		{
			cout << endl << "Current Minute: " << min << endl;
			HealthTime.elements();
			HealthTime.print();
			cout << "Total # of Bags in Queue: " << HealthTime.elements() << endl;
			
		}
	}
  
   
   return 0;


}
