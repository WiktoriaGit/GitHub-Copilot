#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

/**
 * @class matrix
 * @brief Klasa reprezentuj�ca macierz kwadratow� i wykonuj�ca r�ne operacje na niej.
 */
class matrix {
private:
    int n; ///< Rozmiar macierzy (n x n)
    int** data; ///< Wska�nik na dane macierzy

public:
    /**
     * @brief Konstruktor domy�lny.
     */
    matrix();

    /**
     * @brief Konstruktor parametryczny.
     * @param size Rozmiar macierzy.
     */
    matrix(int size);

    /**
     * @brief Konstruktor kopiuj�cy.
     * @param m Macierz do skopiowania.
     */
    matrix(const matrix& m);

    /**
     * @brief Konstruktor z tablic�.
     * @param size Rozmiar macierzy.
     * @param t Wska�nik na tablic�.
     */
    matrix(int size, int* t);

    /**
     * @brief Destruktor.
     */
    ~matrix();

    /**
     * @brief Alokuje pami�� dla macierzy.
     * @param size Rozmiar macierzy.
     * @return Referencja do macierzy.
     */
    matrix& alokuj(int size);

    /**
     * @brief Wstawia warto�� do macierzy.
     * @param x Indeks wiersza.
     * @param y Indeks kolumny.
     * @param wartosc Warto�� do wstawienia.
     * @return Referencja do macierzy.
     */
    matrix& wstaw(int x, int y, int wartosc);

    /**
     * @brief Pobiera warto�� z macierzy.
     * @param x Indeks wiersza.
     * @param y Indeks kolumny.
     * @return Warto�� na okre�lonej pozycji.
     */
    int pokaz(int x, int y);

    /**
     * @brief Transponuje macierz.
     * @return Referencja do macierzy.
     */
    matrix& odwroc();

    /**
     * @brief Wype�nia macierz losowymi warto�ciami.
     * @return Referencja do macierzy.
     */
    matrix& losuj();

    /**
     * @brief Wype�nia okre�lon� liczb� element�w w macierzy losowymi warto�ciami.
     * @param x Liczba element�w do wype�nienia.
     * @return Referencja do macierzy.
     */
    matrix& losuj(int x);

    /**
     * @brief Wype�nia g��wn� przek�tn� macierzy warto�ciami z tablicy.
     * @param t Wska�nik na tablic�.
     * @return Referencja do macierzy.
     */
    matrix& diagonalna(int* t);

    /**
     * @brief Wype�nia przek�tn� przesuni�t� o k warto�ciami z tablicy.
     * @param k Przesuni�cie przek�tnej.
     * @param t Wska�nik na tablic�.
     * @return Referencja do macierzy.
     */
    matrix& diagonalna_k(int k, int* t);

    /**
     * @brief Wype�nia kolumn� macierzy warto�ciami z tablicy.
     * @param x Indeks kolumny.
     * @param t Wska�nik na tablic�.
     * @return Referencja do macierzy.
     */
    matrix& kolumna(int x, int* t);

    /**
     * @brief Wype�nia wiersz macierzy warto�ciami z tablicy.
     * @param y Indeks wiersza.
     * @param t Wska�nik na tablic�.
     * @return Referencja do macierzy.
     */
    matrix& wiersz(int y, int* t);

    /**
     * @brief Wypisuje g��wn� przek�tn� macierzy.
     * @return Referencja do macierzy.
     */
    matrix& przekatna();

    /**
     * @brief Wypisuje elementy pod g��wn� przek�tn� macierzy.
     * @return Referencja do macierzy.
     */
    matrix& pod_przekatna();

    /**
     * @brief Wypisuje elementy nad g��wn� przek�tn� macierzy.
     * @return Referencja do macierzy.
     */
    matrix& nad_przekatna();

    /**
     * @brief Wypisuje macierz w uk�adzie szachownicy.
     * @return Referencja do macierzy.
     */
    matrix& szachownica();

    /**
     * @brief Dodaje dwie macierze.
     * @param m Macierz do dodania.
     * @return Referencja do wynikowej macierzy.
     */
    matrix& operator+(matrix& m);

    /**
     * @brief Mno�y dwie macierze.
     * @param m Macierz do mno�enia.
     * @return Referencja do wynikowej macierzy.
     */
    matrix& operator*(matrix& m);

    /**
     * @brief Dodaje skalar do macierzy.
     * @param a Skalar do dodania.
     * @return Referencja do wynikowej macierzy.
     */
    matrix& operator+(int a);

    /**
     * @brief Mno�y macierz przez skalar.
     * @param a Skalar do mno�enia.
     * @return Referencja do wynikowej macierzy.
     */
    matrix& operator*(int a);

    /**
     * @brief Odejmuje skalar od macierzy.
     * @param a Skalar do odj�cia.
     * @return Referencja do wynikowej macierzy.
     */
    matrix& operator-(int a);

    /**
     * @brief Dodaje skalar do macierzy.
     * @param a Skalar do dodania.
     * @param m Macierz do dodania.
     * @return Wynikowa macierz.
     */
    friend matrix operator+(int a, matrix& m);

    /**
     * @brief Mno�y macierz przez skalar.
     * @param a Skalar do mno�enia.
     * @param m Macierz do mno�enia.
     * @return Wynikowa macierz.
     */
    friend matrix operator*(int a, matrix& m);

    /**
     * @brief Odejmuje skalar od macierzy.
     * @param a Skalar do odj�cia.
     * @param m Macierz do odj�cia.
     * @return Wynikowa macierz.
     */
    friend matrix operator-(int a, matrix& m);

    /**
     * @brief Inkrementuje wszystkie elementy macierzy o 1.
     * @return Referencja do macierzy.
     */
    matrix& operator++(int);

    /**
     * @brief Dekrementuje wszystkie elementy macierzy o 1.
     * @return Referencja do macierzy.
     */
    matrix& operator--(int);

    /**
     * @brief Dodaje skalar do macierzy.
     * @param a Skalar do dodania.
     * @return Referencja do macierzy.
     */
    matrix& operator+=(int a);

    /**
     * @brief Odejmuje skalar od macierzy.
     * @param a Skalar do odj�cia.
     * @return Referencja do macierzy.
     */
    matrix& operator-=(int a);

    /**
     * @brief Mno�y macierz przez skalar.
     * @param a Skalar do mno�enia.
     * @return Referencja do macierzy.
     */
    matrix& operator*=(int a);

    /**
     * @brief Por�wnuje dwie macierze pod k�tem r�wno�ci.
     * @param m Macierz do por�wnania.
     * @return True, je�li macierze s� r�wne, w przeciwnym razie false.
     */
    bool operator==(const matrix& m) const;

    /**
     * @brief Por�wnuje, czy ta macierz jest wi�ksza od innej macierzy.
     * @param m Macierz do por�wnania.
     * @return True, je�li ta macierz jest wi�ksza, w przeciwnym razie false.
     */
    bool operator>(const matrix& m) const;

    /**
     * @brief Por�wnuje, czy ta macierz jest mniejsza od innej macierzy.
     * @param m Macierz do por�wnania.
     * @return True, je�li ta macierz jest mniejsza, w przeciwnym razie false.
     */
    bool operator<(const matrix& m) const;

    /**
     * @brief Wypisuje macierz do strumienia wyj�ciowego.
     * @param o Strumie� wyj�ciowy.
     * @param m Macierz do wypisania.
     * @return Strumie� wyj�ciowy.
     */
    friend ostream& operator<<(ostream& o, const matrix& m);
};

#endif // !MATRIX_H
