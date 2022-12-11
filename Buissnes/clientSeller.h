#ifndef _CLIENTSELLER_H
#define _CLIENTSELLER_H

#include "client.h"
#include "seller.h"

class ClientSeller : public Client, public Seller
{
private:
	ClientSeller(const ClientSeller & copy);
	ClientSeller( ClientSeller && move);


public:
	ClientSeller(const string & userName, const string & name, const string & password, const Address &address);
	ClientSeller(ifstream & inFile);
	virtual ~ClientSeller();
	virtual void print() const override;

	ClientSeller & operator=(const ClientSeller & clientSeller);
	ClientSeller & operator=(ClientSeller && clientSeller);

	friend class KS;
};



#endif // !_CLIENTSELLER_H
