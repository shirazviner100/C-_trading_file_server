#ifndef _USER_H
#define _USER_H

#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <vector>
#include<string>
using namespace std;
#include "address.h"

class User
{
public:
	static constexpr int MAX_NAME_SIZE = 20;		 //maximum name size 20
	static constexpr int MAX_PASSWORD_SIZE = 10;	//maximum password size 10

protected:
	string name;				//User: name
	string userName;			//User: user name - unique for any clent
	Address address;						//User: address
	string password;		//User: password data

	User(const string & name, const string & userName, const string & password, const Address & address);
	User(ifstream & inFile);

public:
	virtual ~User()
	{
	}

	//setters to User class
	bool setName(const string & name);
	bool setUserName(const string & userName);
	bool setPassword(const string & password);
	void setAddress(const Address & address);

	//getters to User class
	const string & getUserName() const { return this->userName; }
	const string & getName() const { return this->name; }
	const Address getAddress() const { return this->address; }
	const string & getPassword() const { return this->password; }

	void write(ofstream& outFile) const;

	virtual void print() const = 0 ;
	void printUserName() const;

};





#endif // !_USER_H
