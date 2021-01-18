#include "../inc/PrinterConnection.h"

int main()
{
    // PrinterConnection newConnection("random"); // Cannot create new object - constructor is private
    // PrinterConnection newConnection(*PrinterConnection::instance()); // Cannot create new object - copy constructor is private

    PrinterConnection::instance()->printID();
    PrinterConnection::instance()->changePrinter("XEROX PHASER 3200MFP");
    PrinterConnection::instance()->printID();
    PrinterConnection::printDocument();

    return 0;
}