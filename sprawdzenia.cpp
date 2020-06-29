/**
* \file sprawdzenia.cpp
* \brief Plik implementacji modułu sprawdzenia.
*/
#include <iostream>

#include "struktury.h"

using namespace std;

 /** Czy odcinek jest unikalny.
 *
 * Sprawdzam czy badany odcinek nie zawiera się już w tych odłożonych na liście odcinków.(przeglądamy wszystkie odcinki na liście odcinków, chyba że wcześniej okaże się, że badany odcinek zawiera się jednak w jakimś).
 * \param  Odcinek *h_lst_odc  wskaźnik na głowę listy prawidłowych odcinków
 * \param  Punkt_Odcinka *h_lst_pkt  wskaznik na głowę listy punktów badanego odcinka
 * return czy_unikat
 */
bool sprawdz_czy_odcinek_unikalny(Odcinek *h_lst_odc, Punkt_Odcinka *h_lst_pkt) {

    bool czy_unikat = true;                     /// pomocnicza: true - badany odcinek jest unikalny, false - badany odcinek zawiera się już w jakimś odcinku

    Punkt_Odcinka *temp_h_lst_pkt = h_lst_pkt;
    Odcinek *temp_h_lst_odc = h_lst_odc;

    /// dla każdego odcinka znajdującego się na liście prawidłowych odcinków wykonuj badanie
    while (temp_h_lst_odc != NULL && czy_unikat == true) {

        if (temp_h_lst_pkt->p.x == temp_h_lst_odc->Head->p.x &&
            temp_h_lst_pkt->p.y == temp_h_lst_odc->Head->p.y &&
            temp_h_lst_pkt->Next->p.x == temp_h_lst_odc->Head->Next->p.x &&
            temp_h_lst_pkt->Next->p.y == temp_h_lst_odc->Head->Next->p.y)

            czy_unikat = false;

        temp_h_lst_odc = temp_h_lst_odc->Next;  /// ustawiam na następny odcinek z listy prawidłowych odcinków

    }

    return czy_unikat;
}
