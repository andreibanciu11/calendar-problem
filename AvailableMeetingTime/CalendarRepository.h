#pragma once
#include "Time.h"
#include <vector>

class CalendarRepository {
private:
	Time lower_limit_range;
	Time upper_limit_range;
	vector<vector<Time>> booking;
	int meeting_time;
public:
	/// <summary>
	/// Constructor for repo class
	/// </summary>
	/// <param name="lower_limit_range">lower limit time range of a person</param>
	/// <param name="upper_limit_range">upper limit time range of a person</param>
	/// <param name="meeting_time">duration of meeting</param>
	CalendarRepository(Time& lower_limit_range, Time& upper_limit_range, int meeting_time);

	/// <summary>
	/// Default constructor for repo class
	/// </summary>
	CalendarRepository();

	/// <summary>
	/// Copy constructor for repo class
	/// </summary>
	/// <param name="repo">Copied repo</param>
	CalendarRepository(const CalendarRepository& repo);

	/// <summary>
	/// Getter for lower limit time range
	/// </summary>
	/// <returns>lower limit time range</returns>
	Time getLowerLimitRange();

	/// <summary>
	/// Getter for upper limit time range
	/// </summary>
	/// <returns>upper limit time range</returns>
	Time getUpperLimitRange();

	/// <summary>
	/// Getter for bookings
	/// </summary>
	/// <returns>Vector which contains bookings of a person</returns>
	vector<vector<Time>> getBooking();

	/// <summary>
	/// Getter for duration of a meeting
	/// </summary>
	/// <returns></returns>
	int getMeetingTime();

	/// <summary>
	/// Setter for lower limit time range
	/// </summary>
	/// <param name="t">new lower limit time range</param>
	void setLowerTimeRange(Time& t);

	/// <summary>
	/// Setter for upper limit time range
	/// </summary>
	/// <param name="t">new upper limit time range</param>
	void setUpperTimeRange(Time& t);

	/// <summary>
	/// Setter for duration of a meeting
	/// </summary>
	/// <param name="meeting_time">New meeting time</param>
	void setMeetingTime(int meeting_time);

	/// <summary>
	/// Adds new booking to bookings vector
	/// </summary>
	/// <param name="booking">New booking of a person</param>
	void addBooking(vector<Time>& booking);
};