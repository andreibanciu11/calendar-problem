#pragma once
#include "Time.h"

Time::Time(int hour, int minute)
{
	this->hour = hour;
	this->minute = minute;
}

Time::Time()
{
	this->hour = 0;
	this->minute = 0;
}

Time::Time(const Time& t)
{
	this->hour = t.hour;
	this->minute = t.minute;
}

int Time::getHour()
{
	return this->hour;
}

int Time::getMinute()
{
	return this->minute;
}

void Time::setHour(int hour)
{
	this->hour = hour;
}

void Time::setMinute(int minute)
{
	this->minute = minute;
}

string Time::toString()
{
	string result = to_string(this->hour) + ':';
	if (this->minute < 10)
		result += '0' + to_string(this->minute);
	else
		result += to_string(this->minute);
	return result;
}

void Time::addMinutes(int minutes)
{
	int new_minute = (this->minute + minutes) % 60;
	int new_hour = this->hour + (this->minute + minutes) / 60;
	if (new_hour >= 24) {
		new_hour -= 24;
	}
	this->hour = new_hour;
	this->minute = new_minute;
}
