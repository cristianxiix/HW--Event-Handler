#pragma once
#include "Classes.h"
#include "CompFunc.h"


int main()
{
	
		int choice = startProgram();
		std::vector<Event*> temp_EventVector;
		Agenda* tempAgenda = nullptr;
		Event* tempEvent = nullptr;

		while (choice >= 0)
		{
			std::cin >> choice;
			switch (choice)
			{
			case 1:
			{
				tempAgenda = CreateAgenda();
				temp_EventVector = ReturnAgendaSubsystem(tempAgenda);
				choice = 0;
				break;
			}
			case 2: std::cout << "Program will exit now." << std::endl; delete tempEvent; delete tempAgenda; break;
			default:
			{
				std::cout << "ERROR.";
				delete tempAgenda;
				choice = startProgram();
				continue;
			}
			}
			break;
		}
		std::cout << std::endl;

		while (choice >= 0 && choice <= 4)
		{
			keep_running();
			std::cin >> choice;
			switch (choice)
			{
			case 1:
			{
				tempEvent = createEvent();
				AddToAgenda(tempEvent, tempAgenda); ////dereference
				temp_EventVector.push_back(tempEvent);
				tempEvent = nullptr;
				break;
			}
			case 2: //delete Event
			{
					int index = 0;
					std::cout << "Please enter the desired event's index:" << std::endl;
					std::cin >> index;
					DeleteEvent(tempAgenda, index);
					temp_EventVector.resize(temp_EventVector.size() - 1);
					AssignBackToAgenda(tempAgenda, temp_EventVector);
				break;
			}
				case 3:
				{
					LogAgenda(tempAgenda); 
					break;
				}
				case 4:
				{
					DeleteAgenda(tempAgenda);
					break;
				}
			}
		}
		std::cout << "Program will exit now." << std::endl;
		delete tempEvent; 
		delete tempAgenda;

}



