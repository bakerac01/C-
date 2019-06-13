#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class productType
	{
		public:
			productType(); 										    	  
			productType(int, double, double);					    	
			productType(string, int, double, double); 					
			productType(string, string, string, int, double, double);	 
			
			void set(string, string, string, int, double, double);
			void print() const;
			
			void setQuantitiesInStock(int x);
			void updateQuantitesInStock(int x);
			int getQuantitiesInStock() const;
			
			void setPrice(double x);
			double getPrice() const;
			void setDiscount(double d);
			double getDiscount() const;
			string returnID() const;
			
		private:
			string productName = "";
			string id = "";
			string manufacturer = "";
			int quantitiesInStock = 0;
			double price = 0;
			double discount = 0;
	};
