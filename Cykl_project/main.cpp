/** @file */

#include "funkcje.h"

int main(int n, char * params[])
{
    std::set<std::string> valid_args{ "-g", "-c" };

    if (n != 5) {
        std::cout << "niewlasciwa ilosc argumentow" << std::endl;
        return 1;
    }

    std::map<std::string, std::string> args;

    for (int i = 1; i < n; i+=2) {
        if (valid_args.count(params[i]) != 1) {
            std::cout << "podany przelacznik " << params[i] << " nie istnieje" << std::endl;
            return 1;
        }
        if (valid_args.count(params[i + 1]) != 0) {
            std::cout << "przelacznik nie moze byc argumentem" << std::endl;
            return 1;
        }
        args[params[i]] = params[i + 1];
    }
    
    if (args["-c"].length() == 0) {
        std::cout << "nazwa pliku docelowego nie zostala podana" << std::endl;
        return 1;
    }
    if (args["-g"].length() == 0) {
        std::cout << "nazwa pliku wejsciowego nie zostala podana" << std::endl;
        return 1;
    }
        
    Graph graph = czytaj_graf(args["-g"]);

    if (graph.size() == 0) {
        std::cout << "graf skierowany nie posiada polaczen" << std::endl;
        return 1;
    }

    Cycles cycles = szukaj_cyklow(graph);

    wyswietl_cykle(cycles);
    zapisz_cykle(cycles, args["-c"]);

    return 0;
}