#include <iostream>
#include <vector>
#include <string>
#include "UI.h"

int main() {
	CalendarRepository repo1{};
	CalendarRepository repo2{};
	Service serv{ repo1, repo2 };
	UI ui{ serv };
	ui.start();
	return 0;
}