/**
* \file pliki.cpp
* \brief Plik implementacji modułu pliki.
*/
#include <iostream>
#include <fstream>

#include "struktury.h"
#include "pliki.h"

using namespace std;

/** \brief Wczytaj punkty z pliku.
 *
 * Funkcja wczytująca punkty z pliku (funkcja zwraca liczbę odczytanych punktów).
 * \param Punkt *Tp tablica dynamiczna o polach x,y
 * \param *nazwa_pliku nazwa pliku który ma zostać odczytany
 */
void wczytaj_pkt_z_pliku(Punkt *Tp, const char *nazwa_pliku)
{

    int wsp;            /// zmienna pomocznicza - na nią będziemy czytać kolejne współrzędne z pliku
    int ile_punktow;    /// ile punktów zapisano w pliku (wartość z pierwszego wiersza pliku)
    int i = 0;          /// ile danych odczytano z pliku?

    fstream plik;
    plik.open(nazwa_pliku, ios::in);

    if (plik.good() == false) {

        cout << "Nie udalo sie otworzyc pliku!" << endl;
        exit(0);

    } else {

        while (!plik.eof())
        {
            if (i == 0) {
                plik >> ile_punktow;
            } else {
                plik >> wsp;

                if (i % 2 != 0)
                    Tp[(i-1)/2].x = wsp;
                else
                    Tp[(i-1)/2].y = wsp;
            }

            i++;
        }

        plik.close();
    }

}
/** \brief Ile punktów w pliku.
 *
 * Funkcja wczytująca liczbę punktów zapisanych w pliku (wartość z pierwszego wiersza pliku).
 * \param const char *nazwa_pliku nazwa pliku który ma zostać odczytany
 * return ile_punktow
 */
int ile_pkt_w_pliku(const char *nazwa_pliku)
{

    int ile_punktow;    /// ile punktów zapisano w pliku
    fstream plik;

    plik.open(nazwa_pliku, ios::in);

    if (plik.good() == false) {

        cout << "Nie udalo sie otworzyc pliku!" << endl;
        exit(0);

    } else {

        plik >> ile_punktow;
        plik.close();
    }

    return ile_punktow;
}


/** \brief Zapisz odcinki do pliku.
 *
 * Zapisanie prawidłowych odcinków do pliku wynikowego
 * \param const char *nazwa_pliku nazwa pliku który ma zostać odczytany
 * \param const Odcinek *head wskaźnik na głowę listy odcinków
 */
void zapisz_odcinki_do_pliku(const Odcinek *head, const char *nazwa_pliku)
{
    Punkt_Odcinka* temp_pkt;

    fstream plik;

    plik.open(nazwa_pliku, ios::out);

    if (plik.good() == false) {

        cout << "Nie udalo sie otworzyc pliku!" << endl;
        exit(0);

    } else {

        /// dla każdego odcinka
        while (head != NULL) {

            temp_pkt = head->Head;      /// head bieżącego odcinka
            /// dla każdego punktu bieżącego odcinka
            while (temp_pkt != NULL) {
                plik << "(" << temp_pkt->p.x << " " << temp_pkt->p.y << ") ";   /// zapisuję współrzędne punktu do pliku
                temp_pkt = temp_pkt->Next;      /// ustawiam wskaźnik na kolejny punkt w odcinku
            }
            plik << endl;
            head = head->Next;      /// ustawiam wskaźnik na kolejny odcinek z listy
        }

        plik.close();
    }
}

