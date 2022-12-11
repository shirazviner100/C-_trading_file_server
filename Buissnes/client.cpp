#include "client.h"

// c`tor
Client::Client(const string & name, const string & userName, const string &password, const Address &address)
	: User(name,userName,password,address)
{
	this->makeEmptyCart();
	this->setWallet(50);
}

//c`tor by file
Client::Client(ifstream & inFile) :User(inFile)
{
	this->makeEmptyCart();
	this->setWallet(50);
}

// copy c'tor
Client::Client(const Client &copy) : User(copy)
{
	this->wallet = copy.wallet;

	this->cart = new ShoppingCart(*copy.cart);
	vector<Order*>::const_iterator itr = copy.historyOrder.begin();
	vector<Order*>::const_iterator itrEnd = copy.historyOrder.end();

	for (; itr != itrEnd; ++itr)
	{
		this->historyOrder.push_back(new Order(*(*itr)));
	}
}


// move c'tor
Client::Client(Client &&move) : User(move)
{
	this->wallet = move.wallet;
	this->historyOrder = std::move(move.historyOrder);

	this->cart = new ShoppingCart(*move.cart);
}

// operator = &
Client& Client::operator=(const Client & client)
{
	if (this != &client)
	{
		User::operator=(client);
		*this->cart = *client.cart;
		this->wallet = client.wallet;

		vector<Order*>::const_iterator itr = client.historyOrder.begin();
		vector<Order*>::const_iterator itrEnd = client.historyOrder.end();

		for (; itr != itrEnd; ++itr)
		{
			this->historyOrder.push_back(new Order(*(*itr)));
		}
	}
	return *this;
}


// operator = &&
Client& Client::operator=(Client && client)
{
	if (this != &client)
	{
		User::operator=(client);
		*this->cart = *client.cart;

		this->wallet = client.wallet;
		this->historyOrder = std::move(client.historyOrder);
	}

	return *this;
}

// destructor
Client::~Client()
{
	vector<Order*>::const_iterator itr = this->historyOrder.begin();
	vector<Order*>::const_iterator itrEnd = this->historyOrder.end();

	// loop to delete all the history order
	for (; itr != itrEnd; ++itr)
		delete *itr;

	delete this->cart;
}

// The function makes a new empty cart
void Client::makeEmptyCart()
{
	this->cart = new ShoppingCart(*this);				// dynamic allocation
	this->allocationCheckShoppingCart(this->cart);		// check allocation
}

// set wallet 
void Client::setWallet(double wallet)
{
	this->wallet = wallet;
}

// print client's name and address
void Client::print() const
{
	User::print();
}

// print the client's shopping cart 
void Client::printShoppingCart() const
{
	cout << this->cart << endl;
}

// The function adds money to the client's wallet
void Client::addMoney(double money)
{
	this->wallet = this->wallet + money;
}

/* The function gets a pointer to an order-items struct and returns boolean value if the
user allowed to leave a feedback */
bool Client::allowToGiveFeedback(OrderItems *productFeedback)
{
	// if the user allowed to feedback
	if (productFeedback->allowFeedback == true)
	{
		productFeedback->allowFeedback = false;
		return true;
	}

	return false;
}


/* The function gets a pointer to an order that the client made and inserts it to the history order array */
void Client::insertToHistoryOrder(Order *order)
{
	// if the logic size equals the physic size
	if (this->historyOrder.size() == this->historyOrder.capacity())
	{
		this->historyOrder.reserve(this->historyOrder.capacity() * 2);
	}

	this->historyOrder.push_back(order); 				// insert the new order
}


// The function adds feedback to the seller's array of feedbacks 
void Client::addFeedback(Feedback * feedback)
{
	// pointer to the seller of the product 
	Seller *sellerForFeedback = &feedback->getProductData().getSellerData();

	// add the feedback to the seller array
	sellerForFeedback->insertFeedback(feedback);
}


// prints the history order of the client
void Client::printHistoryOrder() const
{
	vector<Order*>::const_iterator itr = this->historyOrder.begin();
	vector<Order*>::const_iterator itrEnd = this->historyOrder.end();
	int count = 1;

	// loop to print all the history order
	for (; itr != itrEnd; ++itr)
	{
		cout << "\n\nOrder No. " << count << endl;
		(*itr)->print();
		count++;
	}
}


/* The function gets a bar code and returns a pointer to the wanted product */
OrderItems * Client::searchProductByBarCode(int barCode)
{
	vector<Order*>::iterator itrO = this->historyOrder.begin();
	vector<Order*>::iterator itrOEnd = this->historyOrder.end();

	// loop for moving over the orders in the history
	for (; itrO != itrOEnd; ++itrO)
	{
		vector<OrderItems>::iterator itrOI = (*itrO)->getOrderCart().begin();
		vector<OrderItems>::iterator itrOIEnd = (*itrO)->getOrderCart().end();

		// loop for moving over the products in the current order
		for (; itrOI != itrOIEnd; ++itrOI)
		{
			// if the bar code exists
			if ((*itrOI).product->getBarcode() == barCode)
				return &(*itrOI);
		}
	}

	return nullptr;
}


// check allocation ShoppingCart*
void Client::allocationCheckShoppingCart(ShoppingCart * ptr)
{
	if (ptr == nullptr)
	{
		cout << "Allocation failed\n";
		exit(1);
	}
}

bool Client::operator>(const Client & client) const
{
	return this->cart->getTotalCartPrice() == client.cart->getTotalCartPrice();
}