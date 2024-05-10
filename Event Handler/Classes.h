#pragma once
#include <iostream>
#include <string>
#include <vector>


class DateTime
{
public:
	int day;
	std::string month;
	int year;
public:
	DateTime();
	DateTime(int d, std::string m, int y);
	

};


class Event
{
private:
	DateTime* event_dateTime;
	std::string m_event_location;
	std::string event_name;

public:

	Event();
	Event(DateTime* d, std::string loc, std::string evName);
   ~Event();

	const void LogEvent();
	
};

class Agenda
{
private:
	std::string m_agenda_name;
	std::vector<Event*> m_agenda_events;
public:
	Agenda();
	Agenda(std::string ag_n);
	~Agenda();

	friend void AddToAgenda(Event* &e, Agenda* &a);
	friend void LogAgenda(Agenda* &a);
	friend std::vector<Event*> ReturnAgendaSubsystem(Agenda* &a);
	friend void DeleteEvent(Agenda* &a, int index);
	friend void AssignBackToAgenda(Agenda* &a, std::vector<Event*> v);
	friend int getAgendaSubsystemCount(Agenda* &a);
	friend void DeleteAgenda(Agenda* &a);
};