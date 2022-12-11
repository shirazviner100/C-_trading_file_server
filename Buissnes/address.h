#ifndef __ADDRESS_H
#define __ADDRESS_H

#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;

class Address
{
public:
	static constexpr int MAX_NAME_SIZE = 20;
	static constexpr int ZIP_CODE_SIZE = 8;
		
private:
	string country;
	string city;
	string street;
	string zip;
	short houseNumber;				//save the bilding number
	short aptNum;				   //save the apartment number

	Address() = default;

public:
	Address(const string & country, const string & city, const string & street, const string & zip
		, short houseNumber, short aptNum);

	//setters declaraction
	bool setCountry(const string & country);
	bool setCity(const string & city);
	bool setStreet(const string & street);
	bool setZip(const string & zip);
	void setHouseNumber(short houseNumber);
	void setAptNumber (short aptNum);

	//getters declaration - using as inline function
	const string & getCountry() const { return country; }
	const string & getCity() const { return city; }
	const string & getStreet() const { return street; }
	const string & getZip() const { return zip; }
	const short getHouseNumber() const { return houseNumber; }
	const short getAptNumber() const { return aptNum; }
 
	friend ostream & operator<<(ostream & os, const Address & address);
	void write(ofstream& outFile) const;

	friend class User;
};


#endif // __ADDRESS_H
