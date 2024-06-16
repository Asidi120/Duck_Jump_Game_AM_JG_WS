#include "Baza_Danych.h"


// Funkcja tworz¹ca bazê danych, jeœli jeszcze nie istnieje
void Baza_Danych::stworzBaze() 
{
    sqlite3* baza;
    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    sqlite3_close(baza);
}

// Funkcja tworz¹ca tabelê GRACZE, jeœli jeszcze nie istnieje
void Baza_Danych::stworzTabele() 
{
    sqlite3* baza;
    char* bladWiadomosc;

    string sql = "CREATE TABLE IF NOT EXISTS GRACZE("
        "ID_GRACZA INTEGER PRIMARY KEY AUTOINCREMENT, "
        "NAZWA_GRACZA TEXT NOT NULL, "
        "NAJLEPSZY_WYNIK INT NOT NULL, "
        "CHLEBKI INT NOT NULL, "
        "SKIN1 BOOLEAN NOT NULL DEFAULT 0, "
        "SKIN2 BOOLEAN NOT NULL DEFAULT 0, "
        "SKIN3 BOOLEAN NOT NULL DEFAULT 0);";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    exit = sqlite3_exec(baza, sql.c_str(), NULL, 0, &bladWiadomosc);
    if (exit != SQLITE_OK) {
        cerr << "B³¹d w funkcji stworzTabele." << endl;
        sqlite3_free(bladWiadomosc);
    }
    else {
        cout << "Tabela utworzona pomyslnie." << endl;
    }
    sqlite3_close(baza);
}


// Funkcja sprawdzaj¹ca, czy gracz o danej nazwie ju¿ istnieje w bazie
bool Baza_Danych::czyGraczIstnieje(const string& nazwa_gracza) {
    sqlite3* baza;
    sqlite3_stmt* stmt;
    bool istnieje = false;

    string sql = "SELECT COUNT(*) FROM GRACZE WHERE NAZWA_GRACZA = ?;";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    if (exit == SQLITE_OK) {
        sqlite3_prepare_v2(baza, sql.c_str(), -1, &stmt, 0);
        sqlite3_bind_text(stmt, 1, nazwa_gracza.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            istnieje = sqlite3_column_int(stmt, 0) > 0;
        }
        sqlite3_finalize(stmt);
    }
    sqlite3_close(baza);
    return istnieje;
}

// Funkcja wstawiaj¹ca dane do tabeli GRACZE
void Baza_Danych::wstawDane(const string& nazwa_gracza, int najlepszy_wynik, int chlebki) 
{
    sqlite3* baza;
    char* wiadomosc_bledu;

    string sql = "INSERT INTO GRACZE (NAZWA_GRACZA, NAJLEPSZY_WYNIK, CHLEBKI) VALUES('"
        + nazwa_gracza + "', " + to_string(najlepszy_wynik) + ", " + to_string(chlebki) + ");";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    exit = sqlite3_exec(baza, sql.c_str(), NULL, 0, &wiadomosc_bledu);
    if (exit != SQLITE_OK) 
    {
        cerr << "Blad w funkcji wstawDane." << endl;
        sqlite3_free(wiadomosc_bledu);
    }
    else 
    {
        cout << "Rekordy wstawione pomyslnie." << endl;
    }
    sqlite3_close(baza);
}

// Funkcja wstawiaj¹ca nowe dane lub aktualizuj¹ca istniej¹ce
void Baza_Danych::wstawLubAktualizujDane(const string& nazwa_gracza, int najlepszy_wynik, int chlebki) 
{
    if (czyGraczIstnieje(nazwa_gracza)) {
        aktualizujDaneDlaGracza(nazwa_gracza, najlepszy_wynik, chlebki);
    }
    else {
        sqlite3* baza;
        char* bladWiadomosc;

        string sql = "INSERT INTO GRACZE (NAZWA_GRACZA, NAJLEPSZY_WYNIK, CHLEBKI) VALUES('"
            + nazwa_gracza + "', " + to_string(najlepszy_wynik) + ", " + to_string(chlebki) + ");";

        int exit = sqlite3_open(sciezka_do_bazy, &baza);
        exit = sqlite3_exec(baza, sql.c_str(), NULL, 0, &bladWiadomosc);
        if (exit != SQLITE_OK) {
            cerr << "Blad w funkcji wstawLubAktualizujDane." << endl;
            sqlite3_free(bladWiadomosc);
        }
        else {
            cout << "Rekord wstawiony pomyslnie!" << endl;
        }
        sqlite3_close(baza);
    }
}

void Baza_Danych::uzupelnijSkins(const string& nazwa_gracza, bool skin1, bool skin2, bool skin3) {
    sqlite3* baza;
    char* bladWiadomosc;

    string sql = "UPDATE GRACZE SET SKIN1 = ?, SKIN2 = ?, SKIN3 = ? WHERE NAZWA_GRACZA = ?;";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    if (exit == SQLITE_OK) {
        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(baza, sql.c_str(), -1, &stmt, 0);
        sqlite3_bind_int(stmt, 1, skin1);
        sqlite3_bind_int(stmt, 2, skin2);
        sqlite3_bind_int(stmt, 3, skin3);
        sqlite3_bind_text(stmt, 4, nazwa_gracza.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            cerr << "B³¹d w funkcji uzupelnijSkins." << endl;
        }
        else {
            cout << "Rekord zaktualizowany pomyœlnie!" << endl;
        }
        sqlite3_finalize(stmt);
    }
    sqlite3_close(baza);
}

void Baza_Danych::pobierzSkins(const string& nazwa_gracza, bool& skin1, bool& skin2, bool& skin3) {
    sqlite3* baza;
    sqlite3_stmt* stmt;

    string sql = "SELECT SKIN1, SKIN2, SKIN3 FROM GRACZE WHERE NAZWA_GRACZA = ?;";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    if (exit == SQLITE_OK) {
        sqlite3_prepare_v2(baza, sql.c_str(), -1, &stmt, 0);
        sqlite3_bind_text(stmt, 1, nazwa_gracza.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            skin1 = sqlite3_column_int(stmt, 0);
            skin2 = sqlite3_column_int(stmt, 1);
            skin3 = sqlite3_column_int(stmt, 2);
        }
        sqlite3_finalize(stmt);
    }
    else {
        cerr << "B³¹d w funkcji pobierzSkins." << endl;
    }
    sqlite3_close(baza);
}


// Funkcja aktualizuj¹ca dane gracza
void Baza_Danych::aktualizujDaneDlaGracza(const string& nazwa_gracza, int najlepszy_wynik, int chlebki) 
{
    sqlite3* baza;
    char* bladWiadomosc;

    string sql = "UPDATE GRACZE SET "
        "NAJLEPSZY_WYNIK = MAX(NAJLEPSZY_WYNIK, ?), "
        "CHLEBKI = CHLEBKI + ? "
        "WHERE NAZWA_GRACZA = ?;";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    if (exit == SQLITE_OK) {
        sqlite3_stmt* stmt;
        sqlite3_prepare_v2(baza, sql.c_str(), -1, &stmt, 0);
        sqlite3_bind_int(stmt, 1, najlepszy_wynik);
        sqlite3_bind_int(stmt, 2, chlebki);
        sqlite3_bind_text(stmt, 3, nazwa_gracza.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            cerr << "Blad w funkcji aktualizujDaneDlaGracza." << endl;
        }
        else {
            cout << "Rekord zaktualizowany pomyslnie." << endl;
        }
        sqlite3_finalize(stmt);
    }
    sqlite3_close(baza);
}

string Baza_Danych::pobierzOstatniegoGracza() {
    sqlite3* baza;
    sqlite3_stmt* stmt;
    string nazwa_gracza;

    string sql = "SELECT NAZWA_GRACZA FROM GRACZE ORDER BY ID_GRACZA DESC LIMIT 1;";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    if (exit == SQLITE_OK) {
        sqlite3_prepare_v2(baza, sql.c_str(), -1, &stmt, 0);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            nazwa_gracza = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        }
        sqlite3_finalize(stmt);
    }
    else {
        cerr << "B³¹d w funkcji pobierzOstatniegoGracza." << endl;
    }
    sqlite3_close(baza);
    return nazwa_gracza;
}


void Baza_Danych::wypiszTop10() 
{
    sqlite3* baza;
    char* bladWiadomosc;

    string sql = "SELECT NAZWA_GRACZA, NAJLEPSZY_WYNIK FROM GRACZE ORDER BY NAJLEPSZY_WYNIK DESC LIMIT 10;";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    exit = sqlite3_exec(baza, sql.c_str(), [](void*, int argc, char** argv, char** azColName) -> int {
        for (int i = 0; i < argc; i++) {
            cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << endl;
        }
        cout << endl;
        return 0;
        }, NULL, &bladWiadomosc);
    if (exit != SQLITE_OK) {
        cerr << "B³¹d w funkcji wypiszTop10." << endl;
        sqlite3_free(bladWiadomosc);
    }
    else {
        cout << "Top 10 najlepszych wynikow wypisane pomyslnie!" << endl;
    }
    sqlite3_close(baza);
}


// Funkcja aktualizuj¹ca dane w tabeli GRACZE
void Baza_Danych::aktualizujDane(int id_gracza, int najlepszy_wynik, int chlebki) 
{
    sqlite3* baza;
    char* wiadomosc_bledu;

    string sql = "UPDATE GRACZE SET NAJLEPSZY_WYNIK = " + to_string(najlepszy_wynik) +
        ", CHLEBKI = " + to_string(chlebki) + " WHERE ID_GRACZA = " + to_string(id_gracza) + ";";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    exit = sqlite3_exec(baza, sql.c_str(), NULL, 0, &wiadomosc_bledu);
    if (exit != SQLITE_OK) 
    {
        cerr << "Blad w funkcji aktualizujDane." << endl;
        sqlite3_free(wiadomosc_bledu);
    }
    else 
    {
        cout << "Rekordy zaktualizowane pomyslnie." << endl;
    }
    sqlite3_close(baza);
}

int Baza_Danych::pobierzChlebki(const string& nazwa_gracza) 
{
    sqlite3* baza;
    sqlite3_stmt* stmt;
    int chlebki = 0;

    string sql = "SELECT CHLEBKI FROM GRACZE WHERE NAZWA_GRACZA = ?;";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    if (exit == SQLITE_OK) {
        sqlite3_prepare_v2(baza, sql.c_str(), -1, &stmt, 0);
        sqlite3_bind_text(stmt, 1, nazwa_gracza.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            chlebki = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    else {
        cerr << "Blad w funkcji pobierzChlebki." << endl;
    }
    sqlite3_close(baza);
    return chlebki;
}

int Baza_Danych::pobierzWynik(const string& nazwa_gracza)
{
    sqlite3* baza;
    sqlite3_stmt* stmt;
    int chlebki = 0;

    string sql = "SELECT NAJLEPSZY_WYNIK FROM GRACZE WHERE NAZWA_GRACZA = ?;";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    if (exit == SQLITE_OK) {
        sqlite3_prepare_v2(baza, sql.c_str(), -1, &stmt, 0);
        sqlite3_bind_text(stmt, 1, nazwa_gracza.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            chlebki = sqlite3_column_int(stmt, 0);
        }
        sqlite3_finalize(stmt);
    }
    else {
        cerr << "Blad w funkcji pobierzWynik." << endl;
    }
    sqlite3_close(baza);
    return chlebki;
}

// Funkcja usuwaj¹ca dane z tabeli GRACZE
void Baza_Danych::usunDane(int id_gracza) 
{
    sqlite3* baza;
    char* wiadomosc_bledu;

    string sql = "DELETE FROM GRACZE WHERE ID_GRACZA = " + to_string(id_gracza) + ";";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    exit = sqlite3_exec(baza, sql.c_str(), callback, NULL, &wiadomosc_bledu);
    if (exit != SQLITE_OK) 
    {
        cerr << "Blad w funkcji usunDane." << endl;
        sqlite3_free(wiadomosc_bledu);
    }
    else 
    {
        cout << "Rekordy usuniete pomyslnie." << endl;
    }
    sqlite3_close(baza);
}

// Funkcja wybieraj¹ca dane z tabeli GRACZE
void Baza_Danych::wybierzDane() 
{
    sqlite3* baza;
    char* wiadomosc_bledu;

    string sql = "SELECT * FROM GRACZE;";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    exit = sqlite3_exec(baza, sql.c_str(), callback, NULL, &wiadomosc_bledu);
    if (exit != SQLITE_OK) {
        cerr << "Blad w funkcji wybierzDane." << endl;
        sqlite3_free(wiadomosc_bledu);
    }
    else {
        cout << "Rekordy wybrane pomyslnie." << endl;
    }
    sqlite3_close(baza);
}

// Funkcja zwrotna u¿ywana przez sqlite3_exec do przetwarzania wyników zapytañ
int Baza_Danych::callback(void* baza, int argc, char** argv, char** azColName) 
{
    for (int i = 0; i < argc; i++) 
    {
        cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << endl;
    }
    cout << endl;
    return 0;
}