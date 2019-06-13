#include "productType.h"
using namespace std;

	productType::productType()				
	{
		productName = "";
		id = "";
		manufacturer = "";
		quantitiesInStock = 0;
		price = 0.0;
		discount = 0.0;
	}
	
	productType::productType(int quantitiesInStock, double price, double discount) 
	{
		set( " ", " ", " ", quantitiesInStock, price, discount);
		
	}
	productType::productType(string id, int quantitiesInStock, double price, double discount) 
	 {
	 	set(" ", id, " ", quantitiesInStock, price, discount);
	 }
	
	productType::productType(string productName, string id, string manufacturer, int quantitiesInStock, double price, double discount ) 
	{
		set(productName, id,  manufacturer, quantitiesInStock,  price, discount);
	}
	
void productType::set(string p , string i, string m, int q, double pr, double d)
{
	productName = p;
    id = i;
    manufacturer = m;
    quantitiesInStock = q;
    price = pr;
    discount = d;
}

void productType::print() const
{
    cout << "Product Name: " << productName << "\n"
        << "Product ID: " << id << "\n" 
        << "Manufacturer: " << manufacturer << "\n"
        << "Quantities In Stock: " << quantitiesInStock << "\n"
        << "Price: " << price << "\n"
        << "Discount: " << discount << "\n";
    cout << endl << "**************" << endl;
}

void productType::setQuantitiesInStock(int x) 
{
	quantitiesInStock = x;
}

void productType::updateQuantitesInStock(int x)
{
	quantitiesInStock = x;
}

int productType::getQuantitiesInStock() const
{
	return quantitiesInStock;
}

void productType::setPrice(double x) 
{
	price = x;
}

double productType::getPrice() const 
{
    return price;
}

void productType::setDiscount(double d) 
{
	discount = d;
}

double productType::getDiscount() const
{
	return discount;
	}
	
string productType::returnID() const
{
	return id;
}
