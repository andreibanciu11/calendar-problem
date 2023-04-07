#pragma once
#include "UI.h"

UI::UI(Service serv)
{
	this->serv = serv;
}

UI::UI()
{
}

UI::UI(const UI& ui)
{
	this->serv = ui.serv;
}

Service UI::getService()
{
	return this->serv;
}

void UI::readTime()
{
	string lower_limit_range, upper_limit_range;
	int meeting_duration;

	cout << "Enter range time limits for first person: \n";
	cout << "Enter lower time limit: ";
	cin >> lower_limit_range;
	cout << "\n";
	while (this->serv.checkTimeValid(lower_limit_range) == 0)
	{
		cout << "Time is not valid. Try again!\n";
		cout << "Enter lower time limit: ";
		cin >> lower_limit_range;
		cout << "\n";
	}

	cout << "Enter upper time limit: ";
	cin >> upper_limit_range;
	cout << "\n";
	while (this->serv.checkTimeValid(upper_limit_range) == 0 || this->serv.checkUpperLimit(lower_limit_range, upper_limit_range) == 0)
	{
		if (this->serv.checkTimeValid(upper_limit_range) == 0) {
			cout << "Time is not valid. Try again!\n";
			cout << "Enter upper time limit: ";
			cin >> upper_limit_range;
			cout << "\n";
		}
		else {
			cout << "Upper limit time range value must be greater than lower limit time range value. Try again!\n";
			cout << "Enter upper time limit: ";
			cin >> upper_limit_range;
			cout << "\n";
		}
	}
	this->serv.addTimeRange(lower_limit_range, upper_limit_range, 1);
	
	cout << "Enter booking times for first person: \n";
	this->readBooking(1);
	char option = 'y';
	while (option == 'y') {
		cout << "Do you want to enter another booking? y/n: ";
		cin >> option;
		cout << "\n";

		while (option != 'y' && option != 'n')
		{
			cout << "\nBad input! The options are 'y' or 'n'!\n";
			cout << "Do you want to enter another booking? y/n: ";
			cin >> option;
			cout << "\n";

		}
		if (option == 'y')
			this->readBooking(1);
	}

	cout << "Enter range time limits for second person: \n";
	cout << "Enter lower time limit: ";
	cin >> lower_limit_range;
	cout << "\n";
	while (this->serv.checkTimeValid(lower_limit_range) == 0)
	{
		cout << "Time is not valid. Try again!\n";
		cout << "Enter lower time limit: ";
		cin >> lower_limit_range;
		cout << "\n";
	}

	cout << "Enter upper time limit: ";
	cin >> upper_limit_range;
	cout << "\n";
	while (this->serv.checkTimeValid(upper_limit_range) == 0 || this->serv.checkUpperLimit(lower_limit_range, upper_limit_range) == 0)
	{
		if (this->serv.checkTimeValid(upper_limit_range) == 0) {
			cout << "Time is not valid. Try again!\n";
			cout << "Enter upper time limit: ";
			cin >> upper_limit_range;
			cout << "\n";
		}
		else {
			cout << "Upper limit time range value must be greater than lower limit time range value. Try again!\n";
			cout << "Enter upper time limit: ";
			cin >> upper_limit_range;
			cout << "\n";
		}
	}
	this->serv.addTimeRange(lower_limit_range, upper_limit_range, 2);

	cout << "Enter booking times for second person: \n";
	this->readBooking(2);
	option = 'y';
	while (option == 'y') {
		cout << "Do you want to enter another booking? y/n: ";
		cin >> option;
		cout << "\n";

		while (option != 'y' && option != 'n')
		{
			cout << "\nBad input! The options are 'y' or 'n'!\n";
			cout << "Do you want to enter another booking? y/n: ";
			cin >> option;
			cout << "\n";

		}
		if (option == 'y')
			this->readBooking(2);
	}

	cout << "Enter meeting duration: ";
	cin >> meeting_duration;
	cout << "\n";

	this->serv.addMeetingTime(meeting_duration);
}

void UI::readBooking(int index)
{
	string lower_limit_booking, upper_limit_booking;

	cout << "Enter starting time of booking: ";
	cin >> lower_limit_booking;
	cout << "\n";
	while (this->serv.checkTimeValid(lower_limit_booking) == 0 || this->serv.checkBookingInRange(lower_limit_booking, index) == 0)
	{
		if (this->serv.checkTimeValid(lower_limit_booking) == 0) {
			cout << "Time is not valid. Try again!\n";
			cout << "Enter starting time of booking: ";
			cin >> lower_limit_booking;
			cout << "\n";
		}
		else {
			cout << "Starting time of booking is out of time range limits. Try again!\n";
			cout << "Enter starting time of booking: ";
			cin >> lower_limit_booking;
			cout << "\n";
		}
	}

	cout << "Enter ending time of booking: ";
	cin >> upper_limit_booking;
	cout << "\n";
	while (this->serv.checkTimeValid(upper_limit_booking) == 0 || this->serv.checkUpperLimit(lower_limit_booking, upper_limit_booking) == 0 || this->serv.checkBookingInRange(upper_limit_booking, 1) == 0)
	{
		if (this->serv.checkTimeValid(upper_limit_booking) == 0) {
			cout << "Time is not valid. Try again!\n";
			cout << "Enter ending time of booking: ";
			cin >> upper_limit_booking;
			cout << "\n";
		}
		else {
			if (this->serv.checkUpperLimit(lower_limit_booking, upper_limit_booking) == 0) {
				cout << "Ending time of booking must be greater than starting time of booking. Try again!\n";
				cout << "Enter ending time of booking: ";
				cin >> upper_limit_booking;
				cout << "\n";
			}
			else {
				cout << "Ending time of booking is out of time range limits. Try again!\n";
				cout << "Enter ending time of booking: ";
				cin >> upper_limit_booking;
				cout << "\n";
			}
		}
	}

	while (this->serv.checkBookingValid(lower_limit_booking, upper_limit_booking, index) == 0) {
		cout << "Booking is not valid, time range conflicts with another's booking time range. Try again!\n";
		
		cout << "Enter starting time of booking: ";
		cin >> lower_limit_booking;
		cout << "\n";
		while (this->serv.checkTimeValid(lower_limit_booking) == 0 || this->serv.checkBookingInRange(lower_limit_booking, index) == 0)
		{
			if (this->serv.checkTimeValid(lower_limit_booking) == 0) {
				cout << "Time is not valid. Try again!\n";
				cout << "Enter starting time of booking: ";
				cin >> lower_limit_booking;
				cout << "\n";
			}
			else {
				cout << "Starting time of booking is out of time range limits. Try again!\n";
				cout << "Enter starting time of booking: ";
				cin >> lower_limit_booking;
				cout << "\n";
			}
		}

		cout << "Enter ending time of booking: ";
		cin >> upper_limit_booking;
		cout << "\n";
		while (this->serv.checkTimeValid(upper_limit_booking) == 0 || this->serv.checkUpperLimit(lower_limit_booking, upper_limit_booking) == 0 || this->serv.checkBookingInRange(upper_limit_booking, 1) == 0)
		{
			if (this->serv.checkTimeValid(upper_limit_booking) == 0) {
				cout << "Time is not valid. Try again!\n";
				cout << "Enter ending time of booking: ";
				cin >> upper_limit_booking;
				cout << "\n";
			}
			else {
				if (this->serv.checkUpperLimit(lower_limit_booking, upper_limit_booking) == 0) {
					cout << "Ending time of booking must be greater than starting time of booking. Try again!\n";
					cout << "Enter ending time of booking: ";
					cin >> upper_limit_booking;
					cout << "\n";
				}
				else {
					cout << "Ending time of booking is out of time range limits. Try again!\n";
					cout << "Enter ending time of booking: ";
					cin >> upper_limit_booking;
					cout << "\n";
				}
			}
		}
	}

	this->serv.addBookingService(lower_limit_booking, upper_limit_booking, index);
	cout << "Booking added!\n";
}

void UI::showFreeTime()
{
	cout << "These are the free times people can meet:\n";
	vector<vector<Time>> free_time = this->serv.findCommonFreeTime();
	for (int i = 0; i < free_time.size(); i++) {
		cout << free_time.at(i).at(0).toString() << " - " << free_time.at(i).at(1).toString() << "\n";
	}
}

void UI::start()
{
	this->readTime();
	this->showFreeTime();
}
