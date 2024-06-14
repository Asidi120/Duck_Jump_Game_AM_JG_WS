#include <sqlite3.h>
#include <iostream>
#include <string>
#include "Gra.h"

using namespace std;

// Klasa Baza_Danych zarz¹dza wszystkimi operacjami na bazie danych
class Baza_Danych {
public:
    Baza_Danych(const char* sciezka) : sciezka_do_bazy(sciezka) {
        stworzBaze();
        stworzTabele();
    }

    void wstawDane(const string& nazwa_gracza, int najlepszy_wynik, int chlebki);
    void aktualizujDane(int id_gracza, int najlepszy_wynik, int chlebki);
    void usunDane(int id_gracza);
    void wybierzDane();

private:
    const char* sciezka_do_bazy;
    void stworzBaze();
    void stworzTabele();
    static int callback(void* NotUsed, int argc, char** argv, char** azColName);
};

