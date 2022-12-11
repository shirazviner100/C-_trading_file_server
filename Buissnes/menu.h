#ifndef  __MENU_H
#define __MENU_H

#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <typeinfo.h>
#include "KS.h"


class Menu
{
private:
	static constexpr short SIGN_IN = 0;
	static constexpr short LOG_IN = 1;
	static constexpr short SHUT_DOWN = 2;
	static constexpr short CHECK_OPERATORS = 3;

	static constexpr short COMPARE_CLIENTS = 2;
	static constexpr short PRINT = 3;
	static constexpr short MAIN_MENU = 4;

	static constexpr short CLIENT = 0;
	static constexpr short SELLER = 1;
	static constexpr short CLIENT_SELLER = 2;

	static constexpr int MAX_NAME_SIZE = 20;		 //maximum name size 20
	static constexpr int MAX_PASSWORD_SIZE = 10;
	static constexpr int ZIP_CODE_SIZE = 8;
	static constexpr int FEEDBACK_SIZE = 100;

	static constexpr int MAX_TRY = 4;	//maximum try again chance

	static constexpr int ADD = 1;
	static constexpr int CONTINUE = 0;

	static constexpr int CANCEL = 0;
	static constexpr int PAY = 1;
	static constexpr int EMPTY = 0;

	//menu consts
	static constexpr int EXIT = 0;
	static constexpr int SHOW_PRODUCT = 1;
	static constexpr int SHOW_CLIENT = 2;
	static constexpr int SHOW_SELLER = 3;
	static constexpr int SHOW_CLIENT_SELLER = 4;
	static constexpr int ADD_FEEDBACK = 5;
	static constexpr int SHOP_PRODUCT = 6;
	static constexpr int CREATE_ORDER = 7;
	static constexpr int ADD_PRODUCT = 8;

	KS * const business;
	
	char* myRealloc(char *str, int newSize, int oldSize);
	Address getAddress();
	void getString(int maxSize, string & str);
	bool checkPassword(const string &userPassword);
	Product* createNewProduct(Seller * seller);
	int chooseCategory();

	bool validUserName(const string & userName);
	User * addNewSystemUser(short index);

	void clientMenu(Client * client);
	void sellerMenu(Seller * seller);
	void clientSellerMenu(ClientSeller * clientSeller);

	void createFeedback(Client * client, OrderItems * product);
	void pickProductsToOrder(Client * client);
	void checkout(Order * order);
	bool timeToPay(Order * order);
	Client* searchClientByUserName(const string & userName);

	int getInputInt();
	short getInputShort();
	double getInputDouble();

public:
	Menu(KS* business);
	Menu(const Menu & copy);
	Menu(Menu && move);
	~Menu();

	//gett to the business pointer
	KS* getBusiness() const { return business; }

	void mainMenu();
	void signIn();
	void logIn() ;

	User* searchExistUserName(const string& userName);
	void checkValidationForFeedback(Client * client);
	void shopProduct(Client * client);
	Order * createOrder(Client * client);
	void compareTwoClients();
	void printByOperator() const;
	void checkOperators();

	void shutDown();
	void uploadData(const char * fileName);
};


#endif // ! __MENU_H