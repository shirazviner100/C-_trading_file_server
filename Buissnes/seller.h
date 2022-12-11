#ifndef __SELLER_H
#define __SELLER_H

#pragma warning(disable:4996)
#include "address.h"
#include "user.h"
#include "Array.h"
#include <vector>
class Feedback;
class Product;


class Seller : virtual public User
{

protected:

	vector<Product*> products;					//seller products array
	Array<Feedback*> feedbacks;				//seller feedback array

	Seller(const Seller& copy);
	Seller(Seller && move);

public:
	Seller(const string & name, const string & userName, const string & password, const Address & address);
	Seller(ifstream & inFile);
	virtual ~Seller();

	Seller & operator=(const Seller & seller);
	Seller & operator=(Seller && seller);

	//getters for seller info - as inline functions
	vector<Product*> & getProducts() { return products; }
	Array<Feedback*> & getFeedback() { return feedbacks; }


	void addProduct(Product *product);
	Product * searchProductByBarCode(int barCode);
	void insertFeedback(Feedback *feedback);

	virtual void print() const override;

	void printSellerFeedbacks() const;
	void printProductArr() const;

	friend class KS;
};


#endif // __SELLER_H
