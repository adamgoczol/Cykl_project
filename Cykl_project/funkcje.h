/** @file */

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

/**
 * @brief mapa zwierajaca wierzcholki grafu skierowanego, np 'a' -> 'b' oznacza ¿e 'a' jest polaczone z 'b', a 'b' z 'a' juz nie 
*/

typedef std::map<int, std::vector<int>> Graph;

/**
 * @brief set zawierajacy pojedynczy cykl z grafu skierowanego np ('a' -> 'b' -> 'c', z czego cykl konczy sie na 'c', nie na 'a')
*/

typedef std::vector<int> Cycle;

/**
 * @brief vektor zaierajacy wszystkie cykle wystepujace w grafie skierowanym
*/

typedef std::vector<Cycle> Cycles;


/**
 * @brief funkcja odczytuje zawartosc podanego pliku i konwertuje go na mape
 * @param nazwa_pliku - nazwa pliku z ktorego chcemy czytac
 * @return mapa zawierajaca graf skierowany
*/

Graph czytaj_graf(const std::string& nazwa_pliku);

/**
 * @brief funkcja wypisuje zawartosc mapy w postaci grafu skierowanego (x -> y)
 * @param pary - mapa zawierajaca graf skierowany
*/

void wypisz_graf(const Graph& pary);

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
*/

void podszukanie(const Graph& graph, const int starting, int node,
    Cycles& cycles, Cycle cycle, std::set<int> visited, int depth);

void wyswietl_cykle(const Cycles& cycles);
#endif // !FUNKCJE_H

