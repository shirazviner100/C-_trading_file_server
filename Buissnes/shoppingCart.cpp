#include "ShoppingCart.h"
#include "product.h"
#include "client.h"

// c'tor
ShoppingCart::ShoppingCart(Client & owner) : owner(owner)
{
}

//copt c`tor
ShoppingCart::ShoppingCart(const ShoppingCart &copyCart) :owner(copyCart.owner)
{
	*this = copyCart;
}

//move c`tor to Shopping cart
ShoppingCart::ShoppingCart(ShoppingCart &&moveCart) : owner(moveCart.owner)
{
	*this = moveCart;
}

//opertaor= to Shopping cart
ShoppingCart & ShoppingCart::operator=(const ShoppingCart & oldCart) 
{
	if (this != &oldCart)
	{
		this->owner = oldCart.owner;

		vector<Product*>::const_iterator itr = oldCart.cart.begin();
		vector<Product*>::const_iterator itrEnd = oldCart.cart.end();

		for (; itr != itrEnd; ++itr)
		{
			this->cart.push_back(new Product(*(*itr)));
		}

		vector<Product*>::const_iterator itrO = oldCart.orderProducts.begin();
		vector<Product*>::const_iterator itrEndO = oldCart.orderProducts.end();

		for (; itrO != itrEndO; ++itr)
		{
			this->cart.push_back(new Product(*(*itrO)));
		}
	}
	return *this;
}

//operator= to Rvalue 
ShoppingCart & ShoppingCart::operator=(ShoppingCart && oldCart)
{
	if (this != &oldCart)
	{
		this->owner = oldCart.owner;
		this->cart = std::move(oldCart.cart);
		this->orderProducts = std::move(oldCart.orderProducts);
	}
	return *this;
}

void ShoppingCart::allocateOrderCart()
{
	this->orderProducts.clear();
}

//the function return the shopping cart total price
const double ShoppingCart::getTotalCartPrice() const
{
	double price = 0;
	vector<Product*>::const_iterator itr = this->cart.begin();
	vector<Product*>::const_iterator itrEnd = this->cart.end();

	for (; itr != itrEnd; ++itr)
	{
		price += (*itr)->getPrice();
	}
	return price;
}

// The function gets a pointer to a new product and adds it to the shopping cart
void ShoppingCart::addProduct(Product *newProduct)
{
	// if the physic size equals the logic size 
	if (this->cart.size() == this->cart.capacity())
	{
		this->cart.reserve(this->cart.capacity() * 2);
	}

	this->cart.push_back(newProduct);
}

 ostream &  operator<<(ostream & os, const ShoppingCart & cart)
{
	 os << "This is your shopping cart: " << endl;
	 int index = 0;
	 vector<Product*>::const_iterator itr = cart.cart.begin();
	 vector<Product*>::const_iterator itrEnd = cart.cart.end();

	 for (; itr != itrEnd; ++itr)
	 {
		 cout << "Product number " << index + 1 << ": \n" << *(*itr);
		 index++;
	 }
	 return os;
}

//adding the product into the order final cart
void ShoppingCart::addProductToOrderCart(Product * product)
{
	// if the physic size equals the logic size 
	if (this->orderProducts.size() == this->cart.capacity())
	{
		this->cart.reserve(this->orderProducts.capacity() * 2);
	}

	this->orderProducts.push_back(product);
}

void ShoppingCart::updateShoppingCart(vector<Product*> & newCart)
{
	this->cart.clear();
	vector<Product*>::iterator itr = newCart.begin();
	vector<Product*>::iterator itrEnd = newCart.end();

	for (; itr != itrEnd; ++itr)
	{
		this->cart.push_back(*itr);
	}
}

