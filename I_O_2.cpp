#include <iostream>

using namespace std;

int main() {
    const int rozmiar = 10;
    int AA[rozmiar];
    int* BB = nullptr;
    int liczbaUjemnych = 0;


    cout << "Podaj 10 liczb:" << endl;
    for (int i = 0; i < rozmiar; i++) {
        cin >> AA[i];
        if (AA[i] < 0) {
            liczbaUjemnych++;
        }
    }


    BB = new int[liczbaUjemnych];
    int j = 0;
    int i = 0;
    for (int i = 0; i < rozmiar; i++) {
        if (AA[i] < 0) {
            BB[j] = AA[i];
            j++;
        }
    }


    cout << "\nLiczby ujemne:" << endl;
    for (int i = 0; i < liczbaUjemnych; i++) {
        cout << BB[i] << " ";
    }

    cout << "\n\nLiczba liczb ujemnych: " << liczbaUjemnych << endl;
    cout << "Liczba liczb pominionych: " << rozmiar - liczbaUjemnych << endl;

    delete[] BB;

    return 0;
}
