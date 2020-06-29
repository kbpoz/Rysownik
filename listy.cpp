/**
* \file listy.cpp
* \brief Plik implementacji modułu listy.
*/
#include <iostream>

#include "struktury.h"
#include "listy.h"

using namespace std;

/** \brief Dodaj punkt odcinka.
 *
 * Funkcja dodająca element do listy będącej zbiorem punktów leżących na wspólnej prostej.
 * \param Punkt_Odcinka *&head wskaźnik na głowę odcinka
 * \param Punkt pkt
 */
void dodaj_pkt_odcinka(Punkt_Odcinka *&head, Punkt pkt)
{
    Punkt_Odcinka *temp = new Punkt_Odcinka;

    temp->p.x = pkt.x;
    temp->p.y = pkt.y;
    temp->Next = head;
    head = temp;
}

/** \brief Pokaż odcinek.
 *
 * Funkcja drukująca na ekranie odcinek (współrzędnych punktu) - pomocnicza.
 * \param Punkt_Odcinka *head wskaźnik na głowę odcinka
 */
void pokaz_odcinek( Punkt_Odcinka *head)
{
    while (head != NULL)
    {
        cout << "(" << head->p.x << " " << head->p.y << ") ";
        head = head->Next;
    }
}

/** \brief Usuń punkt odcinka.
 *
 * Funkcja usuwająca element z listy będącej zbiorem punktów leżących na wspólnej prostej.
 * \param Punkt_Odcinka *&head wskaźnik na głowę odcinka
 */
void usun_pkt_odcinka(Punkt_Odcinka *&head)
{
    Punkt_Odcinka *p = new Punkt_Odcinka;

    p = head;

    if(p != NULL) {
        head = p->Next;
        delete p;
    }
}

/** \brief Dodaj odcinek.
 *
 * Funkcja dodająca odcinek do listy odcinków spełniających warunki projektu.
 * \param Odcinek *&head wskaźnik na głowę listy odcinków.
 * \param Punkt_Odcinka *&head_odc wskaźnik na głowę odcinka
 */
void dodaj_odcinek(Odcinek *&head, Punkt_Odcinka *&head_odc)
{
    Odcinek *temp = new Odcinek;

    temp->Head = head_odc;
    temp->Next = head;
    head = temp;
}

/** \brief Pokaż odcinki.
 * Funkcja drukująca na ekranie wszystkich znalezionych odcinków.
 * \param const Odcinek *head wskaźnik na głowę listy odcinków.
 */
void pokaz_odcinki( Odcinek *head)
{
    while (head != NULL)
    {
        pokaz_odcinek(head->Head);
        cout << endl;
        head = head->Next;
    }
}

