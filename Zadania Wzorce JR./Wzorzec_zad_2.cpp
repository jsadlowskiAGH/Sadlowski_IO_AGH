#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Klasa Recepta
class Recepta {
public:
    string numerRecepty;
    string imie;
    string nazwisko;
    string numerUbezpieczenia;
    vector<string> leki;
    bool zatwierdzona;
};

// Klasa Budowniczy dla Recepty
class ReceptaBuilder {
    Recepta recepta;

public:
    ReceptaBuilder& setNumerRecepty(const string& numer) {
        recepta.numerRecepty = numer;
        return *this;
    }

    ReceptaBuilder& setImie(const string& imie) {
        recepta.imie = imie;
        return *this;
    }

    ReceptaBuilder& setNazwisko(const string& nazwisko) {
        recepta.nazwisko = nazwisko;
        return *this;
    }

    ReceptaBuilder& setNumerUbezpieczenia(const string& numer) {
        recepta.numerUbezpieczenia = numer;
        return *this;
    }

    ReceptaBuilder& dodajLek(const string& lek) {
        recepta.leki.push_back(lek);
        return *this;
    }

    ReceptaBuilder& setZatwierdzona(bool zatwierdzona) {
        recepta.zatwierdzona = zatwierdzona;
        return *this;
    }

    Recepta build() {
        return recepta;
    }
};

// Klasa Stomatolog
class Stomatolog {
public:
    Recepta wystawRecepte() {
        ReceptaBuilder builder;
        string dane;

        cout << "Podaj imie pacjenta: ";
        cin >> dane;
        builder.setImie(dane);

        cout << "Podaj nazwisko pacjenta: ";
        cin >> dane;
        builder.setNazwisko(dane);

        cout << "Podaj numer ubezpieczenia zdrowotnego pacjenta: ";
        cin >> dane;
        builder.setNumerUbezpieczenia(dane);

        while (true) {
            cout << "Dodaj leki do recepty (wpisz 'koniec' aby zakonczyc):" << endl;
            cout << "Lek: ";
            cin >> dane;
            if (dane == "koniec") {
                break;
            }
            builder.dodajLek(dane);
        }

        return builder.setZatwierdzona(false).build();
    }
};

class SystemRecept {
public:
    vector<string> dostepneLeki;

    SystemRecept() {
        dostepneLeki = { "lek1", "lek2", "lek3", "lek4", "lek5", "lek6", "lek7", "lek8", "lek9", "lek10" };
    }

    void zapiszRecepte(const Recepta& recepta) {
        ofstream file("recepty.csv", ios::app); // tworzę tu receptę do wydruku, format .csv (excel)
        if (file.is_open()) {
            file << recepta.numerRecepty << "," << recepta.imie << "," << recepta.nazwisko << ","
                << recepta.numerUbezpieczenia << ",";
            for (const string& lek : recepta.leki) {
                file << lek << ";";
            }
            file << "," << (recepta.zatwierdzona ? "Zatwierdzona" : "Oczekujaca") << endl;
            file.close();
        }
        else {
            cout << "Nie mozna otworzyc pliku recepty.csv" << endl;
        }
    }

    bool sprawdzDostepnoscLeku(const string& lek) {
        for (const string& dostepnyLek : dostepneLeki) {
            if (dostepnyLek == lek) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Stomatolog stomatolog;
    SystemRecept systemRecept;

    cout << "1. Stomatolog loguje sie do systemu." << endl;

    cout << "2. Stomatolog wybiera opcje 'Wystaw recepte' z menu glownego." << endl;
    Recepta recepta = stomatolog.wystawRecepte();

    for (const string& lek : recepta.leki) {
        if (!systemRecept.sprawdzDostepnoscLeku(lek)) {
            cout << "Blad: Lek '" << lek << "' nie jest dostepny w magazynie." << endl;
            return 0;
        }
    }

    systemRecept.zapiszRecepte(recepta);

    cout << "Scenariusz alternatywny:" << endl;
    cout << "2. Stomatolog wybiera pacjenta, dla ktorego chce wystawic recepte." << endl;

    Recepta blednaRecepta = stomatolog.wystawRecepte();

    for (const string& lek : blednaRecepta.leki) {
        if (!systemRecept.sprawdzDostepnoscLeku(lek)) {
            cout << "Blad: Lek '" << lek << "' nie jest dostepny w magazynie." << endl;
            continue;
        }
    }

    systemRecept.zapiszRecepte(blednaRecepta);

    return 0;
}

//klasa ReceptaBuilder zawiera metody, które umożliwiają stopniowe budowanie obiektu Recepta. Klasa Stomatolog wykorzystuje ReceptaBuilder do tworzenia obiektu Recepta, co pozwala na bardziej elastyczne i przejrzyste zarządzanie procesem tworzenia recept.
