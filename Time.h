#ifndef TIME_H
#define TIME_H

class Time
{
	int hours;
	int minutes;
	int seconds;

public:
	Time(int =0,int =0,int =0);
	void setHour(int);
	void setMinute(int);
	void setSecond(int);
	void setTime(int, int, int);

	int getHour();
	int getMinute();
	int getSecond();

	void incSec(int = 1);
	void incMin(int = 1);
	void incHour(int = 1);

	void printTwelveHourFormat();
	void printTwentyFourHourFormat();
};

#endif