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

