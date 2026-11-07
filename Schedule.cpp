#include "Schedule.h"

Schedule::Schedule()
{
	capacity = 0;
	taskList = nullptr;
	noOfTasks = 0;
}

void Schedule::addTask(const Task& t)
{
	taskList = new Task [(capacity * 2) + 1];
	taskList[noOfTasks] = t;
	noOfTasks++;
}

void Schedule::displayTask(const Date& d) const
{
	for (int i = 0; i < length; i++)
	{

	}
}
