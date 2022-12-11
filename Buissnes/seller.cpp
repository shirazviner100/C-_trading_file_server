#include "seller.h"
#include "product.h"
#include "feedback.h"

//c`tor for seller by values
Seller::Seller(const string & name, const string & userName, const string & password, const Address & address)
	: User(name, userName, password,address)
{
}

Seller::Seller(ifstream & inFile) : User(inFile)
{
}

Seller::Seller(const Seller& copy) : User(copy)
{
	this->feedbacks = copy.feedbacks;

	vector<Product*>::const_iterator itr = copy.products.begin();
	vector<Product*>::const_iterator itrEnd = copy.products.end();

	for (; itr != itrEnd; ++itr)
	{
		this->products.push_back(new Product(*(*itr)));
	}
}

Seller::Seller(Seller && move) : User(move)
{
	this->feedbacks = std::move(move.feedbacks);
	this->products = std::move(move.products);
}

Seller & Seller::operator=(const Seller & seller)
{
	if (this != &seller)
	{
		this->feedbacks = seller.feedbacks;
		
		vector<Product*>::const_iterator itr = seller.products.begin();
		vector<Product*>::const_iterator itrEnd = seller.products.end();

		for (; itr != itrEnd; ++itr)
		{
			this->products.push_back(new Product(*(*itr)));
		}
	}
	return *this;
}

Seller & Seller::operator=(Seller && seller)
{
	if (this != &seller)
	{
		User::operator=(seller);

		this->feedbacks = std::move(seller.feedbacks);
		this->products = std::move(seller.products);
	}
	return *this;
}

//d`tor for seller (free por the dynamic arrays)
Seller::~Seller()
{
	vector<Product*>::iterator itr = products.begin();
	vector<Product*>::iterator itrEnd = products.end();
	//loop to delete all prodcts alloction of this seller
	for (; itr != itrEnd; ++itr)
	{
		delete *itr;
	}

	//loop to delete all the sellers feedback allocation
	for (int i = 0; i < this->feedbacks.getLogSize(); i++)
	{
		delete this->feedbacks[i];
	}
}


void Seller::addProduct(Product *product)
{
	if (this->products.size()==this->products.capacity())	//check if there is avaliable place in the products array
	{
		this->products.reserve(this->products.size() * 2);
	}

	this->products.push_back(product);			//inseret the produt address to the seller product`s array									//plus one to the log size of the array
	cout << "\n----- The product: " << product->getName() << " added to your account! -----\n";
}

//print function for the seller info
void Seller::print() const
{
	User::print();
}

//loop to print all seller`s feedbacks info
void Seller::printSellerFeedbacks() const
{
	cout << this->feedbacks << endl;
}

//the function check if the feedbacks array as avaliable place if not she make realloc for the array and add the feedback
void Seller::insertFeedback(Feedback *feedback)
{

	this->feedbacks += feedback;
	cout << "\n----- The feedback added successfully! -----\n";
}

//the function get bar code and return the product from the product array if the barcode is not exsist n the array the function return nullptr
Product * Seller::searchProductByBarCode(int barCode)
{
	vector<Product*>::iterator itr = products.begin();
	vector<Product*>::iterator itrEnd = products.end();

	//loop to search the product that his bar code is equal to barCode parameter
	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getBarcode() == barCode)
			return *itr;
	}
	return nullptr;
}


void Seller::printProductArr() const
{
	vector<Product*>::const_iterator itr = products.begin();
	vector<Product*>::const_iterator itrEnd = products.end();

	for (; itr != itrEnd; ++itr)
	{
		cout << *(*itr) << endl;
	}
}

