//File:ExtendedWorkTicket.h
// Title:OOP 3200 Lab 3 - Inheritance
// Made by: Jacky Yuan, 100520106
//          Ashok Sasitharan, 100745484
// Date Created: October 2, 2020
// Description: Program used to generate and track work tickets for client requests.
//
// Change Log:N/A
//

#pragma once

#ifndef _EXTENDEDWORKTICKET
#define _EXTENDEDWORKTICKET

#include "WorkTicket.h";

using namespace std;

class ExtendedWorkTicket : public WorkTicket
{

public:
	
	//Default parameterized constructor 
    ExtendedWorkTicket() : WorkTicket(), m_IsOpen(true) { }
	
	//constructor for ExtendedWorkTicket
    ExtendedWorkTicket(const int ticketNumber, const string& clientId, const int month, const int day, const int year, const string& description, bool isOpen);

	//Accessors 
    bool IsOpen();
    void ShowWorkTicket()const override;

	//Mutators
    void CloseTicket();
    bool SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool isOpen);
	
	//overloaded output operator
    friend ostream& operator<<(ostream& out, const ExtendedWorkTicket& ticket);
	
private:
	
    bool m_IsOpen;

};

//initialize ExtendedWorkTicket
ExtendedWorkTicket::ExtendedWorkTicket(const int ticketNumber, const string& clientId, const int month, const int day, const int year, const string& description, bool isOpen)
    :WorkTicket(ticketNumber, clientId, month, day, year, description), m_IsOpen(isOpen)
{

}
//Returns value of IsOpen
bool ExtendedWorkTicket::IsOpen()
{
    return m_IsOpen;
}

//sets isOpen to false
void ExtendedWorkTicket::CloseTicket()
{
    m_IsOpen = false; //set IsOpen to false
}

// Overloaded SetWorkTicket
bool ExtendedWorkTicket::SetWorkTicket(const int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool isOpen)
{
    bool valid = true;
	//validations for IsOpen
    if (isOpen == NULL)
    {
        valid = false;
    }
    else if (isOpen == false)
    {
        valid = WorkTicket::SetWorkTicket(ticket_number, client_id, month, day, year, description);
        m_IsOpen = false;
    }
    else
    {
        valid = WorkTicket::SetWorkTicket(ticket_number, client_id, month, day, year, description);
        m_IsOpen = true;
    }
    return valid;
}

//override ShowWorkTicket
inline void ExtendedWorkTicket::ShowWorkTicket() const
{
    string isOpenText;
	//set an output string to either open or close 
	if(m_IsOpen == true)
	{
		isOpenText = "OPEN";
	}
	else
	{
	    isOpenText = "CLOSED";
	}
    // display the attributes of the object neatly to the console
    cout << "\nWork Ticket #: " << GetTicketNumber()
        << "\nClient ID:     " << GetClientId()
        << "\nDate:          " << GetDate()
        << "\nIssue:         " << GetDescription()
        << "\nTicket:        " << isOpenText << endl;
}

// overloaded output operator
ostream& operator<<(ostream& out, const ExtendedWorkTicket& ticket)
{
    string isOpenText;
	if(ticket.m_IsOpen == true)
	{
		isOpenText = "OPEN";
	}
	else
	{
	    isOpenText = "CLOSED";
	}
    // outputs WorkTicket attributes with formatting
    out << (WorkTicket)ticket
      << "Ticket:        " << isOpenText << endl;
   
    return out;
} 

#endif
