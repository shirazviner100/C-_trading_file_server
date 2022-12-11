#ifndef  __ORDER_H
#define __ORDER_H

using namespace std;
#include "date.h"
#include <vector>
class Client;
class Product;

struct OrderItems
{
	Product * product;			//pointer to the product that the client bought
	bool allowFeedback;			//boolean object to know if the client can or can not give feedback
};

class Order
{
private:
	double totalPrice;			// the order's total price
	Client & owner;				// the buyer of the 
	Date date;					// date of reservation
	vector< OrderItems> orderCart;		// products in the reservation

	void placeOrderCart(const vector<Product*> & orderCart);

public:
	Order(const vector<Product*> & orderCart, Client & owner); // c'tor
	Order(const Order & copy);
	Order(Order && move);		

	// operators=
	Order& operator=(const Order & order);
	Order& operator=(Order && order);


	// getters 
	const double getTotalPrice() const { return totalPrice; }
	Client & getOwner() const { return owner; }
	const Date getDate() const { return date; }
	vector< OrderItems> & getOrderCart() { return orderCart; }

	// class methods
	void print() const;
	friend ostream & operator<<(ostream & os, const Order & order);
	void calculateTotalPrice();

};



#endif // ! __ORDER_H