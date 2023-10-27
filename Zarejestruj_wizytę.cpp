include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

class Recepta {
private:
    string imiePacjenta;
    string nazwiskoPacjenta;
    string lek;
    string dawkowanie;
    string uwagi;
    string dataWystawienia;

    string pobierzDate() {
        time_t now = time(0);
        char* dt = ctime(&now);
        return string(dt);
    }

public:
    Recepta(string imie, string nazwisko, string lek, string dawkowanie, string uwagi = "")
        : imiePacjenta(imie), nazwiskoPacjenta(nazwisko), lek(lek), dawkowanie(dawkowanie), uwagi(uwagi) {
        dataWystawienia = pobierzDate();
    }

    void zapiszRecepte() {
        std::ofstream plik("recepta.txt");
        if (plik.is_open()) {
            plik << "Recepta stomatologiczna" << std::endl;
            plik << "Data wystawienia: " << dataWystawienia << std::endl;
            plik << "Pacjent: " << imiePacjenta << " " << nazwiskoPacjenta << std::endl;
            plik << "Lek: " << lek << std::endl;
            plik << "Dawkowanie: " << dawkowanie << std::endl;
            if (!uwagi.empty()) {
                plik << "Uwagi: " << uwagi << std::endl;
            }
            plik.close();
            std::cout << "Recepta zosta³a zapisana do pliku 'recepta.txt'." << std::endl;
        }
        else {
            std::cout << "B³¹d podczas zapisu do pliku!" << std::endl;
        }
    }
};

int main() {
    std::string imie, nazwisko, lek, dawkowanie, uwagi;

    std::cout << "Wystawianie recepty stomatologicznej" << std::endl;
    std::cout << "Podaj imiê pacjenta: ";
    std::cin >> imie;
    std::cout << "Podaj nazwisko pacjenta: ";
    std::cin >> nazwisko;
    std::cout << "Podaj nazwê leku: ";
    std::cin >> lek;
    std::cout << "Podaj dawkowanie (np. 2 tabletki dziennie): ";
    std::cin.ignore();
    std::getline(std::cin, dawkowanie);
    std::cout << "Podaj ewentualne uwagi (lub wpisz 'brak', jeœli nie ma): ";
    std::getline(std::cin, uwagi);
    if (uwagi == "brak") {
        uwagi = "";
    }

    Recepta recepta(imie, nazwisko, lek, dawkowanie, uwagi);
    recepta.zapiszRecepte();

    return 0;
}


    

