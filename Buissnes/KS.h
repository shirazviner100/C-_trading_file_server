#ifndef __KS_H
#define __KS_H

#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include"user.h"
#include "seller.h"
#include "client.h"
#include "clientSeller.h"
#include <vector>
using namespace std;

class KS
{
private:
	vector<User*> allUsers;
	int clientCounter, sellerCounter;

public:
	KS();
	KS(const KS& copy) = delete;
	~KS();

	//getters to the KS system
	vector<User*> getAllUsers() const { return this->allUsers; }

	void addUser(User * user);

	void printSellersUserName() const;
	Seller * searchSellerByUserName(const string & userName) const;

	//KS & operator+=(User & user);
	KS & operator+=(const Seller & seller);
	KS & operator+=(const Client & client);
	KS & operator+=(const ClientSeller & clientSeller);
	void showProductByName(const string &productName) const;

	void printAllClients() const;
	void printAllClientSellers() const;
	void printAllSellers() const;
	friend class Menu;

};


#endif // ! __KS_H