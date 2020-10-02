#pragma once

#ifndef _EXTENDEDWORKTICKET
#define _EXTENDEDWORKTICKET

#include "WorkTicket.h";

using namespace std;

class ExtendedWorkTicket : public WorkTicket
{

public:
    ExtendedWorkTicket() : WorkTicket(), m_isOpen() { }
    ExtendedWorkTicket(const int ticketNumber, const string& clientId, const int month, const int day, const int year, const string& description, bool isOpen);

    bool IsOpen();

    void CloseTicket();

private:
    bool m_isOpen = true;

};

ExtendedWorkTicket::ExtendedWorkTicket(const int ticketNumber, const string& clientId, const int month, const int day, const int year, const string& description, bool isOpen)
    :WorkTicket(ticketNumber, clientId, month, day, year, description), m_isOpen(move(isOpen))
{

}

bool ExtendedWorkTicket::IsOpen()
{
    return m_isOpen;
}

void ExtendedWorkTicket::CloseTicket()
{
    m_isOpen = false;
}

#endif