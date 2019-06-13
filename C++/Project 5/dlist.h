// implementation file for the dlist

#include <cstdlib>
#include <iostream>
using namespace std;

struct dlist_node
{
  char contents;    // contents in the node
  dlist_node *back, // pointer to previous node in the list
             *next; // pointer to the next node in the list
};

typedef dlist_node* dptr;

class dlist
{
    private:
      dptr front,   // pointer to the front of the list
           current; // pointer to current node in the list
    public:
      dlist ();   // constructor creates an empty list
      void insert (char ch);  // inserts a new node           
      void remove ();        // removes a node      
      void move_right (int distance); // moves current to right
      void move_left (int distance);  // moves current to left
      void print ();   // prints the list
};

