#include "Task.h"

Task::Task():taskDate(),taskTime(),taskMsg()
{}

Task::Task(const Date& d, const Time& t, const String& m):taskDate(d),taskTime(t),taskMsg(m)
{}

void Task::setTask(const Date & d, const Time & t, const String & m)
{
	taskDate = d;
	taskTime = t;
	taskMsg.~String();
	taskMsg.concatEqual(m);
}

void Task::updateDate(const Date& nd)
{
	taskDate = nd;
}

void Task::updateTime(const Time& nT)
{
	taskTime = nT;
}

void Task::updateMessage(const String& m)
{
	taskMsg.~String();
	taskMsg.concatEqual(m);
}

Date Task::getDate() const
{
	return taskDate;
}

Time Task::getTime() const
{
	return taskTime;
}

String Task::getMessage() const
{
	return taskMsg;
}
