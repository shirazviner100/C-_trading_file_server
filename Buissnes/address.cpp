#include "address.h"

//constractor for address 
Address::Address(const string & country, const string & city, const string & street, const string & zip
	, short houseNumber, short aptNum)
{
	this->setCountry(country);
	this->setCity(city);
	this->setStreet(street);
	this->setZip(zip);
	this->setHouseNumber(houseNumber);
	this->setAptNumber(aptNum);
}

//set adress - country data
bool Address::setCountry(const string & country)
{
	if (country.size() >= MAX_NAME_SIZE)	//validation check if the country name is smaller than MAX_NAME_SIZE
	{
		cout << "The country must contain " << (MAX_NAME_SIZE - 1) << " letters or less." << endl;
		return false;
	}

	this->country = country;
	return true;
}

//set adress - city data
bool Address::setCity(const string & city)
{
	if (city.size() >= MAX_NAME_SIZE)	//validation check if the city name is smaller than MAX_NAME_SIZE
	{
		cout << "The city must contain " << (MAX_NAME_SIZE - 1) << " letters or less." << endl;
		return false;
	}

	this->city = city;
	return true;
}

//set address - street data
bool Address::setStreet(const string & street)
{
	if (street.size() >= this->MAX_NAME_SIZE)	//validation check if the street name is smaller than MAX_NAME_SIZE	
	{
		cout << "The street's name must contain " << (this->MAX_NAME_SIZE - 1) << " letters or less." << endl;
		return false;
	}

	this->street = street;
	return true;
}

//set address - zip code data
bool Address::setZip(const string & zip)
{
	if (zip.size() >= ZIP_CODE_SIZE)	//validation check if the zip code is smaller than ZIP_CODE_SIZE	
	{
		cout << "The zip code must contain " << (ZIP_CODE_SIZE - 1) << " digits or less." << endl;
		return false;
	}

	this->zip = zip;
	return true;
}

//set address - bilding number
void Address::setHouseNumber(short houseNumber)
{
	this->houseNumber = houseNumber;
}

//set address - apartment number
void Address::setAptNumber(short aptNum)
{
	this->aptNum = aptNum;
}

//operator<< (cout) for address
ostream & operator<<(ostream & os, const Address & address)
{
	os << "\nCountry: " << address.country << "\nCity: " << address.city << "\nStreet: " << address.street <<
		"\nHouse No. " << address.houseNumber << "\nApt. " << address.aptNum << "\nZip: " << address.zip << endl;

	return os;
}

void Address::write(ofstream& outFile) const
{
	outFile << this->country << "\n" << this->city << "\n" << this->street << "\n" << this->zip << "\n" << 
		this->houseNumber << "\n" << this->aptNum << "\n";
}
