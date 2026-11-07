#ifndef SCHEDULE_H
#define SCHEDULE_H
#include "Task.h"
#include <ctime>

int d, month, year;
time_t t = time(0);
tm curTime = *localtime(&t);
d = curTime.tm_mday;

class Schedule
{
	Task* taskList;
	int noOfTasks;
	int capacity;

public:
	Schedule();
	void addTask(const Task& t);
	void displayTask(const Date & d= Date(1, 1, 1500)) const;
	void displayTodaysTasks() const;
	void resize(int);
};


#endif