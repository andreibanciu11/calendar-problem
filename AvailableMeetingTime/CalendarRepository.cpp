#pragma once
#include "CalendarRepository.h"

CalendarRepository::CalendarRepository(Time& lower_limit_range, Time& upper_limit_range, int meeting_time)
{
	this->lower_limit_range = lower_limit_range;
	this->upper_limit_range = upper_limit_range;
	this->meeting_time = meeting_time;
}

CalendarRepository::CalendarRepository()
{
}

CalendarRepository::CalendarRepository(const CalendarRepository& repo)
{
	this->lower_limit_range = repo.lower_limit_range;
	this->upper_limit_range = repo.upper_limit_range;
	this->booking = repo.booking;
	this->meeting_time = repo.meeting_time;
}

Time CalendarRepository::getLowerLimitRange()
{
	return this->lower_limit_range;
}

Time CalendarRepository::getUpperLimitRange()
{
	return this->upper_limit_range;
}

vector<vector<Time>> CalendarRepository::getBooking()
{
	return this->booking;
}

int CalendarRepository::getMeetingTime()
{
	return this->meeting_time;
}

void CalendarRepository::setLowerTimeRange(Time& t)
{
	this->lower_limit_range = t;
}

void CalendarRepository::setUpperTimeRange(Time& t)
{
	this->upper_limit_range = t;
}

void CalendarRepository::setMeetingTime(int meeting_time)
{
	this->meeting_time = meeting_time;
}

void CalendarRepository::addBooking(vector<Time>& booking)
{
	this->booking.push_back(booking);
}
