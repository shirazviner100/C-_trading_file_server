#ifndef __CLIENT_H
#define __CLIENT_H

#pragma warning(disable:4996)
#include "shoppingCart.h"
#include "address.h"
#include "seller.h"
#include "feedback.h"
#include "product.h"
#include "order.h"
#include "user.h"
using namespace std;

class Client : virtual public User
{
protected:
	ShoppingCart * cart;					// pointer to the client's shopping cart
	vector <Order*> historyOrder;			// history order - array of old orders
	double wallet;							// wallet 

	// protected c'tors
	Client(const Client &copy);				// copy c'tor
	Client(Client &&move);					// move c'tor

	// protected methods
	bool allowToGiveFeedback(OrderItems *productFeedback);
	void makeEmptyCart();
	void allocationCheckShoppingCart(ShoppingCart * ptr);

public:
	Client(const string & userName, const string & name, const string &  password ,const Address &address);	// c'tor
	Client(ifstream & inFile);
	virtual ~Client();	// destructor
	friend class KS;

	// operators
	bool operator>(const Client & client) const;
	Client& operator=(const Client & client);
	Client& operator=(Client && client);

	// setters 
	void setWallet(double wallet);

	// getters 
	const double getWallet() const { return wallet; }
	ShoppingCart * getCart() const { return cart; }
	vector <Order*> & getHistoryOrder() { return this->historyOrder; }

	// class methods 
	void addFeedback(Feedback * feedback);
	void addMoney(double money);
	void insertToHistoryOrder(Order *order);
	virtual void print() const override;
	void printShoppingCart() const;
	void printHistoryOrder() const;
	OrderItems * searchProductByBarCode(int barCode);
};


#endif // __CLIENT_H

