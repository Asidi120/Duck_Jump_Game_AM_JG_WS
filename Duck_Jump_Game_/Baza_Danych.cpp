#include "Baza_Danych.h"
// Funkcja tworz¹ca bazê danych, jeœli jeszcze nie istnieje
void Baza_Danych::stworzBaze() {
    sqlite3* baza;
    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    sqlite3_close(baza);
}

// Funkcja tworz¹ca tabelê GRACZE, jeœli jeszcze nie istnieje
void Baza_Danych::stworzTabele() {
    sqlite3* baza;
    char* bladWiadomosc;

    string sql = "CREATE TABLE IF NOT EXISTS GRACZE("
        "ID_GRACZA INTEGER PRIMARY KEY AUTOINCREMENT, "
        "NAZWA_GRACZA TEXT NOT NULL, "
        "NAJLEPSZY_WYNIK INT NOT NULL, "
        "CHLEBKI INT NOT NULL);";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    exit = sqlite3_exec(baza, sql.c_str(), NULL, 0, &bladWiadomosc);
    if (exit != SQLITE_OK) {
        cerr << "B³¹d w funkcji stworzTabele." << endl;
        sqlite3_free(bladWiadomosc);
    }
    else {
        cout << "Tabela utworzona pomyœlnie." << endl;
    }
    sqlite3_close(baza);
}

// Funkcja wstawiaj¹ca dane do tabeli GRACZE
void Baza_Danych::wstawDane(const string& nazwa_gracza, int najlepszy_wynik, int chlebki) {
    sqlite3* baza;
    char* bladWiadomosc;

    string sql = "INSERT INTO GRACZE (NAZWA_GRACZA, NAJLEPSZY_WYNIK, CHLEBKI) VALUES('"
        + nazwa_gracza + "', " + to_string(najlepszy_wynik) + ", " + to_string(chlebki) + ");";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    exit = sqlite3_exec(baza, sql.c_str(), NULL, 0, &bladWiadomosc);
    if (exit != SQLITE_OK) {
        cerr << "B³¹d w funkcji wstawDane." << endl;
        sqlite3_free(bladWiadomosc);
    }
    else {
        cout << "Rekordy wstawione pomyœlnie!" << endl;
    }
    sqlite3_close(baza);
}

// Funkcja aktualizuj¹ca dane w tabeli GRACZE
void Baza_Danych::aktualizujDane(int id_gracza, int najlepszy_wynik, int chlebki) {
    sqlite3* baza;
    char* bladWiadomosc;

    string sql = "UPDATE GRACZE SET NAJLEPSZY_WYNIK = " + to_string(najlepszy_wynik) +
        ", CHLEBKI = " + to_string(chlebki) + " WHERE ID_GRACZA = " + to_string(id_gracza) + ";";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    exit = sqlite3_exec(baza, sql.c_str(), NULL, 0, &bladWiadomosc);
    if (exit != SQLITE_OK) {
        cerr << "B³¹d w funkcji aktualizujDane." << endl;
        sqlite3_free(bladWiadomosc);
    }
    else {
        cout << "Rekordy zaktualizowane pomyœlnie!" << endl;
    }
    sqlite3_close(baza);
}

// Funkcja usuwaj¹ca dane z tabeli GRACZE
void Baza_Danych::usunDane(int id_gracza) {
    sqlite3* baza;
    char* bladWiadomosc;

    string sql = "DELETE FROM GRACZE WHERE ID_GRACZA = " + to_string(id_gracza) + ";";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    exit = sqlite3_exec(baza, sql.c_str(), callback, NULL, &bladWiadomosc);
    if (exit != SQLITE_OK) {
        cerr << "B³¹d w funkcji usunDane." << endl;
        sqlite3_free(bladWiadomosc);
    }
    else {
        cout << "Rekordy usuniête pomyœlnie!" << endl;
    }
    sqlite3_close(baza);
}

// Funkcja wybieraj¹ca dane z tabeli GRACZE
void Baza_Danych::wybierzDane() {
    sqlite3* baza;
    char* bladWiadomosc;

    string sql = "SELECT * FROM GRACZE;";

    int exit = sqlite3_open(sciezka_do_bazy, &baza);
    exit = sqlite3_exec(baza, sql.c_str(), callback, NULL, &bladWiadomosc);
    if (exit != SQLITE_OK) {
        cerr << "B³¹d w funkcji wybierzDane." << endl;
        sqlite3_free(bladWiadomosc);
    }
    else {
        cout << "Rekordy wybrane pomyœlnie!" << endl;
    }
    sqlite3_close(baza);
}

// Funkcja zwrotna u¿ywana przez sqlite3_exec do przetwarzania wyników zapytañ
int Baza_Danych::callback(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << endl;
    }
    cout << endl;
    return 0;
}