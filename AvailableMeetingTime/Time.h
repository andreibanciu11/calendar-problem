#pragma once
#include <string>
#include <iostream>

using namespace std;

class Time {
private:
	int hour;
	int minute;
public:
	/// <summary>
	/// Constructor for time class
	/// </summary>
	/// <param name="hour"></param>
	/// <param name="minute"></param>
	Time(int hour, int minute);

	/// <summary>
	/// Default constructor for time class
	/// </summary>
	Time();

	/// <summary>
	/// Copy constructor for time class
	/// </summary>
	/// <param name="t"></param>
	Time(const Time& t);

	/// <summary>
	/// Getter for hour
	/// </summary>
	/// <returns>Integer, hour</returns>
	int getHour();

	/// <summary>
	/// Getter for minute
	/// </summary>
	/// <returns>Integer, minute</returns>
	int getMinute();

	/// <summary>
	/// Setter for hour
	/// </summary>
	/// <param name="hour">New value for hour</param>
	void setHour(int hour);

	/// <summary>
	/// Setter for minute
	/// </summary>
	/// <param name="minute">New value for minute</param>
	void setMinute(int minute);

	/// <summary>
	/// Returns time as string
	/// </summary>
	/// <returns></returns>
	string toString();

	void addMinutes(int minutes);
};
