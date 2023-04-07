#pragma once
#include "Service.h"

class UI {
private:
	Service serv;
public:
	UI(Service serv);

	UI();

	UI(const UI& ui);

	Service getService();
	
	void readTime();

	void readBooking(int index);

	void showFreeTime();

	void start();
};