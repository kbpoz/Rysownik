/**
* \file sortowanie.cpp
* \brief Plik implementacji modułu sortowanie.
*/
#include <iostream>

#include "struktury.h"

using namespace std;

/** Sortowanie według X.
 *
 * Sortowanie bąbelkowe - sortujemy tablicę z punktami według współrzędnej X.
 * \param Punkt tab[] tablica punktów
 * \param int n  ilość punktów
 */
void sortowanie(Punkt tab[], int n)
{

    Punkt temp;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n-i-1; j++)
            if(tab[j].x > tab[j+1].x)
            {
                temp.x = tab[j].x;
                temp.y = tab[j].y;

                tab[j].x = tab[j+1].x;
                tab[j].y = tab[j+1].y;

                tab[j+1].x = temp.x;
                tab[j+1].y = temp.y;
            }
}


