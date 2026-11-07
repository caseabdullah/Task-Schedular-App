#include "Date.h"
#include <iostream>
#include <iomanip>

using namespace std;
const int Date::daysInMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const char* Date::monthNames[13] =
{
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

bool Date::isLeapYear() const
{
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

Date::Date()
{
	day = 1;
	month = 1;
	year = 1999;
}

Date::Date(int d, int m, int y) :Date()
{
	setDay(d);
	setMonth(m);
	setYear(y);
}

void Date::setDay(int d)
{
	int maxDays = daysInMonth[month];
	if (month == 2 && isLeapYear())
	{
		maxDays = 29;
	}
	if (d >= 1 && d <= maxDays)
	{
		day = d;
	}
	else
	{
		cout << "Wrong Day" << endl;
	}
	return;
}

void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
	{
		month = m;
	}
	else
	{
		cout << "Wrong Month" << endl;
	}
}

void Date::setYear(int y)
{
	if (y >= 1500 && y <= 3000)
	{
		year = y;
	}
	else {
		cout << "Wrong Year";
	}
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

void Date::printFormat1() const
{
	cout << setfill('0') << setw(2) << month << "/" << setw(2) << day << "/" << year << endl;
}

void Date::printFormat2() const
{
	cout << monthNames[month];
	cout << " " << setfill('0') << setw(2) << day << ", " << year << endl;
}

void Date::printFormat3() const
{
	//25-Dec-2012
	cout << setfill('0') << setw(2) << day << "-";
	for (int i = 0; i < 3; i++)
	{
		cout << monthNames[month][i];
	}
	cout << "-" << setfill('0') << setw(2) << year;
}

String Date::getDateInFormat1() const
{
	//12/25/ 2012
	char* temp = new char[11];
	//day
	int m = month;
	temp[0] = (m / 10) + '0';
	temp[1] = (m % 10) + '0';
	temp[2] = '/';
	//month
	int d = day;
	temp[3] = (d / 10) + '0';
	temp[4] = (d % 10) + '0';
	temp[5] = '/';
	//year
	int y = year;
	for (int i = 9; i >= 6; i--)
	{
		temp[i] = y % 10 + '0';
		y = y / 10;
	}
	temp[10] = '\0';
	String format2{ temp };
	delete[]temp;
	return format2;
}

String Date::getDateInFormat2() const
{
	char* temp = new char[20];
	int i = 0;
	while (monthNames[month][i] != '\0')
	{
		temp[i] = monthNames[month][i];
		i++;
	}
	temp[i] = ' ';
	i++;
	int d = day;
	temp[i] = (d / 10) + '0';
	i++;
	temp[i] = (d % 10) + '0';
	i++;
	temp[i] = ',';
	i++;
	temp[i] = ' ';

	int y = year;
	for (int c = i + 4; c >= i + 1; c--)
	{
		temp[c] = y % 10 + '0';
		y = y / 10;
	}
	temp[i + 5] = '\0';
	String format2{ temp };
	format2.shrink();
	delete[]temp;
	return format2;
}

String Date::getDateInFormat3() const
{
	char* temp = new char[12];
	//day
	int d = day;
	temp[0] = (d / 10) + '0';
	temp[1] = (d % 10) + '0';
	temp[2] = '-';
	//month
	for (int i = 3, j = 0; i < 6; i++, j++)
	{
		temp[i] = monthNames[month][j];
	}
	//year
	int y = year;
	temp[6] = '-';
	for (int i = 10; i >= 7; i--)
	{
		temp[i] = y % 10 + '0';
		y = y / 10;
	}
	temp[11] = '\0';
	String format3{ temp };
	delete[]temp;
	return format3;
}
