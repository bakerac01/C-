// implementation file for the stack class

#include <iostream>
using namespace std;

const int stack_size = 100;

class stack
{
      private:
         int data [stack_size];  // elements in the stack
         int top;               // index of the top element of the stack 
      public:
         stack ();              // constructor creates an empty stack
         void push (int item); // adds an element to the top of the stack
         int pop ();           // removes and returns the top element
         bool empty ();         // returns true if stack is empty
         bool full ();          // returns true if stack is full
         void print();          // print function
         int elements();		// Elements member function
         int peek();			// returns the top element on the stack
};

// constructor creates an empty stack
stack::stack ()
{
   top = -1;
}

// push adds an element, item, to the top of the stack
void stack::push (int item)
{
     // if the stack is full, print an error message
     if (full ())
     {
         cout << "\n\nStack Class Error: Pushing on a full stack";
         cout << "\nElement being pushed is " << item;
     }
     else // OK to push the new element
     {
         top++;
         data [top] = item;
     }
}

// pop removes and returns the top element from the stack
int stack::pop ()
{
     // if the stack is empty, print an error message
     if (empty ())
     {
          cout << "\n\nStack Class Error: Popping an empty stack";
          cout << "\nReturning a ?";
          return -1;
     }
     else  // OK to pop the stack
     {
         top--;
         return data [top + 1];
     }
}

// empty returns true if the stack is empty, else it returns false
bool stack::empty ()
{
     return top == -1;
}

// full returns true if the stack is full, else it returns false
bool stack::full ()
{
     return top == stack_size - 1;
}

void stack::print()
{
	cout << "Packages in stack: \n";
	
	for (int x = top; x > -1; x--){
	cout << data[x] << " Vaccines" << endl;
}
	
}

int stack::elements()
{
	int temp1 = 0;
	for (int x = top; x > -1; x--){
	temp1++;
	}
	return temp1;
		
	 
}  

int stack::peek()
{
	
	if (empty())
	{
		return top == -1;
	} else {
		return data[top];
	}
	
}











    
