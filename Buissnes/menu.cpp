#include "menu.h"

//c`tor to menu
Menu::Menu(KS* business) : business(business)
{
}

///c`ctor to menu
Menu::Menu(const Menu & copy) : business(copy.getBusiness())
{
}

//m`ctor to menu
Menu::Menu(Menu && move) : business(move.getBusiness())
{
}

//d`ctor to menu
Menu::~Menu()
{
	delete this->business;
}

void Menu::mainMenu()
{
	short res;
	char fileName[this->MAX_NAME_SIZE] = "KS.txt";
	this->uploadData(fileName);
	cout << "---------------------------------------------\n";
	cout << "\tWelcome to KS business!\n";
	cout << "---------------------------------------------\n\n";

	cout << "To SIGN IN please press '" << this->SIGN_IN << "'\nTo LOG IN please press \t'" << this->LOG_IN << "'\n";
	cout << "To SHUT DOWN the system please press '" << this->SHUT_DOWN << "'\n";
	cout << "To Check operators please press '" << this->CHECK_OPERATORS << "'\n";
	res=getInputShort();
	
	while (res != this->SIGN_IN && res != this->LOG_IN && res!= this->SHUT_DOWN && res != this->CHECK_OPERATORS)
	{
		cout << "\nPlese enter '" << this->SIGN_IN << "' , '" << this->LOG_IN << "' or '"<<this->SHUT_DOWN<<"'.\n";
		res = getInputShort();
	}

	if (res == this->SIGN_IN)
		this->signIn();

	else if (res == this->LOG_IN)
		this->logIn();

	else if (res == this->SHUT_DOWN)
	{
		this->shutDown();
		delete business;
		system("pause");
		exit(0);
	}
	else
		this->checkOperators();
}

//menu action to seller user
void Menu::sellerMenu(Seller * seller)
{
	short res;
	char clean;
	string productName;
	cout << "\n---------------------------------------------\n";
	cout << "\tWelcome " << seller->getUserName() << endl;
	cout << "---------------------------------------------\n\n";

	cout << "\nThis is your Menu:\n\n";
	cout << "To EXIT, press '" << this->EXIT << "'.\n";
	cout << "To search product by name, press '" << this->SHOW_PRODUCT << "'.\n";
	cout << "To watch all the clients details, press '" << this->SHOW_CLIENT << "'.\n";
	cout << "To watch all the sellers details, press '" << this->SHOW_SELLER << "'.\n";
	cout << "To watch all the seller details, press '" << this->SHOW_CLIENT_SELLER << "'.\n";
	cout << "To add product, press '" << (this->ADD_PRODUCT - 3) << "'.\n";


	res = getInputShort();
	do
	{
		clean = getchar();
		switch (res)
		{

		case this->EXIT:
			this->mainMenu();
			break;

		case this->SHOW_PRODUCT:
			cout << "\n---------------------------------------------\n";
			cout << "\tShow products\n";
			cout << "---------------------------------------------\n\n";
			cout << "Please enter the name of the product that you would like to search\n";
			this->getString(this->MAX_NAME_SIZE, productName);
			this->business->showProductByName(productName);
			break;

		case this->SHOW_CLIENT:
			this->business->printAllClients();
			break;

		case this->SHOW_SELLER:
			this->business->printAllSellers();
			break;

		case this->SHOW_CLIENT_SELLER:
			this->business->printAllClientSellers();
			break;

		case (this->ADD_PRODUCT - 3):
			seller->addProduct(this->createNewProduct(seller));
			break;

		default:
			cout << "----- NOT VALIDE VALUE -----\n";
			this->sellerMenu(seller);
		}

		cout << "\n---------------------------------------------\n";
		cout << "\tThis is your Menu:\n\n";
		cout << "To EXIT, press '" << this->EXIT << "'.\n";
		cout << "To search product by name, press '" << this->SHOW_PRODUCT << "'.\n";
		cout << "To watch all the clients details, press '" << this->SHOW_CLIENT << "'.\n";
		cout << "To watch all the sellers details, press '" << this->SHOW_SELLER << "'.\n";;
		cout << "To watch all the seller details, press '" << this->SHOW_CLIENT_SELLER << "'.\n";
		cout << "To add product, press '" << (this->ADD_PRODUCT - 3) << "'.\n";
		cout << "---------------------------------------------\n\n";
		res = getInputShort();
		while (res < 0 || res > 5)
		{
			cout << "\n----- unvalide value, please try again -----\n";
			res = getInputShort();
		}

	} while (1);

}

//function contain the client posibole action
void Menu::clientMenu(Client * client)
{
	char clean;
	short res;
	Order * order;
	string productName, temp;
	cout << "\n---------------------------------------------\n";
	cout << "\tWelcome " << client->getUserName() << endl;
	cout << "---------------------------------------------\n\n";

	cout << "\nThis is your Menu:\n\n";
	cout << "To EXIT, press '" << this->EXIT << "'.\n";
	cout << "To search product by name, press '" << this->SHOW_PRODUCT << "'.\n";
	cout << "To watch all the clients details, press '" << this->SHOW_CLIENT << "'.\n";
	cout << "To watch all the sellers details, press '" << this->SHOW_SELLER << "'.\n";
	cout << "To watch all the seller details, press '" << this->SHOW_CLIENT_SELLER << "'.\n";
	cout << "To add feedback, press '" << this->ADD_FEEDBACK << "'.\n";
	cout << "To add a product to your shopping cart, press '" << this->SHOP_PRODUCT << "'.\n";
	cout << "To create an order, press '" << this->CREATE_ORDER << "'.\n";

	res = getInputShort();
	do
	{
		clean = getchar();
		switch (res)
		{
		case this->EXIT:
			this->mainMenu();
			break;

		case this->SHOW_PRODUCT:
			cout << "\n---------------------------------------------\n";
			cout << "\tShow products\n";
			cout << "---------------------------------------------\n\n";
			cout << "Please enter the name of the product that you would like to search\n";
			this->getString(this->MAX_NAME_SIZE, productName);
			this->business->showProductByName(productName);
			this->business->showProductByName(productName);
			break;

		case this->SHOW_CLIENT:
			this->business->printAllClients();
			break;

		case this->SHOW_SELLER:
			this->business->printAllSellers();
			break;

		case this->SHOW_CLIENT_SELLER:
			this->business->printAllClientSellers();
			break;

		case this->ADD_FEEDBACK:
			this->checkValidationForFeedback(client);
			break;

		case this->SHOP_PRODUCT:
			this->shopProduct(client);
			break;
			
		case this->CREATE_ORDER:
			this->pickProductsToOrder(client);

			if (client->getCart()->getOrderProducts().size() > 0)	//the order cart is not empty
			{
				order = this->createOrder(client);
				this->checkout(order);
			}
			break;


		default:
			cout << "----- NOT VALIDE VALUE -----\n";
			this->clientMenu(client);

		}

		cout << "\n---------------------------------------------\n";
		cout << "\tThis is your Menu:\n\n";
		cout << "To EXIT, press '" << this->EXIT << "'.\n";
		cout << "To search product by name, press '" << this->SHOW_PRODUCT << "'.\n";
		cout << "To watch all the clients details, press '" << this->SHOW_CLIENT << "'.\n";
		cout << "To watch all the sellers details, press '" << this->SHOW_SELLER << "'.\n";
		cout << "To watch all the seller details, press '" << this->SHOW_CLIENT_SELLER << "'.\n";
		cout << "To add feedback, press '" << this->ADD_FEEDBACK << "'.\n";
		cout << "To add a product to your shopping cart, press '" << this->SHOP_PRODUCT << "'.\n";
		cout << "To create an order, press '" << this->CREATE_ORDER << "'.\n";
		cout << "---------------------------------------------\n\n";
		res = getInputShort();

		while (res < 0 || res > 7)
		{
			cout << "\n----- unvalide value, please try again -----\n";
			res = getInputShort();
		}

	} while (1);

}

//function to sign in for clients or sellers
void Menu::signIn()
{
	short res;
	User * getUser;
	cout << "\n---------------------------------------------\n";
	cout << "\t\tSIGN IN" << endl;
	cout << "---------------------------------------------\n\n";

	cout << "To sign in as a client please press '" << this->CLIENT << "' \nTo sign in as a seller please press '" << this->SELLER
		<< "'\n" << "To sign in as client&seller please press '" << this->CLIENT_SELLER << "'\n";
	res = getInputShort();

	while (res != this->CLIENT && res != this->SELLER && res != this->CLIENT_SELLER)
	{
		cout << "\nPlese enter '" << this->CLIENT << "' , '" << this->SELLER << "' , '" << this->CLIENT_SELLER << "'.\n";
		res = getInputShort();
	}

	getUser = this->addNewSystemUser(res);

	if (res == this->CLIENT)	//start the client menu with the user parameter
	{
		Client * temp = dynamic_cast<Client*>(getUser);
		*(this->business) += *temp;
		delete temp;
		vector<User*>::iterator itr = this->business->allUsers.end();
		--itr;
		temp = dynamic_cast<Client*>(*itr);
		this->clientMenu(temp);
	}

	else if (res == this->SELLER)	//start the seller menu with the user parameter
	{
		Seller * temp = dynamic_cast<Seller*>(getUser);
		*(this->business) += *temp;
		delete temp;
		vector<User*>::iterator itr = this->business->allUsers.end();
		--itr;
		temp = dynamic_cast<Seller*>(*itr);
		this->sellerMenu(temp);
	}

	else    //start the client&seller menu with the user parameter
	{
		ClientSeller * temp = dynamic_cast<ClientSeller*>(getUser);
		*(this->business) += *temp;
		delete temp;
		vector<User*>::iterator itr = this->business->allUsers.end();
		--itr;
		temp = dynamic_cast<ClientSeller*>(*itr);
		this->clientSellerMenu(temp);
	}
}

//function to log in as client or seller
void Menu::logIn() 
{
	cout << "\n---------------------------------------------\n";
	cout << "\t\tLOG IN" << endl;
	cout << "---------------------------------------------\n\n";
	User * getUser;
	string userName;
	char clean = getchar();
	cout << "\nPlease enter your userName: ";
	this->getString(this->MAX_NAME_SIZE, userName);

	getUser = this->searchExistUserName(userName);	//search the user in the clients array of the system

	if (!getUser)	//user name is not exsist int the system
	{
		cout << "\n----- This user name is not exist ----- \n\n";
		this->mainMenu();
	}

	else  //the user name exsist in the system 
	{
		//the password match to the user name
		if (this->checkPassword(getUser->getPassword()))	
		{
			if (typeid(*getUser) == typeid(Client))
				this->clientMenu(dynamic_cast<Client*>(getUser));

			else if (typeid(*getUser) == typeid(Seller))
				this->sellerMenu(dynamic_cast<Seller*>(getUser));

			else
				this->clientSellerMenu(dynamic_cast<ClientSeller*>(getUser));

		}
		else   //password dosen`t match
		{
			cout << "\n----- Sorry, you can`t try again -----\n";
			this->mainMenu();
		}
	}
}

void Menu::clientSellerMenu(ClientSeller * clientSeller)
{
	short res;
	Order * order;
	char clean;
	string productName;
	cout << "\n---------------------------------------------\n";
	cout << "\tWelcome " << clientSeller->getUserName() << endl;
	cout << "---------------------------------------------\n\n";

	cout << "\nThis is your Menu:\n\n";
	cout << "To EXIT, press '" << this->EXIT << "'.\n";
	cout << "To search product by name, press '" << this->SHOW_PRODUCT << "'.\n";
	cout << "To watch all the clients details, press '" << this->SHOW_CLIENT << "'.\n";
	cout << "To watch all the sellers details, press '" << this->SHOW_SELLER << "'.\n";
	cout << "To watch all the seller details, press '" << this->SHOW_CLIENT_SELLER << "'.\n";
	cout << "To add feedback, press '" << this->ADD_FEEDBACK << "'.\n";
	cout << "To add a product to your shopping cart, press '" << this->SHOP_PRODUCT << "'.\n";
	cout << "To create an order, press '" << this->CREATE_ORDER << "'.\n";
	cout << "To add product, press '" << this->ADD_PRODUCT << "'.\n";

	res = getInputShort();
	do
	{
		clean = getchar();
		switch (res)
		{
		case this->EXIT:
			this->mainMenu();
			break;

		case this->SHOW_PRODUCT:
			cout << "\n---------------------------------------------\n";
			cout << "\tShow products\n";
			cout << "---------------------------------------------\n\n";
			cout << "Please enter the name of the product that you would like to search\n";
			this->getString(this->MAX_NAME_SIZE, productName);

			this->business->showProductByName(productName);
			break;

		case this->SHOW_CLIENT:
			this->business->printAllClients();
			break;

		case this->SHOW_SELLER:
			this->business->printAllSellers();
			break;

		case this->SHOW_CLIENT_SELLER:
			this->business->printAllClientSellers();
			break;

		case this->ADD_FEEDBACK:
			this->checkValidationForFeedback(clientSeller);
			break;

		case this->SHOP_PRODUCT:
			this->shopProduct(clientSeller);
			break;

		case this->CREATE_ORDER:
			this->pickProductsToOrder(clientSeller);

			if (clientSeller->getCart()->getOrderProducts().size() > 0)	//the order cart is not empty
			{
				order = this->createOrder(clientSeller);
				this->checkout(order);
			}
			break;


		case this->ADD_PRODUCT:
			clientSeller->addProduct(this->createNewProduct(clientSeller));
			break;

		default:
			cout << "----- NOT VALIDE VALUE -----\n";
			this->clientSellerMenu(clientSeller);

		}

		cout << "\n---------------------------------------------\n";
		cout << "\tThis is your Menu:\n\n";
		cout << "To EXIT, press '" << this->EXIT << "'.\n";
		cout << "To search product by name, press '" << this->SHOW_PRODUCT << "'.\n";
		cout << "To watch all the clients details, press '" << this->SHOW_CLIENT << "'.\n";
		cout << "To watch all the sellers details, press '" << this->SHOW_SELLER << "'.\n";
		cout << "To watch all the seller details, press '" << this->SHOW_CLIENT_SELLER << "'.\n";
		cout << "To add feedback, press '" << this->ADD_FEEDBACK << "'.\n";
		cout << "To add a product to your shopping cart, press '" << this->SHOP_PRODUCT << "'.\n";
		cout << "To create an order, press '" << this->CREATE_ORDER << "'.\n";
		cout << "To add product, press '" << this->ADD_PRODUCT << "'.\n";
		cout << "---------------------------------------------\n\n";
		res = getInputShort();
		while (res < 0 || res > 8)
		{
			cout << "\n----- unvalide value, please try again -----\n";
			res = getInputShort();
		}

	} while (1);
}

//function check if the password match to the input password from the user
bool Menu::checkPassword(const string &userPassword)
{
	string password;

	cout << "Please enter your password: ";
	for (int i = 0; i < this->MAX_TRY; i++)	//the user as only 3 more trys to enter the correct password
	{
		this->getString(this->MAX_PASSWORD_SIZE, password);

		if (password == userPassword)
		{
				return true;
		}
		cout << "\nIncorect password, you can try " << this->MAX_TRY - i -1 << " more times.\nEnter your paaword: ";
	}
	return false;
}

//the function return the client pointer with the same userName 
Client* Menu::searchClientByUserName(const string & userName)
{
	vector<User*>::iterator itr = this->business->allUsers.begin();
	vector<User*>::iterator itrEnd = this->business->allUsers.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getUserName() == userName)
			return dynamic_cast<Client*>(*itr);
	}
	return nullptr;
}

//realloc function to the string input
char* Menu::myRealloc(char *str, int newSize, int oldSize)
{
	char * newString = new char[newSize];	// dynamic allocation

	// loop for saving the old data
	for (int i = 0; i < oldSize; i++)
	{
		newString[i] = str[i];
	}

	delete[] str;

	return newString;		//return to the new allocation string

}

//function to get string by the maximun size parameter
void Menu::getString(int maxSize, string & str)
{
	getline(cin, str);

	//as long as the log size is bigger then the maximoum size that we choose we stat the function again
	while (str.size() >= maxSize)
	{
		cout << "----- The input must " << maxSize << " or less characters, please try again -----\n";
		getline(cin, str);

		this->getString(maxSize,str);
	}
}

User* Menu::searchExistUserName(const string& userName)
{
	vector<User*>::iterator itr = this->business->allUsers.begin();
	vector<User*>::iterator itrEnd = this->business->allUsers.end();

	for (; itr != itrEnd; ++itr)
	{
		if (userName == (*itr)->getUserName())
			return *itr;
	}
	return nullptr;
}

User * Menu::addNewSystemUser(short index)
{
	string name, userName, password;
	char clean = getchar();
	cout << "\n---------------------------------------------\n";
	cout << "\tCreate your account" << endl;
	cout << "---------------------------------------------\n\n";

	cout << "\nPlease enter your name: ";
	this->getString(this->MAX_NAME_SIZE,name);
	

	cout << "\n\nPlease enter your userName: ";
	this->getString(this->MAX_NAME_SIZE,userName);

	while (!validUserName(userName))	//loop to check if the userName is already i the system
	{
		cout << "\n----- This userName is already taken, please try again -----\n";
		this->getString(this->MAX_NAME_SIZE, userName);
	}

	cout << "\nPlease enter your password: ";
	this->getString(this->MAX_PASSWORD_SIZE,password);

	Address address(this->getAddress());	//creating address by using defult copy c`tor

	if (index == this->CLIENT_SELLER)
	{
		cout << "\nThank you for join us, we gave you a 50$ on us! enjoy :)\n";
		cout << "--------------------------------------------------------\n\n";
		return new ClientSeller(name, userName, password, address);
	}
	else if (index == this->CLIENT)
	{
		cout << "\nThank you for join us, we gave you a 50$ on us! enjoy :)\n";
		cout << "--------------------------------------------------------\n\n";
		return new Client(name, userName, password, address);
	}
	else
	{
		cout << "\nThank you for join us :)\n";
		cout << "--------------------------------------------------------\n\n";
		return new Seller(name, userName, password, address);
	}
}

//the function build the client address and return the value 
Address Menu::getAddress()
{
	string country, city, street, zip;
	short houseNumber, aptNum;
	cout << "\nPlease enter your address.";

	cout << "\nCountry: ";
	this->getString(this->MAX_NAME_SIZE,country);

	cout << "\nCity: ";
	this->getString(this->MAX_NAME_SIZE,city);

	cout << "\nStreet: ";
	this->getString(this->MAX_NAME_SIZE, street);

	cout << "\nZip Code: ";
	this->getString(this->ZIP_CODE_SIZE, zip);

	cout << "\nHouse Number: ";
	houseNumber = this->getInputShort();

	cout << "\nApartment Number: ";
	aptNum = this->getInputShort();

	//making the address by using teh c`tor
	Address address(country, city, street, zip, houseNumber, aptNum);
	return address;
}

//function to check if the userName is avaliable in the clients userName of the system
bool Menu::validUserName(const string & userName)
{
	vector<User*>::iterator itr = this->business->allUsers.begin();
	vector<User*>::iterator itrEnd = this->business->allUsers.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getUserName() == userName)
		{
			return false;
		}
	}
	return true;
}

//the function make new product for seller that we get and return pointer to the product
Product* Menu::createNewProduct(Seller * seller)
{
	string name;
	double price;

	cout << "\n---------------------------------------------\n";
	cout << "\tLet`s get your product\n";
	cout << "---------------------------------------------\n\n";
	cout << "\nPlease enter the product`s name: ";
	this->getString(this->MAX_NAME_SIZE, name);

	cout << "\nPlease enter the product`s price: ";
	price = getInputDouble();
	while (price <= 0)
	{
		cout << "\n ----- The price must be positive number, nothing is for free. Try again -----\n" << endl;
		price = getInputDouble();
	}

	int category = this->chooseCategory();
	
	return new Product(name, (Product::eCategory) category, price, *seller);
}

//function to choose the category of the product
int Menu::chooseCategory()
{
	int res;
	cout << "\nPlease enter the product category:\n\n";
	cout << "To pick the KIDS category press'0'" << endl;
	cout << "To pick the ELECTRICITY category press'1'" << endl;
	cout << "To pick the OFFICE category press'2'" << endl;
	cout << "To pick the FASHION category press'3'" << endl;
	cout << "To pick the HEALTH category press'4'" << endl;
	cout << "To pick the SPORTS category press'5'" << endl;
	cout << "To pick the HOME category press'6'" << endl;
	cout << "To pick the SALE category press'7'" << endl;

	res=getInputInt();
	while (res < 0 || res>7)
	{
		cout << "----- Not valid value, please try again -----\n";
		res = getInputInt();
	}

	return res;
}

//function to check if the client can give the feedback and the product to the right seller feedback array
void Menu::checkValidationForFeedback(Client * client)
{
	int barCode;
	OrderItems * productForFeedback;
	if (client->getHistoryOrder().size() == 0)
	{
		cout << "\n------ Your history orders is empty, you can`t feedback ------\n";
	}
	else
	{
		cout << "\n---------------------------------------------\n";
		cout << "\tThis is your history order\n";
		cout << "---------------------------------------------\n\n";
		client->printHistoryOrder();
		cout << "\n\nPlease enter the bar code of the product that you would like to feedback: \n";
		barCode = this->getInputInt();
		productForFeedback = client->searchProductByBarCode(barCode);
		if (productForFeedback!=nullptr)
		{
			if(productForFeedback->allowFeedback)
			     this->createFeedback(client, productForFeedback);
			else
				cout << "\n------ Sorry, you already wrote a feedback to this product ------\n";
		}
		else
			cout << "\n------ Sorry, there is no product with this bar code in your history order ------\n";
	}
}

//function make the feedback and add the feedback to the seller feedbacks array
void Menu::createFeedback(Client * client, OrderItems * product)
{
	string note;
	char clean = getchar();
	cout << "\n---------------------------------------------\n";
	cout << "\tLet`s feedback" << endl;
	cout << "---------------------------------------------\n\n";

	cout << "Please enter your feedback:\n(Please notice: to end the feedback press ENTER)\n";

	this->getString(this->FEEDBACK_SIZE, note);
	product->allowFeedback = false;

	client->addFeedback(new Feedback(*client, note, *product->product));
}

//the function get client and add to his shopping cart the wanted product (by seller and bar code)
void Menu::shopProduct(Client * client)
{
	string sellerUserName;
	ClientSeller * type = dynamic_cast<ClientSeller*>(client);
	Seller * seller;
	Product * product;
	int barCode;

	cout << "---------------------------------------------\n";
	cout << "\tWelcom to your cart!\n";
	cout << "---------------------------------------------\n\n";
	this->business->printSellersUserName();

	if (this->business->sellerCounter > 0)
	{
		cout << "\nPlease enter the user name of the seller that you would like to by from\n";
		this->getString(this->MAX_NAME_SIZE, sellerUserName);

		seller = this->business->searchSellerByUserName(sellerUserName);	//get the seller info

		if (seller == nullptr)	//not seller match
			cout << "\n----- Sorry this seller user name is not exist ------\n";

		else
		{
			if (client->getUserName() == seller->getUserName())
			{
				cout << "\n----- Sorry, you can`t by from yourself -----\n";
				this->clientSellerMenu(type);
			}
			
			if (seller->getProducts().size() > 0)	//the seller as products to offer
			{
				cout << "\n---------------------------------------------\n";
				cout << "\nThe seller: " << seller->getUserName() << " store offers:\n";
				cout << "---------------------------------------------\n\n";
				seller->printProductArr();

				cout << "\nPlease enter the product`s bar code: ";
				barCode = this->getInputInt();
				product = seller->searchProductByBarCode(barCode);
				if (product != nullptr)
				{
					client->getCart()->addProduct(product);
					cout << "The product is in your shopping cart.\n";
				}
				else   //the bar code dosent match to the seller
				{
					cout << "\n----- Sorry, this bar code is not exsist -----\n";

					if (type)
						this->clientSellerMenu(type);

					this->clientMenu(client);
				}
			}
			else //the seller as no products in his account
			{
				cout << "\n----- Sorry, this seller as no products -----\n";

				if (type)
					this->clientSellerMenu(type);

				this->clientMenu(client);
			}

		}
	}
	else
	{
		cout << "\n----- Sorry, come back later ------\n";

		if (type)
			this->clientSellerMenu(type);

		this->clientMenu(client);
	}
	
}

//the function create the client order cart from his shopping cart
void Menu::pickProductsToOrder(Client * client)
{
	client->getCart()->allocateOrderCart();
	short res;
	ClientSeller * type = dynamic_cast<ClientSeller*>(client);
	vector<Product*> reserveArr;
	//there are no products in the shopping cart to pick
	if (client->getCart()->getShoppingCart().size() == 0)
	{
		cout << "\n----- Sorry, your shopping cart is empty ------\n";

		if (type)
			this->clientSellerMenu(type);

		this->clientMenu(client);
	}

	cout << "---------------------------------------------\n";
	cout << "\tLet`s create your order!\n";
	cout << "---------------------------------------------\n\n";
	vector<Product*>::iterator itr = client->getCart()->getShoppingCart().begin();
	vector<Product*>::iterator itrEnd = client->getCart()->getShoppingCart().end();
	for (; itr != itrEnd; ++itr)
	{
		cout << *(*itr) << endl;

		cout << "To order this product please press '" << this->ADD << "' \nTo continue to the next product please press '" << this->CANCEL << "'\n";
		res = getInputShort();
		while (res != this->ADD && res != this->CONTINUE)
		{
			cout << "\nPlease press '" << this->ADD << "' or '" << this->CANCEL << "'.\n";
			res = getInputShort();
		}
		
		if (res == ADD)
		{
			//insert the product to the shopping cart
			client->getCart()->addProductToOrderCart(*itr);
		}
		else
		{
			reserveArr.push_back(*itr);
		}
		cout << endl;
	}
	cout << "\n----- There are no more products to check -----\n";
	client->getCart()->updateShoppingCart(reserveArr);
}

//the function create the final order and return pointer to this order
Order * Menu::createOrder(Client * client)
{
	if (client->getCart()->getOrderProducts().size() == 0)
	{
		cout << "\n----- The order was not created because you didn`t selected any product -----\n";
	}
	else
	{
		return new Order(client->getCart()->getOrderProducts(), *client);
	}
}

//the function check if the client want to pay or canle the reservation
void Menu::checkout(Order * order)
{
	short res;
	cout << "---------------------------------------------\n";
	cout << "\tAllmost done!\n";
	cout << "---------------------------------------------\n";
	cout << "\tThis is your order:" << endl;
	cout << "---------------------------------------------\n\n";

	order->print();	//print the client order shopping cart
	cout << "\nTo pay please press '" << this->PAY << "' \nTo cancel press '" << this->CANCEL << "'\n";
	res = getInputShort();

	while (res != this->CANCEL && res != this->PAY)
	{
		cout << "\nPlease press '" << this->PAY << "' or '" << this->CANCEL << "'.\n";
		res = getInputShort();
	}

	if (res == this->PAY)
	{
		if (this->timeToPay(order))
		{
			cout << "\nYour reservation approved." << endl;
			cout << "Thanks for buying, KS BUSSINES :)" << endl;
			order->getOwner().insertToHistoryOrder(order);
		}
		else
		{
			cout << "\n----- The reservation canceled -----\n";
			delete order;
		}
	}
	else
	{
		cout << "\n----- The reservation canceled -----\n";
		delete order;
	}
}

// The function used for paying on the reservation
bool Menu::timeToPay(Order * order)
{
	short res;
	double amount;
	if (order->getOwner().getWallet() >= order->getTotalPrice())
	{
		order->getOwner().setWallet(order->getOwner().getWallet() - order->getTotalPrice());
		return true;
	}

	cout << "\n----- Sorry, there is not enough money in your wallet ----- \n\nTo charge your wallet please press '" << this->PAY << "' \nTo cancel press '" << this->CANCEL << "'\n";
	res = getInputShort();
	while (res != this->PAY && res != this->CANCEL)
	{
		cout << "Please press '" << this->PAY <<"' or '"<<this->CANCEL<<"'.\n";
		res = getInputShort();
	}

	if (res == this->PAY)
	{
		cout << "Please enter the amount to charge: ";
		amount = getInputDouble();
		order->getOwner().setWallet(order->getOwner().getWallet() + amount);
		return this->timeToPay(order);
	}

	return false;
}


//validation check to integers inputs
int Menu::getInputInt()
{
	int input;
	cin >> input;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a number\n";
		cin >> input;
	}
	return input;
}

//validation check to short inputs
short Menu::getInputShort()
{
	short input;
	cin >> input;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a number\n";
		cin >> input;
	}
	return input;
}

//validation check to double inputs
double Menu::getInputDouble()
{
	double input;
	cin >> input;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a number\n";
		cin >> input;
	}
	return input;
}

void Menu::compareTwoClients() 
{
	this->business->printAllClients();
	Client *client1, *client2;
	string clientName1, clientName2 ;

	if (this->business->sellerCounter > 0)
	{
		cout << "\nPlease enter the first user name:\n";
		this->getString(this->MAX_NAME_SIZE,clientName1);

		client1 = this->searchClientByUserName(clientName1);
		if (client1 == nullptr)
		{
			cout << "\n----- Sorry, this user name dosen`t exist -----\n";
			this->checkOperators();
		}

		cout << "\nPlease enter the second user name:\n";
		this->getString(this->MAX_NAME_SIZE, clientName2);

		client2 = this->searchClientByUserName(clientName2);
		if (client2 == nullptr)
		{
			cout << "\n----- Sorry, this user name dosen`t exist -----\n";
			this->checkOperators();
		}

		if (*client1 > *client2)
			cout << "\n----- Same shopping cart total price -----\n";
		else
			cout << "\n----- Different shopping cart total price -----\n";
	}
}

// check operators menu
void Menu::checkOperators()
{
	short res;
	User * newUser;

	cout << "\n---------------------------------------------\n";
	cout << "\t\tCHECK OPERATORS" << endl;
	cout << "---------------------------------------------\n\n";

	cout << "Dear checker please be gentle!\n\n";
	cout << "To add client by using operator += please press '" << this->CLIENT << "'\n";
	cout << "To add seller by using operator += please press '" << this->SELLER << "'\n";
	cout << "To compare between two clients by using operator > please press '" << this->COMPARE_CLIENTS << "'\n";
	cout << "To print by using operator << please press '" << this->PRINT << "'\n";
	cout << "To go back to the main menu please press '" << this->MAIN_MENU << "'\n";

	res = this->getInputShort();

	do
	{
		switch (res)
		{
		case this->CLIENT:
		{
			newUser = this->addNewSystemUser(this->CLIENT);
			*(this->business) += *(dynamic_cast<Client*>(newUser));
			delete newUser;
			cout << "Now you can see your client account in our clients list :)\n";
			this->business->printAllClients();
			break;
		}
		case this->SELLER:
		{
			newUser = this->addNewSystemUser(this->SELLER);
			*(this->business) += *(dynamic_cast<Seller*>(newUser));
			delete newUser;
			cout << "Now you can see your seller account in our sellers list :)\n";
			this->business->printAllSellers();
			break;
		}
		case this->COMPARE_CLIENTS:
		{
			this->compareTwoClients();
			break;
		}
		case this->PRINT:
		{
			this->printByOperator();
			break;
		}
		case this->MAIN_MENU:
		{
			this->mainMenu();
			break;
		}
		default:
			cout << "----- NOT VALIDE VALUE -----\n";
			this->checkOperators();
			break;
		}

		cout << "\n---------------------------------------------\n";
		cout << "Dear checker please be gentle!\n\n";
		cout << "To add client by using operator += please press '" << this->CLIENT << "'\n";
		cout << "To add seller by using operator += please press '" << this->SELLER << "'\n";
		cout << "To compare between two clients by using operator > please press '" << this->COMPARE_CLIENTS << "'\n";
		cout << "To print by using operator << please press '" << this->PRINT << "'\n";
		cout << "To go back to the main menu please press'" << this->MAIN_MENU << "'\n";
		cout << "\n---------------------------------------------\n\n";

		res = this->getInputShort();
		while (res < 0 || res > 4)
		{
			cout << "\n----- unvalide value, please try again -----\n";
			res = getInputShort();
		}

	} while (1);	// check validation
}

//this function prints all operatos << of ours class
void Menu::printByOperator() const
{
	cout << "\nHello dear checker:\n";
	cout << "We choose to use operator<< in the class: \n\nDate \nFeedback \nProduct\n\n";
	cout << "By printing one feedback you can see the using of operator<< of all those 3 class\n";
	Address tempAdress("Isarel", "Tel Aviv", "Ha Hasmonaim", "28399", 12, 3);
	Client * tempClient=new Client("Test Client name", "Tast Client", "1234", tempAdress);
	Seller * tempSeller = new Seller("Test Seller name", "Test Seller", "1234", tempAdress);
	Product * tempProduct = new Product("BRIBE ;)", Product::eCategory(7), 100, *tempSeller);
	Feedback tempFeedback(*tempClient, "\n=============== This project worth = 100 ===============\n", *tempProduct);

	cout << "\n" << tempFeedback << "\n";

	cout << "We use operator<< in Address class :\n" << tempAdress << "\n";

	delete tempClient;
	delete tempSeller;
	delete tempProduct;
}

void Menu::shutDown()
{
	ofstream outFile("KS.txt", ios::trunc);

	if (this->business->allUsers.size() == 0)
		outFile << this->EMPTY << "\n";

	else
	{
		outFile << this->business->allUsers.size() << endl;
		vector<User*>::iterator itr = this->business->allUsers.begin();
		vector<User*>::iterator itrEnd = this->business->allUsers.end();

		for (; itr != itrEnd; ++itr)
		{
			(*itr)->write(outFile);
		}
	}
	outFile.close();
}

void Menu::uploadData(const char * fileName)
{
	ifstream inFile(fileName, ios::in);
	int numOfUsers;
	inFile >> numOfUsers;

	if (numOfUsers == this->EMPTY)
		inFile.close();

	else
	{
		User * temp;
		for (int i = 0; i < numOfUsers; i++)
		{
			char type[this->MAX_NAME_SIZE];
			inFile >> type;

			if (strcmp(type, typeid(Seller).name() + 6) == 0)
			{
				temp = new Seller(inFile);
				*this->business += *(dynamic_cast<Seller*>(temp));
			}
			else if (strcmp(type, typeid(Client).name() + 6) == 0)
			{
				temp = new Client(inFile);
				*this->business += *(dynamic_cast<Client*>(temp));
			}
			else if (strcmp(type, typeid(ClientSeller).name() + 6) == 0)
			{
				temp = new ClientSeller(inFile);
				*this->business += *(dynamic_cast<ClientSeller*>(temp));
			}
		}
		inFile.close();
	}
}