/**
* \file pliki.h
* \brief Plik nagłówkowy modułu pliki.
*/
#ifndef PLIKI
#define PLIKI

    void wczytaj_pkt_z_pliku(Punkt *Tp, const char *nazwa_pliku);
    int ile_pkt_w_pliku(const char *nazwa_pliku);
    void zapisz_odcinki_do_pliku(const Odcinek *head, const char *nazwa_pliku);

#endif // PLIKI

