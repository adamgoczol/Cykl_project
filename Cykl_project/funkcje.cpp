#include "funkcje.h"
int sus(const double x1) {
    return 1;
}

void printus(int x) {
    std::cout << x << std::endl;
}

vec_ark czytaj_pary(const std::string& nazwa_pliku) {

    vec_ark zwrot;
    std::ifstream in(nazwa_pliku);
    
    if (in) {
        std::string strzalki;
        std::string linia;
        int start, stop;
        while (std::getline(in, linia, ',')) {
            std::stringstream ss(linia);

            ss >> start >> strzalki >> stop;
            std::cout << start << strzalki << stop << std::endl;
            zwrot.push_back(std::make_pair(start,stop));
        }
        in.close();
    }
    else {
        std::cout << "problem przy otwieraniu pliku" << std::endl;
    }
    return zwrot;

}

void wypisz_pary(const vec_ark& pary) {
    for (const auto& el : pary) {
        std::cout << el.first << " -> " << el.second << std::endl;
    }
    std::cout << std::endl;
}