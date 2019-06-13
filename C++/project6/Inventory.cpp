// Programing project 6 by Alan Baker
// This is an exercise to dementosrate the use of stacks in a simulation enviornment. 

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "stack.h"

using namespace std;

int main()
{
    int total_days = 10,     // total number of days in the simulation
        print_days = 5,      // print results every print_days days
        max_package_size = 100,  // largest vaccine package in terms of how many vaccines
                                 // are in it  (packages sizes will be randomly  
                                 // set from 1 to max_package_size)
        add_packages = 10,       // number of packages added each minute 
        total_vaccines = 250,    // total number of vaccines a lab technical can process
                                 // test and ship a day 
        Lab_techs,           // number of postal workers read from user
        srand(time(NULL)),	// random number
        sum = 0,				//used for total number of vaccines counter
        random = 0;
        
        
        
    
        stack newstack; 
        
        cout << "Enter Number of Lab Techs:  "; // ask user for number of lab techs
        cin >> Lab_techs;
        
        for (int days = 1; days <= total_days; days++)
		{
			for(int b = 0; b < add_packages; b++)
			{
				random = rand() % 50 + 51;
				newstack.push(random);				//pushes the random number on top of the stack
			}
			
			for(int z = 0; z < Lab_techs; z++)
			{
				sum = 0;
				while(sum <= total_vaccines)
				{
					sum = sum + newstack.peek();
					if (sum < total_vaccines && !newstack.empty())
					
						newstack.pop();
					 else
						break;
					
				}
			}
				
				if(days % print_days ==0)
				{
					cout << endl << "Current Day: " << days << endl;
					newstack.elements();
					newstack.print();
					cout << "Number of packages in stack: " << newstack.elements() << endl;
				}
			}
		
		
		
           
   
   return 0;
}
