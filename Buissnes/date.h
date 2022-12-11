#ifndef __DATE_H
#define __DATE_H

#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;

class Date
{
private:
	short day;
	short month;
	short year;

public:
	Date();
	Date(short day, short month, short year);

	//setters for Date class values
	bool setDay(short day);
	bool setMonth(short month);
	bool setYear(short year);

	//getters for Data class uses as inline
	const short getDay() const { return day; }
	const short getMonth() const { return month; }
	const short getYear() const { return year; }

	friend ostream & operator<<(ostream & os, const Date & date);
};


#endif // __DATE_H