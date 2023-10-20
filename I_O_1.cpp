#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Produkt {
    std::string nazwa;
    double cena;
};

bool porownajCene(const Produkt& a, const Produkt& b) {
    return a.cena > b.cena;
}

int main() {
    std::vector<Produkt> listaProduktow;

    for (int i = 0; i < 10; i++) {
        Produkt p;

        std::cout << "Podaj nazw� produktu " << i + 1 << ": ";
        std::cin.ignore();
        std::getline(std::cin, p.nazwa);

        std::cout << "Podaj cen� produktu " << i + 1 << ": ";
        std::cin >> p.cena;

        listaProduktow.push_back(p);
    }

    std::sort(listaProduktow.begin(), listaProduktow.end(), porownajCene);

    std::cout << "\nLista produkt�w od najdro�szego do najta�szego:" << std::endl;
    for (const Produkt& p : listaProduktow) {
        std::cout << p.nazwa << " - " << p.cena << " z�" << std::endl;
    }

    return 0;
}
