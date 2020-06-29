/**
* \file interfejs.cpp
* \brief Plik implementacji modułu interfejs.
*/#include <iostream>

#include "struktury.h"

using namespace std;

/** Pokaż menu.
 *
 * Menu użytkownika (funkcja zwraca watość będącą opcją wybraną przez uzytkownika)ków
 * return op
 */
int pokaz_menu()
{
    int op = 0;

    cout << "1 = Reczne wczytanie punktow" << endl;
    cout << "2 = Wczytanie punktow z pliku" << endl;

    do {
        cout << "Opcja [1,2]? ";
        cin >> op;
    }
    while (op != 1 && op != 2);

    return op;
}


/** Ile punktów.
 *
 * Wczytuje od użytkownika ilość punktów, które chce wpisać.
 * \param ile_punktow zmienna przechowująca ilość wczytanych punktów
 * return czy_unikat
 */
int ile_punktow()
{
    int ile;

    cout << "Ile punktow: ";
    cin >> ile;

    return ile;
}

/** Wczytaj punkty od użytkownika.
 *
 * Wczytanie współrzędnych punktów przez uzytkownika (ręcznie)
 * \param Punkt *Tp tablica dynamiczna o polach x,y
 * \param ile zmienna przechowująca ilość punktów jaką chce wpisać użytkownik
 */
void wczytaj_pkt_uzytkownika(Punkt *Tp, int ile)
{
    int i = 0;

    do {
        cout << "Tp[" << i << "].x = ";
        cin >> Tp[i].x;

        cout << "Tp[" << i << "].y = ";
        cin >> Tp[i].y;

        i++;
    }
    while(i < ile);
}





/** Pokaż wczytane punkty.
 *
 * Wyświetlanie wczytanych punktów.
 * \param Punkt *Tp tablica dynamiczna o polach x,y
 * \param ile_punktow zmienna przechowująca ilość wczytanych punktów
 */
void pokaz_wczytane_punkty(Punkt *Tp, int ile_punktow) {

    for (int i = 0; i < ile_punktow; i++) {
        cout << "P[" << (i+1) << "] = { " << Tp[i].x << " ; " << Tp[i].y << " }" << endl;
    }
}

/// wybór metody sprawdzania czy punkty tworza odcinek
int wybor_metody()
{
    int op = 0;

    cout << "1 = Badanie czy punkty leza na jednej prostej" << endl;
    cout << "2 = Badanie dlugosci odcinkow" << endl;

    do {
        cout << "Wybierz metode [1,2]? ";
        cin >> op;
    }
    while (op != 1 && op != 2);

    return op;
}

