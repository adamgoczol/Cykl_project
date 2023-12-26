/** @file */

#include "funkcje.h"

int main(int ile, char * params[])
{


    std::string infile;
    std::string outfile;

    if (ile != 5) {
        std::cout << "niewlasciwa ilosc argumentow" << std::endl;
        return 1;
    }

    for (int i = 0; i < ile; i++) {

        if (std::string(params[i]) == "-g") infile = std::string(params[i + 1]);
        if (std::string(params[i]) == "-c") outfile = std::string(params[i + 1]);
    }
        
        
    Graph graph = czytaj_graf(infile);

    Cycles cycles = szukaj_cyklow(graph);

    wyswietl_cykle(cycles);
    zapisz_cykle(cycles, outfile);

    return 0;
}