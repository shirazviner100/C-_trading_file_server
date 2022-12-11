#include "KS.h"


KS::KS()
{
	this->clientCounter = this->sellerCounter = 0;
}

KS::~KS()
{
	//loop to delete all the clients allocation
	vector<User*>::iterator itr = allUsers.begin();
	vector<User*>::iterator itrEnd = allUsers.end();

	for (; itr != itrEnd; ++itr)
	{
		delete (*itr);
	}
}


//function to add user to the system
void KS::addUser(User *user)
{
	if (this->allUsers.size() == this->allUsers.capacity())
	{
		this->allUsers.reserve(this->allUsers.capacity() * 2);
	}

	this->allUsers.push_back(user);
}



//function to print all products in the system with the same product name
void KS::showProductByName(const string & productName) const
{
	int counter=0;
	if (this->sellerCounter > 0)
	{
		cout << "\n---------------------------------------------\n";
		cout << "The products named '" << productName << "' are:\n";
		cout << "---------------------------------------------\n\n";
		//loop to check all sellers / ClientSellers by there products name
		vector<User*>::const_iterator itr = allUsers.begin();
		vector<User*>::const_iterator itrEnd = allUsers.end();

		for (;itr != itrEnd; ++itr)
		{
			Seller * tempSeller = dynamic_cast<Seller*>(*itr);
			if (tempSeller)	//the user is Seller
			{
				if (tempSeller->getProducts().size() > 0)
				{
					vector<Product*>::iterator itrP = tempSeller->getProducts().begin();
					vector<Product*>::iterator itrPend = tempSeller->getProducts().end();
					for (; itrP != itrPend; ++itrP)
					{
						if ((*itrP)->getName() == productName)
						{
							counter++;
							cout << *(*itrP) << endl;
						}
					}
				}
			}
		}

		if (counter == 0)
			cout << "------- There are no products with this name -------\n";
	}
	else
		cout << "------- Sorry, there are no sellers in the system -------\n";

}

//the function get seller user name and chck if the seller exsist in the sellers aray
Seller * KS::searchSellerByUserName(const string & userName) const
{
	if (this->sellerCounter > 0)
	{
		vector<User*>::const_iterator itr = allUsers.begin();
		vector<User*>::const_iterator itrEnd = allUsers.end();
		for (; itr != itrEnd; ++itr)
		{
			Seller * tempSeller = dynamic_cast<Seller*>(*itr);

			if ((tempSeller) && (userName == (*itr)->getUserName()))
				return tempSeller;
		}
	}
	return nullptr;
}


//all clients array alloctaion check
void KS::printSellersUserName() const
{
	if (this->sellerCounter > 0)
	{
		cout << "\n---------------------------------------------\n";
		cout << "\tOur Sellers: \n";
		cout << "---------------------------------------------\n\n";

		vector<User*>::const_iterator itr = allUsers.begin();
		vector<User*>::const_iterator itrEnd = allUsers.end();
		for (; itr != itrEnd; ++itr)
		{
			Seller * tempSeller = dynamic_cast<Seller*>(*itr);

			 if(tempSeller)
				(*itr)->printUserName();
		}
	}
	else
		cout << "-------- There are no sellers in the system --------\n";
}


//operator += to add client
KS & KS::operator+=(const Client & client)
{
	Client * temp = new Client(client);
	this->addUser(temp);
	this->clientCounter++;
	return *this;
}

//operator += to add Seller
KS & KS::operator+=(const Seller & seller)
{
	Seller * temp = new Seller(seller);
	this->addUser(temp);
	this->sellerCounter++;
	return *this;
}

//operator += to add Seller
KS & KS::operator+=(const ClientSeller & clientSeller)
{
	ClientSeller * temp = new ClientSeller(clientSeller);
	this->addUser(temp);
	this->clientCounter++;
	this->sellerCounter++;
	return *this;
}

// print all sellers info
void KS::printAllSellers() const
{
	// if there are sellers in the system
	if (this->sellerCounter > 0)
	{
		Seller * temp;

		cout << "\n---------------------------------------------\n";
		cout << "\tOur Sellers: \n";
		cout << "---------------------------------------------\n\n";

		vector<User*>::const_iterator itr = allUsers.begin();
		vector<User*>::const_iterator itrEnd = allUsers.end();
		// loop to print all the seller's data
		for (; itr != itrEnd; ++itr)
		{
			temp = dynamic_cast<Seller *>(*itr);
			if (temp)
			{
				temp->print();
				cout << endl;
			}
		}
	}
	else
		cout << "----- There are no sellers in the system -----\n";
}

// print clients data
void KS::printAllClients() const
{
	// if there are clients in the system
	if (this->clientCounter > 0)
	{
		Client * temp;

		cout << "\n---------------------------------------------\n";
		cout << "\tOur Clients: \n";
		cout << "---------------------------------------------\n\n";

		vector<User*>::const_iterator itr = allUsers.begin();
		vector<User*>::const_iterator itrEnd = allUsers.end();
		// loop for moving over the users array
		for (; itr != itrEnd; ++itr)
		{
			temp = dynamic_cast<Client *>(*itr);
			if (temp)
			{
				temp->print();
				cout << endl;
			}
		}
	}

	// else, there are no clients in the system
	else
		cout << "----- There are no clients in the system -----\n";
}


// print clients-sellers data
void KS::printAllClientSellers() const
{
	int counter = 0;

	// if there are clients-seller in the system

	ClientSeller * temp;

	cout << "\n---------------------------------------------\n";
	cout << "\tOur Clients-Sellers: \n";
	cout << "---------------------------------------------\n\n";

	vector<User*>::const_iterator itr = allUsers.begin();
	vector<User*>::const_iterator itrEnd = allUsers.end();
	// loop for moving over the users array
	for (; itr != itrEnd; ++itr)
	{
		temp = dynamic_cast<ClientSeller *>(*itr);
		if (temp)
		{
			temp->print();
			cout << endl;
			counter++;
		}
	}

	// else, there are no clients-sellers in the system
	if (counter == 0)
		cout << "----- There are no clients-sellers in the system -----\n";
}
