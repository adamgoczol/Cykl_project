/** @file */

#include <iostream>
#include "funkcje.h"

int main()
{
    Graph graph = czytaj_graf("grafy.txt");

    Cycles cycles = szukaj_cyklow(graph);

    wyswietl_cykle(cycles);

    return 0;
}