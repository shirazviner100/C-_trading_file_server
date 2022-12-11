#include "order.h"
#include "client.h"
#include "product.h"

// c'tor
Order::Order(const vector<Product*> & orderCart, Client & owner) :owner(owner)
{
	this->placeOrderCart(orderCart);
	this->calculateTotalPrice();
}

//coty c`tor to Order class
Order::Order(const Order & copy) : owner(copy.owner)
{
	*this = copy;
}

//move c`tor to Order class
Order::Order(Order && move) : owner(move.owner)
{
	*this = move;
}

// operator = &
Order& Order::operator=(const Order & order)
{
	if (this != &order)
	{
		this->orderCart = order.orderCart;
		this->date = order.date;
		this->owner = order.owner;
		this->totalPrice = order.totalPrice;

		this->orderCart = order.orderCart;
	}
	return *this;
}


// operator = &&
Order& Order::operator=(Order && order)
{
	if (this != &order)
	{
		this->date = order.date;
		this->owner = order.owner;
		this->totalPrice = order.totalPrice;
		
		this->orderCart = std::move(order.orderCart);
	}
	return *this;
}

//the function insert to the order array the producrt array that we get from the client
void Order::placeOrderCart(const vector<Product*> & orderCart)
{
	vector<Product*>::const_iterator itr = orderCart.begin();
	vector<Product*>::const_iterator itrEnd = orderCart.end();

	//looop to reserve the products pointers
	for (; itr != itrEnd; ++itr)
	{
		OrderItems temp;
		temp.allowFeedback = true;
		temp.product = *itr;
		this->orderCart.push_back(temp);
	}
}


// The function calculates the total price of the order
void Order::calculateTotalPrice()
{
	this->totalPrice = 0;
	vector<OrderItems>::iterator itr = this->orderCart.begin();
	vector<OrderItems>::iterator itrEnd = this->orderCart.end();

	for (; itr != itrEnd; ++itr)
		this->totalPrice += (*itr).product->getPrice();
}


// The function prints the order
void Order::print() const
{
	vector<OrderItems>::const_iterator itr = this->orderCart.begin();
	vector<OrderItems>::const_iterator itrEnd = this->orderCart.end();

	// loop for printing all the products in the reservation
	for (; itr != itrEnd; ++itr)
	{
		cout << *(*itr).product;
	}

	cout << "Total price: " << this->totalPrice <<"$\n"<< endl;
}


 ostream & operator<<(ostream & os, const Order & order)
{
	 vector<OrderItems>::const_iterator itr = order.orderCart.begin();
	 vector<OrderItems>::const_iterator itrEnd = order.orderCart.end();

	 // loop for printing all the products in the reservation
	 for (; itr != itrEnd; ++itr)
	 {
		 os << *(*itr).product;
	 }

	 os << "Total price: " << order.totalPrice << "$\n" << endl;

	 return os;
}