#pragma once
#include "CalendarRepository.h"

class Service {
private:
	CalendarRepository repo1;
	CalendarRepository repo2;
public:
	Service(CalendarRepository& repo1, CalendarRepository& repo2);

	Service();

	Service(const Service& serv);

	/// <summary>
	/// Getter for first person repository
	/// </summary>
	/// <returns>repository for first person</returns>
	CalendarRepository getRepository1();

	/// <summary>
	/// Getter for second person repository
	/// </summary>
	/// <returns></returns>
	CalendarRepository getRepository2();

	/// <summary>
	/// Service function which calls add booking function from repository
	/// </summary>
	/// <param name="first_time">Starting time of booking as string</param>
	/// <param name="second_time">Ending time of booking as string</param>
	/// <param name="index">Person index, first person or second person, 1/2</param>
	void addBookingService(string first_time, string second_time, int index);

	/// <summary>
	/// Sets time ranges in repository for first/second person
	/// </summary>
	/// <param name="first_time">Starting time of range</param>
	/// <param name="second_time">Ending time of range</param>
	/// <param name="index">person index</param>
	void addTimeRange(string first_time, string second_time, int index);

	/// <summary>
	/// Sets meeting time to value introduced by user
	/// </summary>
	/// <param name="minute">New meeting time value</param>
	void addMeetingTime(int minute);

	/// <summary>
	/// Makes Time class object from string
	/// </summary>
	/// <param name="time">time as a string</param>
	/// <returns>Time class object</returns>
	Time stringToTime(string time);

	/// <summary>
	/// Checks if time introduced by user is valid
	/// </summary>
	/// <param name="time">Time from input</param>
	/// <returns>1 if valid, 0 if not</returns>
	int checkTimeValid(string time);

	/// <summary>
	/// Checks if upper limit from input is greater that lower limit
	/// </summary>
	/// <param name="lower_limit_range"></param>
	/// <param name="upper_limit_range"></param>
	/// <returns>1 if greater, 0 if not</returns>
	int checkUpperLimit(string lower_limit_range, string upper_limit_range);

	/// <summary>
	/// Checks if time from input is in time range
	/// </summary>
	/// <param name="time">time from input</param>
	/// <param name="index">person index</param>
	/// <returns>1 if time is in range, 0 if not</returns>
	int checkBookingInRange(string time, int index);

	/// <summary>
	/// Checks if booking overlaps another already existing booking
	/// </summary>
	/// <param name="lower_limit_booking"></param>
	/// <param name="upper_limit_booking"></param>
	/// <param name="index">person index</param>
	/// <returns>1 if booking does not overlap, 0 if it does</returns>
	int checkBookingValid(string lower_limit_booking, string upper_limit_booking, int index);

	/// <summary>
	/// Compares 2 Time class objects
	/// </summary>
	/// <param name="t1">first time</param>
	/// <param name="t2">second time</param>
	/// <returns>1 if t1 is greater than t2(later), 0 if equal, 2 if t1 lower than t2(earlier)</returns>
	int compareTime(Time t1, Time t2);

	/// <summary>
	/// Finds all free time slots in a day for a person
	/// </summary>
	/// <param name="index">person index</param>
	/// <returns>Vector with all free time slots</returns>
	vector<vector<Time>> findFreeTime(int index);

	/// <summary>
	/// Combines free time slots from both and returns a vector with free time slots with duration >= meeting_time
	/// </summary>
	/// <returns></returns>
	vector<vector<Time>> findCommonFreeTime();
};
