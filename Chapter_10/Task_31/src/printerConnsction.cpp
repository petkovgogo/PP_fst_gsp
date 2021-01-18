#include "../inc/PrinterConnection.h"

#include <iostream>

PrinterConnection PrinterConnection::m_connection("Dell s2830dn");

PrinterConnection::PrinterConnection(const char *printer)
{
    m_printer = printer;
}

PrinterConnection::PrinterConnection(PrinterConnection &connection) {}

PrinterConnection *PrinterConnection::instance()
{
    return &m_connection;
}

void PrinterConnection::printDocument()
{
    std::cout << "Printing document..." << std::endl;
}

void PrinterConnection::changePrinter(const char *printer)
{
    m_printer = printer;
}

void PrinterConnection::printID() const
{
    std::cout << "Connected to: " << m_printer << std::endl;
}