#include "productType.h"
#include <fstream>

void getProductData(productType products[], int &numOfProducts);
void showMenu();


using namespace std;

int main(int argc, char** argv) {
	
	productType products[100];
	int numOfProducts =0;
	int choice;
	string PID;
	int i = 0;


	getProductData(products, numOfProducts);
	showMenu();
    cin >> choice;
    cout << "~~~~~~~~~~~~~~~~~~~" << endl;

	while (choice !=99)
	{
		switch (choice)
		{
			case 1:
				PID = "";
				cout << "Enter Product ID: " << PID;
				cin >> PID;
				for (i = 0; i < numOfProducts; i++)
				
				if (products[i].returnID() == PID)
					 products[i].print();
					
				if (i == numOfProducts)
				cout << "Could not find ID.  Please Try Again." << endl;
				break;
			
			
			case 2:
				for (i = 0; i < numOfProducts; i++)
				products[i].print();
				break;
				
				
				
			default :
				cout << "Invalid Selection." << endl;
		}
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
	cout << "      3: Change a product quantity(coming soon)" << endl;
	cout << "      4: Change a product price(coming soon)" << endl;
	cout << "      5: Change a discount(coming soon)" << endl;
	cout << "      6: Add a product(coming soon)" << endl;
	cout << "      99: Exit the program" << endl;
}
