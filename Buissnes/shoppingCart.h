#ifndef __SHOPPING_CART_H
#define __SHOPPING_CART_H

#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include "order.h"
class Client;
class Product;

class ShoppingCart
{

private:
	Client & owner;							// pointer to the client who own the cart
	vector<Product*> cart;						// shopping cart 
	vector<Product*> orderProducts;				// order cart 

public:
	ShoppingCart(Client & owner);							// c'tor
	ShoppingCart(const ShoppingCart &copyCart);				//copy c`tor
	ShoppingCart(ShoppingCart &&moveCart);			//move c`tor
	ShoppingCart & operator=(const ShoppingCart & oldCart);	//operator=
	ShoppingCart & operator=(ShoppingCart && oldCart);		//move operator=

	// getters 
	vector<Product*> & getShoppingCart() { return cart; }
	vector<Product*> & getOrderProducts() { return orderProducts; }
	Client & getOwner() const { return owner; }
	const double getTotalCartPrice() const;

	// class methods
	friend ostream &  operator<<(ostream & os, const ShoppingCart & cart);
	void addProduct(Product *newProduct);
	void allocateOrderCart();
	void addProductToOrderCart(Product * product);
	void updateShoppingCart(vector<Product*> & newCart);

};

#endif // __SHOPPING_CART_H

