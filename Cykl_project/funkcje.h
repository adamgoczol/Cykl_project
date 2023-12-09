/** @file */

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <string>
#include <sstream>

/**
 * @brief vector par wierzcholkow grafu
*/

typedef std::vector<std::pair<int, int>> vec_ark;


/**
 * @brief funkcja odczytuje zawartosc podanego pliku i konwertuje go na vector par
 * @param nazwa_pliku - nazwa pliku z ktorego chcemy czytac
 * @return vector par ktore sa wierzcholkami grafu
 * @todo nie wiem co robie wiec do zobaczenia w srode/czwartek
*/

vec_ark czytaj_pary(const std::string& nazwa_pliku);

/**
 * @brief funkcja wypisuje zawartosc wektora par w formacie wierzcholkow grafu
 * @param pary - vektor zawierajacy pary wierzcholkow grafu
*/

void wypisz_pary(const vec_ark& pary);

#endif // !FUNKCJE_H

