#include "date.h"

//default c`tor for Date class
Date::Date()
{
	time_t now = time(0);	//get the current time
	tm *localTm = localtime(&now);	//get the time by local time

	day = localTm->tm_mday;	//current day
	month = localTm->tm_mon + 1;	//current month
	year = localTm->tm_year + 1900;		//current year(the function time start to count from 1990)
}

//c`tor that get paramrters
Date::Date(short day, short month, short year)
{
	this->setDay(day);
	this->setMonth(month);
	this->setYear(year);
}

//set for day value
bool Date::setDay(short day)
{
	// if the day is valid
	if (day >= 1 && day <= 31)
	{
		this->day = day;
		return true;
	}

	cout << "The day value must be between 1-31. " << endl;
	return false;
}

//set for month value
bool Date::setMonth(short month)
{
	// if the month is valid
	if (month >= 1 && month <= 12)
	{
		this->month = month;
		return true;
	}

	cout << "The month value must be between 1-12. " << endl;
	return false;
}

//set for year value
bool Date::setYear(short year)
{
	// if the year is valid
	if (year >= 2019)
	{
		this->year = year;
		return true;
	}

	cout << "The year must be bigger than 2019. " << endl;
	return false;
}

//opertor<< to print date
ostream & operator<<(ostream & os, const Date & date)
{
	os << date.day << "/" << date.month << "/" << date.year << endl;

	return os;
}
