/**
* \file interfejs.h
* \brief Plik nagłówkowy modułu interfejs.
*/
#ifndef INTERFEJS
#define INTERFEJS

    /// Wczytanie współrzędnych punktów przez uzytkownika (ręcznie)
    void wczytaj_pkt_uzytkownika(Punkt *Tp, int ile);

    /// wybór metody sprawdzania czy punkty tworza odcinek
    int wybor_metody();

    /// Menu użytkownika (funkcja zwraca watość będącą opcją wybraną przez uzytkownika)
    int pokaz_menu();

    /// Użytkownik podaje ile punktów będzie wczytywał
    int ile_punktow();

    /// Wyświetlanie wczytanych punktów
    void pokaz_wczytane_punkty(Punkt *Tp, int ile_punktow);

#endif // INTERFEJS

