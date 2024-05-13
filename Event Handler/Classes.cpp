#include "Classes.h"

DateTime::DateTime() {}
DateTime::DateTime(int d, std::string m, int y) : day(d), month(m), year(y) {}


Event::Event() {}
Event::Event(DateTime* d, std::string loc, std::string evName) : event_dateTime(d), m_event_location(loc), event_name(evName) 
{}
Event::~Event() {}



const void Event::LogEvent()
{
	std::cout << "***LOGGING EVENT***" << std::endl;
	std::cout << "Event name: " << this->event_name << '\n' <<
		"Event location: " << this->m_event_location << '\n' <<
		"Event date time: " << this->event_dateTime->day << '-' << this->event_dateTime->month << '-' <<
		this->event_dateTime->year << '.' << std::endl;
	std::cout << "\n\n\n";
}

Agenda::Agenda() { std::cout << "Agenda's been created.\n"; }
Agenda::Agenda(std::string ag_n) : m_agenda_name(ag_n) {}
Agenda::~Agenda() { std::cout << "Agenda has been deleted! [DESTRUCTOR CALL]\n"; }


void AddToAgenda(Event* &e, Agenda* &a)
{
	std::cout << "Are you sure you want to add this event to the agenda?\nConfirm! Y/N\n";
	char c;
	std::cin >> c;
	if (c == 'Y')
	{
		a->m_agenda_events.push_back(e);
	}
	else
	{
		delete e;
	}
}

void LogAgenda(Agenda*& a)
{
	if (a->m_agenda_events.size() != 0)
	{
		for (int i = 0; i < a->m_agenda_events.size(); i++)
		{
			a->m_agenda_events[i]->LogEvent();
		}
	}
	else
	{
		std::cout << "No events here. Try creating and adding an event to the agenda instead" << std::endl;
	}
}

std::vector<Event*> ReturnAgendaSubsystem(Agenda*& a)
{
	std::vector<Event*> v;
	v = a->m_agenda_events;
	return v;
}

void DeleteEvent(Agenda*& a, int index)
{
	
	std::cout << "Are you sure you want to delete this event? Y/N\n";
	char c;
	std::cin >> c;
	if (c == 'Y')
	{
		delete a->m_agenda_events[index-1];
		std::cout << "Last event has been deleted successfully!" << std::endl;
	}
	else
		return;
}

void AssignBackToAgenda(Agenda*& a, std::vector<Event*> v)
{
	a->m_agenda_events = v;
}

int getAgendaSubsystemCount(Agenda*& a)
{
	return a->m_agenda_events.size();
}

void DeleteAgenda(Agenda*& a)
{
	std::cout << "Are you sure you want to delete this agenda? Y/N\n";
	char c;
	std::cin >> c;
	if (c == 'Y')
	{
		delete a;
	}
	else
		return;
}



