/** @file */

#include <iostream>
#include "funkcje.h"

int main()
{
    vec_ark pary = czytaj_pary("grafy.txt");

    wypisz_pary(pary);

    return 0;
}