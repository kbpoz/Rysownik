/**
* \file listy.h
* \brief Plik nagłówkowy modułu listy.
*/
#ifndef LISTY
#define LISTY

    void dodaj_pkt_odcinka(Punkt_Odcinka *&head, Punkt pkt);
    void pokaz_odcinek( Punkt_Odcinka* head);
    void usun_pkt_odcinka(Punkt_Odcinka* &head);
    void dodaj_odcinek(Odcinek *&head, Punkt_Odcinka *&head_odc);
    void pokaz_odcinki( Odcinek *head);


#endif // LISTY

