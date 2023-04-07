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

	CalendarRepository getRepository1();

	CalendarRepository getRepository2();

	void addBookingService(string first_time, string second_time, int index);

	void addTimeRange(string first_time, string second_time, int index);

	void addMeetingTime(int minute);

	Time stringToTime(string time);

	int checkTimeValid(string time);

	int checkUpperLimit(string lower_limit_range, string upper_limit_range);

	int checkBookingInRange(string time, int index);

	int checkBookingValid(string lower_limit_booking, string upper_limit_booking, int index);

	int compareTime(Time t1, Time t2);

	vector<vector<Time>> findFreeTime(int index);

	vector<vector<Time>> findCommonFreeTime();
};
