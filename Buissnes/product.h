#ifndef __PRODUCT_H
#define __PRODUCT_H

#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include "seller.h"
#include<string>
using namespace std;

class Product
{
public:
	static constexpr int MAX_NAME_SIZE = 20;
	enum eCategory { KIDS, ELECTRICITY, OFFICE, FASHION, HEALTH, SPORTS, HOME, DEALS };	//enum for the products category
	const char* categoryName[8] = { "KIDS", "ELECTRICITY" , "OFFICE", "FASHION", "HEALTH", "SPORTS", "HOME", "DEALS" };		//definition of the catagorys as stings

private:
	static int serialCounter;			//serial number run from 10000

	string name;			//product name value
	const int barCode;					//unique barCode value
	eCategory category;					//product Catagory
	double price;						//product price
	Seller & sellerData;			//the seller pointer can`t change


public:
	Product(const string & name,const eCategory &category, double price,Seller &sellerData);

	//setters for product values
	bool setName(const string & name);
	void setCategory(const eCategory &category);
	bool setPrice(double price);

	//getters function as inline functions
	const string & getName() const { return name; }
	const int getBarcode() const { return barCode; }
	const eCategory getCategory() const { return category; }
	const double getPrice() const { return price; }
	Seller & getSellerData() const { return sellerData; }
	
	friend ostream & operator<<(ostream & os, const Product & product);

};

#endif // __PRODUCT_H