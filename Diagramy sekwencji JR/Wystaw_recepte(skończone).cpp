#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Recepta {
public:
    string numerRecepty;
    string imie;
    string nazwisko;
    string numerUbezpieczenia;
    vector<string> leki;
    bool zatwierdzona;
};

class Stomatolog {
public:
    Recepta wystawRecepte() {
        Recepta recepta;
        recepta.zatwierdzona = false;

        cout << "Podaj imie pacjenta: ";
        cin >> recepta.imie;
        cout << "Podaj nazwisko pacjenta: ";
        cin >> recepta.nazwisko;
        cout << "Podaj numer ubezpieczenia zdrowotnego pacjenta: ";
        cin >> recepta.numerUbezpieczenia;

        while (true) {
            cout << "Dodaj leki do recepty (wpisz 'koniec' aby zakonczyc):" << endl;
            string lek;
            cout << "Lek: ";
            cin >> lek;
            if (lek == "koniec") {
                break;
            }
            recepta.leki.push_back(lek);
        }


        return recepta;
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
