/** @file funkcje.h 
    @author Adam Goczol
    @date 13.01.2024
    @brief plik zawiera deklaracje funkcji
*/

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <iostream>
#include <fstream>
#include <set>
#include <utility>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
#include <fstream>

/**
 * @brief mapa zwierajaca wierzcholki grafu skierowanego, np 'a' -> 'b' oznacza ze 'a' jest polaczone z 'b', a 'b' z 'a' juz nie 
*/

typedef std::map<int, std::vector<int>> Graph;

/**
 * @brief vektor zawierajacy pojedynczy cykl z grafu skierowanego np ('a' -> 'b' -> 'c', z czego cykl konczy sie na 'c', nie na 'a')
*/

typedef std::vector<int> Cycle;

/**
 * @brief vektor zawierajacy wszystkie cykle wystepujace w grafie skierowanym
*/

typedef std::vector<Cycle> Cycles;

/**
 * @brief funkcja sprawdza czy podany string mozna przekonwertowac na int
 * @param text - string do sprawdzenia
 * @author Adam Goczol
 * @return true jesli sie da, false jesli nie
*/

bool isnumber(std::string& text);


/**
 * @brief funkcja porownuje dwa vektory (uzywa sortowania)
 * @param v1 - pierwszy vektor
 * @param v2 - drugi vektor
 * @return true jesli sa identyczne, false jesli nie
*/

bool porownaj(std::vector<int> v1, std::vector<int> v2);

/**
 * @brief funkcja odczytuje zawartosc podanego pliku i konwertuje go na mape
 * @param nazwa_pliku - nazwa pliku z ktorego chcemy czytac
 * @return mapa zawierajaca graf skierowany
*/

Graph czytaj_graf(const std::string& nazwa_pliku);

/**
 * @brief funkcja sprawdza czy podany cykl wystepuje w vektorze cyklow
 * @param cycles - vektor cyklow
 * @param cycle - pojedynczy vektor zawierajacy cykl
 * @return true jesli nie wystepuje, false jesli wystepuje
*/

bool czy_nowy_cykl(const Cycles& cycles, const Cycle& cycle);


/**
 * @brief funkcja wypisuje zawartosc mapy w postaci grafu skierowanego (x -> y)
 * @param graph - mapa zawierajaca graf skierowany
*/

void wypisz_graf(const Graph& graph);

/**
 * @brief funkcja zwraca znalezione cykle w podanym grafie skierowanym
 * @param graph - graf skierowany
 * @return vektor zawierajacy znalezione cykle
*/

Cycles szukaj_cyklow(const Graph& graph);

/**
 * @brief rekurencyjna funkcja znajdujaca cykle w grafie o podanym poczatku
 * @param graph - graf skierowany
 * @param starting - poczatek ktory musi byc koncem cyklu
 * @param node - aktualnie sprawdzana krawedz grafu skierowanego
 * @param cycles - vektor zawierajacy znalezione cykle
 * @param cycle - aktualnie sprawdzany cykl
 * @param visited - odwiedzone krawedzie
 * @param depth - glebokosc rekurencji
 */

void podszukanie(const Graph& graph, const int starting, int node,
    Cycles& cycles, Cycle cycle, std::set<int> visited, int depth);

/**
 * @brief funkcja wyswietla podany vektor cyklow
 * @param cycles - vektor zawierajacy cykle do wyswietlenia
*/

void wyswietl_cykle(const Cycles& cycles);

/**
 * @brief funkcja zapisuje podany vektor cyklow do pliku
 * @param cycles - vektor zawierajacy cykle do zapisania
 * @param filename - nazwa pliku
*/

void zapisz_cykle(const Cycles& cycles, const std::string filename);



#endif // !FUNKCJE_H

