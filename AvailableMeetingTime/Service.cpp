#pragma once
#include "Service.h"

Service::Service(CalendarRepository& repo1, CalendarRepository& repo2)
{
	this->repo1 = repo1;
	this->repo2 = repo2;
}

Service::Service()
{
}

Service::Service(const Service& serv)
{
	this->repo1 = serv.repo1;
	this->repo2 = serv.repo2;
}

CalendarRepository Service::getRepository1()
{
	return this->repo1;
}

CalendarRepository Service::getRepository2()
{
	return this->repo2;
}

void Service::addBookingService(string first_time, string second_time, int index)
{
    Time t1 = this->stringToTime(first_time);
    Time t2 = this->stringToTime(second_time);
    vector<Time> booking;
    booking.push_back(t1);
    booking.push_back(t2);
    if (index == 1) {
        this->repo1.addBooking(booking);
    }
    else {
        this->repo2.addBooking(booking);
    }
}

void Service::addTimeRange(string first_time, string second_time, int index)
{
    Time t1 = this->stringToTime(first_time);
    Time t2 = this->stringToTime(second_time);
    if (index == 1) {
        this->repo1.setLowerTimeRange(t1);
        this->repo1.setUpperTimeRange(t2);
    }
    else {
        this->repo2.setLowerTimeRange(t1);
        this->repo2.setUpperTimeRange(t2);
    }
 }

void Service::addMeetingTime(int minute)
{
    this->repo1.setMeetingTime(minute);
    this->repo2.setMeetingTime(minute);
}

Time Service::stringToTime(string time)
{
    int hour, minute;
    if (time[1] == ':') {
        hour = time[0] - '0';
    }
    else if (time[2] == ':') {
        hour = (time[0] - '0') * 10 + (time[1] - '0');
    }
    minute = (time[time.length() - 2] - '0') * 10 + (time[time.length() - 1] - '0');
    return Time{hour, minute};
}

int Service::checkTimeValid(string time)
{
    if (time.length() != 5 && time.length() != 4) {
        return 0;
    }

    int hour;
    if (time[1] == ':') {
        hour = time[0] - '0';
    }
    else if (time[2] == ':') {
        hour = (time[0] - '0') * 10 + (time[1] - '0');
    }
    else {
        return 0;
    }
    if (hour < 0 || hour > 23) {
        return 0;
    }

    int minute;
    if (time[1] == ':' || time[2] == ':') {
        minute = (time[time.length() - 2] - '0') * 10 + (time[time.length() - 1] - '0');
    }
    else {
        return 0;
    }
    if (minute < 0 || minute > 59) {
        return 0;
    }

    return 1;
}

int Service::checkUpperLimit(string lower_limit_range, string upper_limit_range)
{
    Time t1 = stringToTime(lower_limit_range);
    Time t2 = stringToTime(upper_limit_range);
    if (t2.getHour() < t1.getHour())
        return 0;
    else {
        if (t2.getHour() == t1.getHour()) {
            if (t2.getMinute() <= t1.getMinute())
                return 0;
            else
                return 1;
        }
        else
            return 1;
    }
}

int Service::checkBookingInRange(string time, int index)
{
    Time t1 = stringToTime(time);
    if (index == 1) {
        if (t1.getHour() < this->repo1.getLowerLimitRange().getHour()) {
            return 0;
        }
        else {
            if (t1.getHour() == this->repo1.getLowerLimitRange().getHour()) {
                if (t1.getMinute() < this->repo1.getLowerLimitRange().getMinute())
                    return 0;
            }
            else {
                if (t1.getHour() == this->repo1.getUpperLimitRange().getHour()) {
                    if (t1.getMinute() > this->repo1.getUpperLimitRange().getMinute())
                        return 0;
                }
                else {
                    if (t1.getHour() > this->repo1.getUpperLimitRange().getHour())
                        return 0;
                }
            }
        }
        return 1;
    }
    else {
        if (t1.getHour() < this->repo2.getLowerLimitRange().getHour()) {
            return 0;
        }
        else {
            if (t1.getHour() == this->repo2.getLowerLimitRange().getHour()) {
                if (t1.getMinute() < this->repo2.getLowerLimitRange().getMinute())
                    return 0;
            }
            else {
                if (t1.getHour() == this->repo2.getUpperLimitRange().getHour()) {
                    if (t1.getMinute() > this->repo2.getUpperLimitRange().getMinute())
                        return 0;
                }
                else {
                    if (t1.getHour() > this->repo2.getUpperLimitRange().getHour())
                        return 0;
                }
            }
        }
        return 1;
    }
}

int Service::checkBookingValid(string lower_limit_booking, string upper_limit_booking, int index)
{
    Time first_time = stringToTime(lower_limit_booking);
    Time second_time = stringToTime(upper_limit_booking);
    if (index == 1) {
        for (int i = 0; i < this->repo1.getBooking().size(); i++) {
            if (compareTime(first_time, this->repo1.getBooking().at(i).at(0)) == 1 && compareTime(first_time, this->repo1.getBooking().at(i).at(1)) == 2)
                return 0;
            else {
                if (compareTime(second_time, this->repo1.getBooking().at(i).at(0)) == 1 && compareTime(second_time, this->repo1.getBooking().at(i).at(1)) == 2)
                    return 0;
                else {
                    if (compareTime(first_time, this->repo1.getBooking().at(i).at(0)) == 2 && compareTime(second_time, this->repo1.getBooking().at(i).at(1)) == 1)
                        return 0;
                }
            }
        }
        return 1;
    }
    else {
        for (int i = 0; i < this->repo2.getBooking().size(); i++) {
            if (compareTime(first_time, this->repo2.getBooking().at(i).at(0)) == 1 && compareTime(first_time, this->repo2.getBooking().at(i).at(1)) == 2)
                return 0;
            else {
                if (compareTime(second_time, this->repo2.getBooking().at(i).at(0)) == 1 && compareTime(second_time, this->repo2.getBooking().at(i).at(1)) == 2)
                    return 0;
                else {
                    if (compareTime(first_time, this->repo2.getBooking().at(i).at(0)) == 2 && compareTime(second_time, this->repo2.getBooking().at(i).at(1)) == 1)
                        return 0;
                }
            }
        }
        return 1;
    }
}

int Service::compareTime(Time t1, Time t2)
{
    if (t1.getHour() > t2.getHour()) {
        return 1;
    }
    else if (t1.getHour() < t2.getHour()) {
        return 2;
    }
    else {
        if (t1.getMinute() > t2.getMinute()) {
            return 1;
        }
        else if (t1.getMinute() < t2.getMinute()) {
            return 2;
        }
        else {
            return 0;
        }
    }
}

vector<vector<Time>> Service::findFreeTime(int index)
{
    vector<vector<Time>> free_slots;
    vector<Time> slot;

    if (index == 1) {
        Time start_time = repo1.getLowerLimitRange();
        Time end_time = repo1.getUpperLimitRange();

        for (int i = 0; i < repo1.getBooking().size(); i++) {
            Time booking_start_time = repo1.getBooking().at(i).at(0);
            Time booking_end_time = repo1.getBooking().at(i).at(1);

            if (booking_start_time.getHour() > start_time.getHour() ||
                (booking_start_time.getHour() == start_time.getHour() && booking_start_time.getMinute() > start_time.getMinute())) {
                Time free_start_time = start_time;
                Time free_end_time = booking_start_time;
                slot.push_back(free_start_time);
                slot.push_back(free_end_time);
                free_slots.push_back(slot);
                slot.clear();
            }
            start_time = booking_end_time;
        }

        if (start_time.getHour() < end_time.getHour() ||
            (start_time.getHour() == end_time.getHour() && start_time.getMinute() < end_time.getMinute())) {
            Time free_start_time = start_time;
            Time free_end_time = end_time;
            slot.push_back(free_start_time);
            slot.push_back(free_end_time);
            free_slots.push_back(slot);
        }

        return free_slots;
    }
    else {
        Time start_time = repo2.getLowerLimitRange();
        Time end_time = repo2.getUpperLimitRange();

        for (int i = 0; i < repo2.getBooking().size(); i++) {
            Time booking_start_time = repo2.getBooking().at(i).at(0);
            Time booking_end_time = repo2.getBooking().at(i).at(1);

            if (booking_start_time.getHour() > start_time.getHour() ||
                (booking_start_time.getHour() == start_time.getHour() && booking_start_time.getMinute() > start_time.getMinute())) {
                Time free_start_time = start_time;
                Time free_end_time = booking_start_time;
                slot.push_back(free_start_time);
                slot.push_back(free_end_time);
                free_slots.push_back(slot);
                slot.clear();
            }

            start_time = booking_end_time;
        }

        if (start_time.getHour() < end_time.getHour() ||
            (start_time.getHour() == end_time.getHour() && start_time.getMinute() < end_time.getMinute())) {
            Time free_start_time = start_time;
            Time free_end_time = end_time;
            slot.push_back(free_start_time);
            slot.push_back(free_end_time);
            free_slots.push_back(slot);
        }

        return free_slots;
    }
}

vector<vector<Time>> Service::findCommonFreeTime()
{
    vector<vector<Time>> free_time_slots1 = this->findFreeTime(1);
    vector<vector<Time>> free_time_slots2 = this->findFreeTime(2);

    vector<vector<Time>> commonFreeTimeSlots;

    int i = 0, j = 0;
    while (i < free_time_slots1.size() && j < free_time_slots2.size()) {
        Time start1 = free_time_slots1[i][0];
        Time end1 = free_time_slots1[i][1];
        Time start2 = free_time_slots2[j][0];
        Time end2 = free_time_slots2[j][1];

        if (this->compareTime(start2, end1) == 1) {
            i++;
        }
        else if (this->compareTime(start1, end2) == 1) {
            j++;
        }
        else {
            Time start = this->compareTime(start2, start1) == 2 ? start1 : start2;
            Time end = this->compareTime(end2, end1) == 1 ? end1 : end2;
            Time start_check = start;
            start_check.addMinutes(repo1.getMeetingTime());
            if (this->compareTime(end, start_check) <= 1) {
                commonFreeTimeSlots.push_back({ start, end });
            }
            if (this->compareTime(end2, end1) == 1) {
                i++;
            }
            else {
                j++;
            }
        }
    }
    return commonFreeTimeSlots;
}
