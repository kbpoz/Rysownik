/**
* \file sprawdzenia.h
* \brief Plik nagłówkowy modułu sprawdzenia.
*/
#ifndef SPRAWDZENIA
#define SPRAWDZENIA

    /// Sprawdzamy czy badany odcinek nie zawiera się już w tych odłożonych na liście odcinków
    /// (przeglądamy wszystkie odcinki na liście odcinków, chyba że wcześniej okaże się, że badany odcinek zawiera się jednak w jakimś)
    /// Argumenty:
    ///      h_lst_odc - wskaźnik do głowy listy prawidłowych odcinków
    ///      h_lst_pkt - wskaznik do głowy listy punktów badanego odcinka
    bool sprawdz_czy_odcinek_unikalny(Odcinek *h_lst_odc, Punkt_Odcinka *h_lst_pkt);

#endif // SPRAWDZENIA

