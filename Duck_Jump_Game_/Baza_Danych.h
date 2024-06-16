#include <sqlite3.h>
#include <iostream>
#include <string>
#include "Gra.h"

using namespace std;

// Klasa Baza_Danych zarz¹dza wszystkimi operacjami na bazie danych
class Baza_Danych 
{
    const char* sciezka_do_bazy;
    void stworzBaze();
    void stworzTabele();
    bool czyGraczIstnieje(const string& nazwa_gracza);
    static int callback(void* NotUsed, int argc, char** argv, char** azColName);
public:
    Baza_Danych(const char* sciezka) : sciezka_do_bazy(sciezka) {
        stworzBaze();
        stworzTabele();
    }

    void wstawDane(const string& nazwa_gracza, int najlepszy_wynik, int chlebki);
    void wstawLubAktualizujDane(const string& nazwa_gracza, int najlepszy_wynik, int chlebki);
    void uzupelnijSkins(const string& nazwa_gracza, bool skin1, bool skin2, bool skin3);
    void pobierzSkins(const string& nazwa_gracza, bool& skin1, bool& skin2, bool& skin3);
    void aktualizujDaneDlaGracza(const string& nazwa_gracza, int najlepszy_wynik, int chlebki);
    string pobierzOstatniegoGracza();
    void wypiszTop10();
    void aktualizujDane(int id_gracza, int najlepszy_wynik, int chlebki);
    int pobierzChlebki(const string& nazwa_gracza);
    int pobierzWynik(const string& nazwa_gracza);
    void usunDane(int id_gracza);
    void wybierzDane();
};

