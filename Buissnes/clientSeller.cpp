#include "clientSeller.h"


//c`tor
ClientSeller::ClientSeller(const string & userName, const string & name, const string & password, const Address &address)
	: User(userName, name, password, address), Client(userName, name, password, address), Seller(name, userName, password, address)
{
}

//copy c`tor
ClientSeller::ClientSeller(const ClientSeller & copy) : User(copy) ,Seller(copy), Client(copy)
{
}

//move c`tor
ClientSeller::ClientSeller(ClientSeller && move) : User(move), Seller(move), Client(move)
{
}

//c`tor by file
ClientSeller::ClientSeller(ifstream & inFile) : User(inFile), Seller(inFile), Client(inFile)
{
}

//operator= to clientSeller
ClientSeller & ClientSeller::operator=(const ClientSeller & clientSeller)
{
	if (this != &clientSeller)
	{
		Client::operator=(clientSeller);
		Seller::operator=(clientSeller);
	}
	return *this;
}

//move operator= to ClientSeller
ClientSeller & ClientSeller::operator=(ClientSeller && clientSeller)
{
	if (this != &clientSeller)
	{
		Client::operator=(clientSeller);
		Seller::operator=(clientSeller);
	}
	return *this;
}

//d`tor
ClientSeller::~ClientSeller()
{
}

//print to ClientSeller using user print
void ClientSeller::print() const 
{
	User::print();
}