#pragma once
#include "Service.h"

class UI {
private:
	Service serv;
public:
	UI(Service serv);

	UI();

	UI(const UI& ui);

	/// <summary>
	/// Getter for service
	/// </summary>
	/// <returns></returns>
	Service getService();
	
	/// <summary>
	/// Main read function which reads time ranges and bookings from user input
	/// </summary>
	void readTime();

	/// <summary>
	/// Separate read function for reading multiple booking times
	/// </summary>
	/// <param name="index"></param>
	void readBooking(int index);

	/// <summary>
	/// Prints all commom free time slots 
	/// </summary>
	void showFreeTime();

	/// <summary>
	/// 
	/// </summary>
	void start();
};