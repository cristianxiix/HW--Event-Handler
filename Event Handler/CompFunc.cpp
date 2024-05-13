#include "Classes.h"



Agenda* CreateAgenda()
{
	std::string agn;
	std::cout << "Insert agenda name:\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, agn);
	Agenda* a = new Agenda(agn);
	std::cout << "Agenda successfully created!" << std::endl;
	return a;
}

Event* createEvent()
{

	std::string tempN;
	std::string tempLoc;
	DateTime* dt = new DateTime();
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "What name should i assign to your event?\n";
	std::cin >> tempN;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "What location should i assign to your event?(string)\n";
	std::getline(std::cin, tempLoc);
	std::cout << "What date time should i assign to your event?\nInsert day, month, year one after the other:\n";
	std::cout << "day: \n";
	std::cin >> dt->day;
	std::cout << "month: \n";
	std::cin >> dt->month;
	std::cout << "year: \n";
	std::cin >> dt->year;

	Event* e = new Event(dt, tempLoc, tempN);
	std::cout << "Event successfully created!" << std::endl;
	return e;
}

int startProgram()
{
	const char* prompt = R"(
	Welcome to your favorite EVENT HANDLER!
	Your choices FOR NOW are as follows:
	1.Create Agenda
	2.Exit
)";
	std::cout << prompt;
	return 0;
}

void keep_running()
{
	const char* prompt2 = R"(
1.Create Event
2.Delete Event
3.Log Agenda
4.Delete Agenda
5.Exit
)";
	std::cout << prompt2;
}



