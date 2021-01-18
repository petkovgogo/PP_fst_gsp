#ifndef PRINTER_CONNECTION_H
#define PRINTER_CONNECTION_H

class PrinterConnection
{
private:
    static PrinterConnection m_connection;
    const char *m_printer;

    PrinterConnection(const char *printer);
    PrinterConnection(PrinterConnection &connection);

public:
    static PrinterConnection *instance();
    static void printDocument();
    void changePrinter(const char *printer);
    void printID() const;
};

#endif // PRINTER_CONNECTION_H