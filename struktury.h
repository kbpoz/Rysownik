/**
* \file struktury.h
* \brief Plik nagłówkowy ze zdefiniowanymi strukturami.
*/
#ifndef STRUKTURY
#define STRUKTURY

/** \brief Definicja elementu tablicy dynamicznej.
*
* Struktura opisująca pojedynczy punkt.
*/
    struct Punkt{
        /// współrzędna x.
        int x;
        /// współrzędna y.
        int y;
    };

    /** \brief Definicja struktury punktu odcinka.
     *
     * Struktura opisująca element listy będącej odcinkiem składającym się z punktów leżących na wspólnej prostej.
     */
    struct Punkt_Odcinka {
        /// struktura przechowująca współrzędne punktu należącego do odcinka.
        Punkt p;
        /// wskaźnik na kolejny element odcinka.
        Punkt_Odcinka* Next;
    };

    /** \brief Definicja struktury listy odcinków.
     *
     *  Struktura opisująca element listy będącej zbiorem odcinków spełniających założenia projektu.
     */
    struct Odcinek {
        /// wskaźnik na głowę budowanego odcinka.
        Punkt_Odcinka* Head;
        /// wskaźnik na kolejny element listy odcinków.
        Odcinek* Next;
    };

#endif // STRUKTURY

