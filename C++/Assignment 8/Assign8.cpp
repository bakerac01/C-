#include <cstdlib>
#include <iostream>
#include "queue.h"
/*
    Testing program for queue member functions elements and print.
*/

using namespace std;

int main(int argc, char *argv[])
{
    // declare a queue called qute
    queue qute;
    cout << "\n\nThe queue to start is:\n";
    // print the queue 
    qute.print();
    // print the number of elements in the queue
    cout << "\nNumber of elements to start is " << qute.elements();
    
    // enqueue the letters H, I, P, P and O
    
    	qute.enqueue('H');
    	qute.enqueue('I');
    	qute.enqueue('P');
    	qute.enqueue('P');
    	qute.enqueue('O');
    	
    cout << "\n\nThe queue after enqueueing is:\n";
    // print the queue 
    qute.print();
    // print the number of elements in the queue
    cout << "\nNumber of elements after enqueueing is " << qute.elements();
    
    // dequeue three elements
    
    qute.dequeue();
    qute.dequeue();
    qute.dequeue();
    
    // enqueue the letters K, E and R

	qute.enqueue('K');
	qute.enqueue('E');
	qute.enqueue('R');


    cout << "\n\nThe final queue is:\n";
    // print the queue 
    qute.print();
    
    // print the number of elements in the queue
    cout << "\nNumber of elements in final queue is " << qute.elements();

    cout << "\n\n";
    return 0;
}
