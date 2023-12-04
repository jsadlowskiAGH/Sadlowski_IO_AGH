#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Wizyta {
public:
    string data;
    string godzina;
    string klinika;
};

class SystemRejestracji {
public:
    vector<Wizyta> dostepneWizyty;

    SystemRejestracji() {
        // Inicjalizacja dostępnych wizyt (możesz dostosować do własnych potrzeb)
        dostepneWizyty = { {"2023-11-10", "10:00", "Klinika A"},
                          {"2023-11-10", "14:30", "Klinika B"},
                          {"2023-11-12", "11:15", "Klinika C"} };
    }

    bool zarezerwujWizyte(const string& preferowanaData, const string& preferowanaGodzina, Wizyta& zarezerwowanaWizyta) {
        for (const Wizyta& dostepnaWizyta : dostepneWizyty) {
            if (dostepnaWizyta.data == preferowanaData && dostepnaWizyta.godzina == preferowanaGodzina) {
                zarezerwowanaWizyta = dostepnaWizyta;
                return true;
            }
        }
        return false;
    }
};

int main() {
    SystemRejestracji systemRejestracji;

    cout << "Scenariusz główny:" << endl;
    cout << "1. Pacjent loguje się do systemu rejestracji wizyt." << endl;
    cout << "2. Pacjent wybiera dostępne daty i godziny wizyt w dostępnych klinikach." << endl;

    string preferowanaData, preferowanaGodzina;
    Wizyta zarezerwowanaWizyta;

    cout << "3. Pacjent wybiera preferowaną datę: ";
    cin >> preferowanaData;
    cout << "4. Pacjent wybiera preferowaną godzinę: ";
    cin >> preferowanaGodzina;

    if (systemRejestracji.zarezerwujWizyte(preferowanaData, preferowanaGodzina, zarezerwowanaWizyta)) {

        cout << "5. System potwierdza rezerwację." << endl;
        cout << "6. Pacjent otrzymuje potwierdzenie rezerwacji wizyty." << endl;
        cout << "Potwierdzenie rezerwacji: Data - " << zarezerwowanaWizyta.data
            << ", Godzina - " << zarezerwowanaWizyta.godzina
            << ", Klinika - " << zarezerwowanaWizyta.klinika << endl;
    }
    else {
        cout << "5. Nie udało się zarezerwować wizyty. Proszę wybrać inną datę i godzinę." << endl;
    }

    cout << "\nScenariusz alternatywny:" << endl;
    cout << "1. Pacjent loguje się do systemu rejestracji wizyt." << endl;
    cout << "2. Pacjent wybiera dostępne daty i godziny wizyt w dostępnych klinikach." << endl;

    cout << "3. Pacjent wybiera preferowaną datę: ";
    cin >> preferowanaData;
    cout << "4. Pacjent wybiera preferowaną godzinę: ";
    cin >> preferowanaGodzina;

    if (systemRejestracji.zarezerwujWizyte(preferowanaData, preferowanaGodzina, zarezerwowanaWizyta)) {

        cout << "5. System potwierdza rezerwację." << endl;
        cout << "6. Pacjent otrzymuje potwierdzenie rezerwacji wizyty." << endl;
        cout << "Potwierdzenie rezerwacji: Data - " << zarezerwowanaWizyta.data
            << ", Godzina - " << zarezerwowanaWizyta.godzina
            << ", Klinika - " << zarezerwowanaWizyta.klinika << endl;
    }
    else {

        cout << "5. System informuje pacjenta o braku dostępności wybranej daty i godziny wizyty." << endl;
        cout << "6. Pacjent wybiera inną dostępną datę i godzinę." << endl;

        cout << "Nowa preferowana data: ";
        cin >> preferowanaData;
        cout << "Nowa preferowana godzina: ";
        cin >> preferowanaGodzina;

        if (systemRejestracji.zarezerwujWizyte(preferowanaData, preferowanaGodzina, zarezerwowanaWizyta)) {
            cout << "7. System potwierdza rezerwację." << endl;
            cout << "8. Pacjent otrzymuje potwierdzenie rezerwacji wizyty." << endl;
            cout << "Potwierdzenie rezerwacji: Data - " << zarezerwowanaWizyta.data
                << ", Godzina - " << zarezerwowanaWizyta.godzina
                << ", Klinika - " << zarezerwowanaWizyta.klinika << endl;
        }
        else {
            cout << "7. Nie udało się zarezerwować wizyty. Proszę skontaktować się z obsługą." << endl;
        }
    }

    return 0;
}
