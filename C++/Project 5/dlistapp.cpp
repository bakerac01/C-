/*

    Programming Project 5 Application File
    
*/

#include <cstdlib>
#include <iostream>
#include "dlist.h"
using namespace std;

int main(int argc, char *argv[])
{
    char choice, ch;
    int distance;
/****  Declare a dlist variable      ****/
    dlist myDlist;
    cout << "Select p (print), i (insert), d (delete), r (right),";
    cout << "\n   l (left) or q (quit): ";
    cin >> choice;
    
    while (choice != 'q')
    {
          switch (choice)
          {
                 case 'p' : cout << "\nThe list is:\n";
/****  Call the print member function to print the dlist    ****/
							myDlist.print();
                            cout << endl;
                            break;
                 case 'i' : cout << "\nEnter the character to insert: ";
                            cin >> ch;
/****  Call the insert member function to insert ch in the dlist   ****/
							myDlist.insert(ch);
                            break;
                 case 'r' : cout << "\nEnter the distance to move right: ";
                            cin >> distance;
/****  Call the move_right member to move current to the right distance spots    ****/
							myDlist.move_right(distance);
                            break;
                 case 'l' : cout << "\nEnter the distance to move left: ";
                            cin >> distance;
/****  call the move opperator to do some cool stuff    ****/
							myDlist.move_left(distance);
                            break;
                 case 'd' : 
/****  Call the remove member function to remove the node pointed to by current      ****/
						myDlist.remove();
                            cout << endl;
                            break;
                 default  : cout << "\nMust enter p, i, d, r, l, or q!\n";
          }    
          cout << "\nSelect p (print), i (insert), d (delete), r (right),";
          cout << "\n   l (left) or q (quit): ";
          cin >> choice;
    }
    
    cout << "\n\nEditing Complete\n\n";
          
    
    return 0;
}
