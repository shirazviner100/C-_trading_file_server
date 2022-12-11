#include "product.h"


//c`tor by values
Product::Product(const string & name, const eCategory & category, double price ,Seller & sellerData)
	: barCode(serialCounter++), sellerData(sellerData)
{
	this->setName(name);
	this->setPrice(price);
	this->setCategory(category);
}


//set for product name data
bool Product::setName(const string & name)
{
	if (name.size() >= MAX_NAME_SIZE) //check string length validation
	{
		cout << "The name must contain " << (MAX_NAME_SIZE - 1) << " letters or less." << endl;
		return false;
	}

	this->name = name;
	return true;
}

//set product price
bool Product::setPrice(double price)
{
	if (price <= 0)	//the price must be bigger than 0$
	{
		cout << "The price must be positive number, nothing is for free. " << endl;
		return false;
	}

	this->price = price;
	return true;
}

//set the product category
void Product::setCategory(const eCategory &category)
{
	this->category = category;
}

//operator<< (cout) to Product class
 ostream & operator<<(ostream & os, const Product & product)
{
	 os << "Product name: " << product.name << "\nSeller user name: " << product.sellerData.getUserName() <<
		 "\nBar code: " << product.barCode << "\nCategory: " << product.categoryName[product.category] << "\nPrice: " << product.price << "$\n\n";
	 return os;
 }

int Product::serialCounter = 10000;