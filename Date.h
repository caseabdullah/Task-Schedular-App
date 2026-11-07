#ifndef DATE_H
#define DATE_H
#include "String.h"

class Date
{
	int day;
	int month;
	int year;
	static const int daysInMonth[13];
	static const char* monthNames[13];
	bool isLeapYear() const;
public:
	Date();
	Date(int, int, int);
	void setDate(int, int, int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void printFormat1() const;
	void printFormat2() const;
	void printFormat3() const;
	String getDateInFormat1() const;
	String getDateInFormat2() const;
	String getDateInFormat3() const;
};

#endif