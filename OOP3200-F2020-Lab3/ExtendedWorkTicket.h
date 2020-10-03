#pragma once

#ifndef _EXTENDEDWORKTICKET
#define _EXTENDEDWORKTICKET

#include "WorkTicket.h";

using namespace std;

class ExtendedWorkTicket : public WorkTicket
{

public:
    ExtendedWorkTicket() : WorkTicket(), m_IsOpen(true) { }
    ExtendedWorkTicket(const int ticketNumber, const string& clientId, const int month, const int day, const int year, const string& description, bool isOpen);

    bool IsOpen();
    bool SetWorkTicket(int ticket_number, const string& client_id, int day, int month, int year, const string&
        description, bool isOpen);

    void ShowWorkTicket()const override;
    void CloseTicket();

private:
    bool m_IsOpen;

};

ExtendedWorkTicket::ExtendedWorkTicket(const int ticketNumber, const string& clientId, const int month, const int day, const int year, const string& description, bool isOpen)
    :WorkTicket(ticketNumber, clientId, month, day, year, description), m_IsOpen(move(isOpen))
{

}

bool ExtendedWorkTicket::IsOpen()
{
    return m_IsOpen;
}

void ExtendedWorkTicket::CloseTicket()
{
    m_IsOpen = false;
}

// ExtendedWorkTicket::SetTicket definition
bool ExtendedWorkTicket::SetWorkTicket(const int ticket_number, const string& client_id, int day, int month, int year, const string& description, bool isOpen)
{
    bool valid = true;
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

inline void ExtendedWorkTicket::ShowWorkTicket() const
{
    string isOpenText;
	if(m_IsOpen==true)
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


#endif
