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



