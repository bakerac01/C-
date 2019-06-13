// implementation file for the queue class

#include <iostream>
using namespace std;

const int queue_size = 6;

class queue
{
      private:
         char data [queue_size]; // elements in the queue
         int front, // index to the front of the queue, indexes one previous
                    // to actual front element (remove)
             rear;  // index of the rear element;
      public:
         queue ();  // create an empty queue
         void enqueue (char item);   // adds an element to the rear
         char dequeue ();            // removes an element from the front
         bool empty ();              // returns true for an empty queue
         bool full ();               // returns true for a full queue
         int elements ();            // returns the number of elements in the queue
         void print ();              // prints the queue from front to rear
};

// returns the number of elements in the queue
int queue::elements ()
{
	int i, count =0;
    // no wrap-around
    if (front <= rear)
     for (i = front; i< rear; i++)
     count++;
    else // with wrap-around
          for (int i = front; i !=rear; i=(i++) % queue_size)
          count++;
    return count;
}

// prints the elements in the queue from first to last element
void queue::print ()
{
     int index;
     
     // no wrap-around
     if (front <= rear)
     
        // print elements from first to last
        for (index = front + 1 ; index <= rear ; index++ )
            cout << data[index];
      else // wrap-around
     {
         // print elements from front element to end of array
         for (index = front+1 ; index < queue_size ; index++ )
               cout << data[index];
         // print elements from beginning of array to rear
         for (index = 0  ; index <= rear ; index++ )
               cout << data[index];
     }
}

// constructor creates an empty queue
queue::queue ()
{
    front = 0;
    rear = 0;
}

// enqueue adds an element to the rear of the queue
void queue::enqueue (char item)
{
      // if full, can't add another element
      if (full ())
      {
          cout << "\n\nQueue Error: Can't add to a full queue";
          cout << "\nQueue will not be changed";
      }
      else // ok to add an item
      {
           rear = (rear + 1) % queue_size;
           data [rear] = item;
      }
}

// dequeue removes an element from the front of the queue
char queue::dequeue ()
{
     // if the queue is empty, we can't remove a value
     if (empty ())
     {
          cout << "\n\nQueue Error: Can't remove from an empty queue";
          cout << "\nReturning a blank";
          return ' ';
     }
     else // ok to remove a value
     {
          front = (front + 1) % queue_size;
          return data [front];
     }
}

// empty returns true if the queue is empty
bool queue::empty ()
{
     return front == rear;
}

// full returns true if the queue is full
bool queue::full ()
{
     return (rear + 1) % queue_size == front;
}






         
