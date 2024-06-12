#include "Baza_Danych.h"

Baza_Danych::Baza_Danych(const std::string& host, const std::string& uzytkownik, const std::string& haslo) {
    try {
        sterownik = sql::mysql::get_mysql_driver_instance();
        polaczenie = std::unique_ptr<sql::Connection>(sterownik->connect(host, uzytkownik, haslo));
        polecenie = std::unique_ptr<sql::Statement>(polaczenie->createStatement());
    }
    catch (sql::SQLException& e) {
        std::cerr << "B��d SQL: " << e.what() << std::endl;
        throw;
    }
}

Baza_Danych::~Baza_Danych() {
    // Automatyczne czyszczenie zasob�w dzi�ki unique_ptr
}

void Baza_Danych::utworzBaze(const std::string& nazwaBazy) {
    try {
        polecenie->execute("CREATE DATABASE IF NOT EXISTS " + nazwaBazy);
        std::cout << "Baza danych " << nazwaBazy << " zosta�a utworzona." << std::endl;
    }
    catch (sql::SQLException& e) {
        std::cerr << "B��d SQL: " << e.what() << std::endl;
        throw;
    }
}

void Baza_Danych::wybierzBaze(const std::string& nazwaBazy) {
    try {
        polecenie->execute("USE " + nazwaBazy);
        std::cout << "Baza danych " << nazwaBazy << " zosta�a wybrana." << std::endl;
    }
    catch (sql::SQLException& e) {
        std::cerr << "B��d SQL: " << e.what() << std::endl;
        throw;
    }
}

void Baza_Danych::utworzTabele() {
    try {
        polecenie->execute("CREATE TABLE IF NOT EXISTS uzytkownicy ("
            "id INT AUTO_INCREMENT PRIMARY KEY, "
            "nazwa VARCHAR(255) NOT NULL, "
            "email VARCHAR(255) NOT NULL UNIQUE"
            ")");
        std::cout << "Tabela uzytkownicy zosta�a utworzona." << std::endl;
    }
    catch (sql::SQLException& e) {
        std::cerr << "B��d SQL: " << e.what() << std::endl;
        throw;
    }
}