/**
* \mainpage
* \par Rysownik
* Program wyszukujący w zbiorze punktów odcinki co najmniej 3-punktowe.
* \author Jakub Poźniak grupa 16
* \date 2015.05.11
* \version 1.0
* \par Kontakt:
* \a kuba_pozniak@wp.pl
*/

#include <iostream>
#include <fstream>
#include <cmath>

#include "struktury.h"
#include "pliki.h"
#include "listy.h"
#include "interfejs.h"
#include "sortowanie.h"
#include "sprawdzenia.h"

using namespace std;

int pierwiastek(int x1, int y1, int x2, int y2);    /// pierwiastek z sumy kwadratów wspł. punktów odcinka


int main()
{   int metoda;                             /// Metoda badania punktów: 1 - pkty leżące na wspólnej prostej, 2 - długości odcinków
    int opcja;                              /// Pobieranie punktow: 1 - wczytanie ręczne, 2 - z pliku
    int ile_pkt;                            /// ile punktów wczytujemy do programu
    Punkt *Tpkt;                            /// tablica wszystkich punktów (wczytanych z pliku lub podanych przez użytkownika)
    Punkt_Odcinka *head_lst_pkt = NULL;     /// głowa listy z elementami będącymi punktami budowanego odcinka
    Odcinek *head_lst_odc = NULL;           /// głowa listy odcinków
    bool czy_unikat;                        /// pomocnicza do określenia czy badany odcinek jest unikalny (true), czy zawiera się już w jakimś wczesniejszym (false)

    string nazwa_pliku;

    /// Menu pozwalające wybrać metodę
    metoda = wybor_metody();
    /// Wybieram sposób wypełniania tablicy punktami
    opcja = pokaz_menu();

    /// Okreslam ile punktów zostanie wczytanych do tablicy
    if (opcja == 1) {

        ile_pkt = ile_punktow();

    } else {

        cout << "Podaj nazwe pliku z punktami: ";
        cin >> nazwa_pliku;

        /// wczytuje z pliku
        ile_pkt = ile_pkt_w_pliku(nazwa_pliku.c_str());
    }

    /// deklaruje tablicę
    Tpkt = new Punkt [ile_pkt];

    /// wczytuje punkty do tablicy
    if (opcja == 1) {
        wczytaj_pkt_uzytkownika(Tpkt, ile_pkt);
    } else {

        /// wczytuje z pliku
        wczytaj_pkt_z_pliku(Tpkt, nazwa_pliku.c_str());
    }

    /// pokazuje wszystkie wczytane punkty
    pokaz_wczytane_punkty(Tpkt, ile_pkt);
    cout << endl;


    /// Sortowanie punktów w tablicy ze względu na wsp. X
    sortowanie(Tpkt, ile_pkt);


    pokaz_wczytane_punkty(Tpkt, ile_pkt);
    cout << endl;


    /// Wyszukiwanie punktów leżących na tej samej prostej

    /// utwórz listę odcinków

    int ile;        /// zmienna przechowująca liczbę punktów, z których składa się odcinek

    for(int i = 0; i < ile_pkt - 2; i++) {
        for(int j = i + 1; j < ile_pkt - 1; j++) {

            /// 1. buduję odcinek składający się z dwóch zadanych punktów i pozostałych pasujących (leżących na wspólnej prostej)
            /// Tworzę tymczasową listę przechowującą pasujące punkty
            ile = 2;

            dodaj_pkt_odcinka(head_lst_pkt, Tpkt[i]);   /// dodaję pierwszy punkt do listy przechowującej punkty tworzące odcinek
            dodaj_pkt_odcinka(head_lst_pkt, Tpkt[j]);   /// dodaje drugi punkt do listy przechowującej punkty tworzące odcinek

            for(int k = j + 1; k < ile_pkt; k++){
                if (metoda == 1) {
                    /// Sprawdzam czy badany k-ty punkt leży na prostej
                    if ((Tpkt[k].y-Tpkt[i].y)*(Tpkt[j].x-Tpkt[i].x)-(Tpkt[k].x-Tpkt[i].x)*(Tpkt[j].y-Tpkt[i].y) == 0)
                    {
                        dodaj_pkt_odcinka(head_lst_pkt, Tpkt[k]);   /// jeżeli punkt leży na prostej, dodajemy go do listy przechowującej punkty tworzące odcinek
                        ile += 1;
                    }
                }
                else
                {
                                        /// Sprawdzamy długości odcinków
                                        if ( pierwiastek(Tpkt[i].x, Tpkt[i].y, Tpkt[j].x, Tpkt[j].y) + pierwiastek(Tpkt[j].x, Tpkt[j].y, Tpkt[k].x, Tpkt[k].y)== pierwiastek(Tpkt[i].x, Tpkt[i].y, Tpkt[k].x, Tpkt[k].y) )
                                        {
                                            dodaj_pkt_odcinka(head_lst_pkt, Tpkt[k]);   /// jezeli punkt spełnia powyższy warunek, dodajemy go do listy przechowującej punkty tworzące odcinek
                                            ile += 1;
                                        }
                }
            }


            /// 2. jeżeli odcinek składa się co najmniej z 3 punktów, sprawdzamy, czy nie występuje już liście znalezionych odcinków
            /// i czy nie zawiera się on w żadnym innym, wcześniej znalezionym odcinku
            if (ile >= 3) {

                /// Jeżeli to pierwszy poprawny odcinek, dodaj go do listy (bez sprawdzania)
                if (head_lst_odc == NULL) {

                    dodaj_odcinek(head_lst_odc, head_lst_pkt);     /// dodaję odcinek do listy odcinków
                    head_lst_pkt = NULL;                           /// czyszczę head_lst_pkt na potrzeby nowego analizowanego odcinka

                }
                else {  /// Jeżeli to kolejny odcinek, sprawdzam, czy na liście nie występuje już odcinek, w którym zawiera się ten odcinek

                    /// sprawdzam, czy aktualnie badany odcinek jest unikalny
                    czy_unikat = sprawdz_czy_odcinek_unikalny(head_lst_odc, head_lst_pkt);

                    /// jeżeli okazało się, że badany odcinek jest unikalny
                    if (czy_unikat == true) {
                        dodaj_odcinek(head_lst_odc, head_lst_pkt);      /// dodaję ten odcinek do listy prawidłowych odcinków
                        head_lst_pkt = NULL;                            /// zeruję wskaźnik head'a kolejnego odcinka, który będzie analizowany
                    }
                }

            }
            else {
                /// jeżeli okaże się, że badany sprawdzany odcinek składa się z mniejszej liczby punktów niż 3,
                /// usuwam z pamięci wszystkie jego punkty
                while(head_lst_pkt != NULL)
                    usun_pkt_odcinka(head_lst_pkt);

            }

        }
    }

    /// Zapisanie wyniku do pliku
    zapisz_odcinki_do_pliku(head_lst_odc, "C:\\Users\\Kuba\\Desktop\\odcinki.txt");
    pokaz_odcinki(head_lst_odc);


    delete [] Tpkt;
    return 0;
}

/// Pierwiastek z sumy kwadratów wspł. punktów odcinka - pomocnicza dla skrócenia zapisu w if-ie
int pierwiastek(int x1, int y1, int x2, int y2)
{
    const int dokladnosc = 1000; ///przesuniecie przecinka o 3 miejsca w prawo

    /// floor odcięcie części ułamkowej (zaokrąglenie w dół)
    /// (int) argument - argument staje się typu int
    return (int)floor(sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)) * dokladnosc);
}



