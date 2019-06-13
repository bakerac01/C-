//Code by Alan Baker.
// project 3-10 A B C


#include "productType.h"
#include <fstream>

//function delcerations
void getProductData(productType products[], int &numOfProducts);
void showMenu();

using namespace std;

int main(int argc, char** argv) {

// variable delcerations	
	productType products[100];
	int numOfProducts =0;
	int choice;
	string PID;
	int i = 0;
	int UDQ = 0;
	double tempPrice = 0;

// this is the function that inputs the data.
	getProductData(products, numOfProducts);
	
	// launches the menu after data is loaded and adds in users selection.
	showMenu();
    cin >> choice;
    cout << "~~~~~~~~~~~~~~~~~~~" << endl;

//Switch for whatever the users selects on the menu
	while (choice !=99)
	{
		switch (choice)
		{
			case 1:    //Case one searches for an ID that the user input.  Problem getting the error message to always display.
				PID = "";
				cout << "Enter Product ID: " << PID;
				cin >> PID;
				for (i = 0; i < numOfProducts; i++)
				
				if (products[i].returnID() == PID)
					{
					  products[i].print();
				}
					
				if (i == numOfProducts)
				{
				cout << "Could not find ID.  Please Try Again." << endl;
				break;
				}
				break;
			
			
			case 2: //Case 2 prints out every item stored in the array.
				for (i = 0; i < numOfProducts; i++)
				products[i].print();
			break;
				
			case 3: // change product quantity in the array
				PID = "";
				cout << "Enter Product ID: " << PID;
				cin >> PID;
				for (i = 0; i < numOfProducts; i++)
				
				if (products[i].returnID() == PID)
					{
					  cout << "Please Enter New Quantity:  ";
					  cin >> UDQ;
					  products[i].updateQuantitesInStock(UDQ);
				}
				if (i == numOfProducts)
				{
				cout << "Could not find ID.  Please Try Again." << endl;
				}
			break;
			
			case 4: // change product price in the array
				PID = "";
				cout << "Enter Product ID: " << PID;
				cin >> PID;
				for (i = 0; i < numOfProducts; i++)
				
				if (products[i].returnID() == PID)
					{
					  cout << "Please Enter New Price:  ";
					  cin >> tempPrice;
					  products[i].setPrice(tempPrice);
				}
				if (i == numOfProducts)
				{
				cout << "Could not find ID.  Please Try Again." << endl;
				}
			
			break;
			
			case 5: // change a discount price in the array
				PID = "";
				cout << "Enter Product ID: " << PID;
				cin >> PID;
				for (i = 0; i < numOfProducts; i++)
				
				if (products[i].returnID() == PID)
					{
					  cout << "Please Enter Discount:  ";
					  cin >> tempPrice;
					  products[i].setDiscount(tempPrice);
				}
				if (i == numOfProducts)
				{
				cout << "Could not find ID.  Please Try Again." << endl;
				}
			break;
			
			case 6:	// add a product
				string p = "";
				string i = "";
				string m = "";
				int q = 0;
				double pr = 0.0;
				double di = 0.0;
				
				
				
				
				cout << "Enter Product Name:" << endl;
				cin >> p; 
				cout << "Enter ID: " << endl;
				cin >> i;
				cout << "Enter Manufacturer: " << endl;
				cin >> m;
				cout << "Enter Quantity: " << endl;
				cin >> q;
				cout << "Enter Price: " << endl;
				cin >> pr;
				cout << "Enter Discount: " << endl;
				cin >> di; 
				
			products[numOfProducts].set(p, i, m, q, pr, di)	;
							numOfProducts = numOfProducts++;
			

			
			
			
			
		}
		// relaunches the menu after the switch.
		showMenu();
		cin >> choice;
	} 
  	return 0;
}

void getProductData(productType products[], int& numOfProducts)
{
	string productName;
	string id;
	string manufacturer;
	int quantitesInStock;
	double price;
	double discount;
	int i = 0;
	
	ifstream infile;
	
	infile.open("project03binput.txt");
	 if(!infile)
       {
         cout << "Unable to open input file. "<< endl;
         cout << "Terminating program ! "<< endl;
            return;
    	}
    infile >> productName >> id >> manufacturer >> quantitesInStock >> price >> discount;
     while ( !infile.eof())
         {
           products[i].set(productName, id, manufacturer, quantitesInStock, price,  discount);
           infile >> productName >> id >> manufacturer >> quantitesInStock >> price >> discount;
           numOfProducts++;
           i++;
         }
          infile.close();       
}


void showMenu()
{
	cout << "Welcome to Jenna and Eddy's Appliance Store" << endl << endl;
	cout << "To make a selection enter the number and press enter" << endl << endl;
	cout << "      1: Display the information for a specific product" << endl;
	cout << "      2: Display the information for all the products" << endl;
	cout << "      3: Change a product quantity" << endl;
	cout << "      4: Change a product price" << endl;
	cout << "      5: Change a discount" << endl;
	cout << "      6: Add a product" << endl;
	cout << "      99: Exit the program" << endl;
}
