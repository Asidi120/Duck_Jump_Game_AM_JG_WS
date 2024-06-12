#pragma once
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include "Gra.h"
#include <memory>
#include <string>

using namespace sql::mysql;
class Baza_Danych
{
public:
    Baza_Danych(const std::string& host, const std::string& uzytkownik, const std::string& haslo);
    ~Baza_Danych();
    void utworzBaze(const std::string& nazwaBazy);
    void wybierzBaze(const std::string& nazwaBazy);
    void utworzTabele();
private:
    sql::mysql::MySQL_Driver* sterownik;
    std::unique_ptr<sql::Connection> polaczenie;
    std::unique_ptr<sql::Statement> polecenie;
};

