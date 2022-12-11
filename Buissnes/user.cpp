#include "user.h"

//c`tor to User class - using setters
User::User(const string & name, const string & userName, const string & password ,const Address & address) : address(address)
{
	this->setName(name);
	this->setUserName(userName);
	this->setPassword(password);
}

//c`tor by file
User::User(ifstream & inFile)
{
	string delimiter;
	//user data
	getline(inFile, delimiter);
	getline(inFile, this->name);
	getline(inFile, this->userName);
	getline(inFile, this->password);
	//address data
	getline(inFile, this->address.country);
	getline(inFile, this->address.city);
	getline(inFile, this->address.street);
	getline(inFile, this->address.zip);
	inFile >> this->address.houseNumber;
	inFile >> this->address.aptNum;
}


//set the Name value
bool User::setName(const string & name) 
{
	if (name.size() >= MAX_NAME_SIZE)	//check validation for the name string size
	{
		cout << "The name must contain " << (MAX_NAME_SIZE - 1) << " letters or less." << endl;
		return false;
	}

	this->name = name;
	return true;
}

//set the user Name value
bool User::setUserName(const string & userName)
{
	if (userName.size() >= MAX_NAME_SIZE)	//check validation for the user name string size
	{
		cout << "The name must contain " << (MAX_NAME_SIZE - 1) << " letters or less." << endl;
		return false;
	}

	this->userName = userName;
	return true;
}

//set user address data
void User::setAddress(const Address &clientAddress)
{
	address = clientAddress;
}

//set for user password data
bool User::setPassword(const string & password)
{
	if (password.size() >= MAX_PASSWORD_SIZE)	//check validation for the password string size
	{
		cout << "The password must contain " << this->MAX_PASSWORD_SIZE - 1 << " tabs or less.\n";
		return false;
	}

	this->password = password;
	return true;
}

//print to user class (virual)
void User::print() const
{
	cout << "\nName: " << this->name << "\nUser Name: " << this->userName << "\nAddress: " << this->address;
}

//the function prints just the user name of the seller (we use this function when the client want to buy products)
void User::printUserName() const
{
	cout << "User Name: " << this->userName << "\n";
}

void User::write(ofstream& outFile) const
{
	outFile << typeid(*this).name() + 6 << "\n" << this->name << "\n" << this->userName << "\n" << this->password << "\n";
	this->address.write(outFile);
}

