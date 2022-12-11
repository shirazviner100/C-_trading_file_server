#ifndef  __FEEDBACK_H
#define __FEEDBACK_H

#pragma warning(disable:4996)
using namespace std;
#include "date.h"
#include<string>
class Client;
class Product;

class Feedback
{
public:
	static constexpr int FEEDBACK_SIZE = 100;

private:
	Client & client;
	Date date;
	string note;
	Product & productData;

public:
	Feedback(Client & client, const string & note, Product & productData);

	//setters for Feedback
	bool setNote(const string & note);

	//getters -functions by inline
	Client & getClient() const { return client; }
	const Date getDate() const { return date; }
	const string & getNote() const { return note; }
	Product & getProductData() const { return productData; }

	friend ostream & operator<<(ostream & os, const Feedback & date);
};



#endif // ! __FEEDBACK_H