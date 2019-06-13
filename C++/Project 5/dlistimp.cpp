
#include "dlist.h"

//constructor logic
dlist::dlist()
{
front = NULL;
current = NULL;
}

//Insert function logic.
	// building the node
void dlist::insert(char c)
{
	dlist_node *p;

if(front == NULL) { //list is empty
	p = new dlist_node;
	p -> back = NULL;
	p -> contents = c;
	p -> next = NULL;
	current = p;
	front = p;
} else {
		if (current -> next == NULL && front !=NULL)
			{
			p = new dlist_node;
			p -> back = current;
			p -> contents = c;
			p -> next = NULL;
			current -> next = p; //dont think this is right either
			current = p;
			} else {
				p = new dlist_node;
				p -> back = current;
				p -> contents = c;
				p -> next = current -> next;
				current -> next = p;
				current = p; //not sure if this is right. says assign a value?
			}
}

p = NULL;
}
//remove logic
void dlist::remove()
{
	dptr temp1;
	dptr temp2;
	
	if ( front != NULL){	//checks that list is not empty
		if (front == current && front -> next !=NULL){
			front = front -> next;
			front -> back = NULL; // this im not sure is right. says assign a value again?
			delete current;
			current = front;
		} else {
				if (front == current && front -> next == NULL){ // deleting first and only node
					front = NULL;
					delete current;
					current = front;
				} else {
					if (current -> next !=NULL){
						temp1 = current -> next;
						temp2 = current -> back;
						temp1 -> back = temp2;
						temp2 -> next = temp1;
						delete current;
						current = temp1;
						temp1 = NULL; //seems odd to assign temp1 then assign it to null?
						temp2 = NULL;
					} else {
						temp1 = current -> back;
						delete current;
						current = temp1;
						current -> next = NULL;
						temp1 = NULL;
						}
					}
				}
	}	
		
}

//move right logic
void dlist::move_right(int d)
{
	if (front !=NULL){
	
		for(int i = 0; i < d; i++){
			if(current -> next !=NULL){
				current = current -> next;
			}else{
				break;
			}
		}
	}
}
	
// move left logic
void dlist::move_left(int d)
{
	if (front !=NULL){
	
		for(int i = 0; i < d; i++){
			if(current -> back !=NULL){
				current = current -> back;
			}else{
				break;
			}
		}
	}
}
//print logic
void dlist::print()
{
	dptr mover;
	
	for (mover = front; mover !=NULL; mover = mover ->next)
	{
	
		if(mover !=current)
		{
			cout << mover -> contents;
		}else{
			cout << "{" << current -> contents << "}";
		}
	}
}
