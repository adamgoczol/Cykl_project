/** @file */

#include "funkcje.h"


bool porownaj(std::vector<int> v1, std::vector<int> v2)
{
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    return v1 == v2;
}


Graph czytaj_graf(const std::string& nazwa_pliku) {

    Graph graph;
    std::ifstream in(nazwa_pliku);
    
    if (in) {
        std::string strzalki;
        std::string linia;
        int start, stop;
        while (std::getline(in, linia, ',')) {
            std::stringstream ss(linia);

            ss >> start >> strzalki >> stop;
            graph[start].push_back(stop);
        }
        in.close();
    }
    else {
        std::cout << "problem przy otwieraniu pliku" << std::endl;
    }
    return graph;

}


void wypisz_graf(const Graph& graph) {
    for (const auto& el : graph) {
        for (const auto& st : el.second) {
            std::cout << el.first << " -> " << st << std::endl;
        }

    }
}
 

bool czy_nowy_cykl(const Cycles& cycles, const Cycle& cycle) {
    for (const auto& el : cycles) {
        if (porownaj(el, cycle)) return 0;
    }
    return 1;
}


Cycles szukaj_cyklow(const Graph& graph) {

    Cycles cycles;
    Cycle starts;
    

    for (const auto& el : graph) {
        std::set<int> visited;
        //std::cout << el.first << '/' << graph.size() << std::endl;
        podszukanie(graph, el.first, el.first, cycles, starts, visited, 0);
        
    }
    return cycles;
}


void podszukanie(const Graph& graph, const int starting, int node,
    Cycles& cycles, Cycle cycle, std::set<int> visited, int depth) {



    if (graph.count(node) == 0 or graph.at(node).empty()) return;
    if (node == starting and depth != 0) {
        if (czy_nowy_cykl(cycles, cycle)) {
            cycles.push_back(cycle);
        }

        return;
    }
    if (visited.count(node) != 0) {
        return;
    }
    cycle.push_back(node);
    visited.insert(node);
    for (const auto& el : graph.at(node)) {
        
        
        depth++;
        podszukanie(graph, starting, el, cycles, cycle, visited, depth);
    }
}


void wyswietl_cykle(const Cycles& cycles) {
    if (cycles.empty()) {
        std::cout << "W podanym grafie skierowanym nie wystepuja cykle" << std::endl;
        return;
    }
    std::cout << "Cykle znalezione w podanym grafie skierowanym:" << std::endl;
    for (const auto& el : cycles) {
        for (const auto& sub : el) {
            std::cout << sub << " -> ";
        }
        std::cout << el[0] << std::endl;
    }
}


void zapisz_cykle(const Cycles& cycles, const std::string filename) {
    
    std::ofstream out(filename);

    if (out) {
        if (cycles.empty()) {
            std::cout << "W podanym grafie skierowanym nie wystepuja cykle" << std::endl;
            return;
        }
        for (const auto& el : cycles) {
            for (const auto& sub : el) {
                out << sub << " -> ";
            }
            out << el[0] << std::endl;
        }
    }

    
}