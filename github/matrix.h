#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

/**
 * @class matrix
 * @brief Klasa reprezentuj¹ca macierz kwadratow¹ i wykonuj¹ca ró¿ne operacje na niej.
 */
class matrix {
private:
    int n; ///< Rozmiar macierzy (n x n)
    int** data; ///< WskaŸnik na dane macierzy

public:
    /**
     * @brief Konstruktor domyœlny.
     */
    matrix();

    /**
     * @brief Konstruktor parametryczny.
     * @param size Rozmiar macierzy.
     */
    matrix(int size);

    /**
     * @brief Konstruktor kopiuj¹cy.
     * @param m Macierz do skopiowania.
     */
    matrix(const matrix& m);

    /**
     * @brief Konstruktor z tablic¹.
     * @param size Rozmiar macierzy.
     * @param t WskaŸnik na tablicê.
     */
    matrix(int size, int* t);

    /**
     * @brief Destruktor.
     */
    ~matrix();

    /**
     * @brief Alokuje pamiêæ dla macierzy.
     * @param size Rozmiar macierzy.
     * @return Referencja do macierzy.
     */
    matrix& alokuj(int size);

    /**
     * @brief Wstawia wartoœæ do macierzy.
     * @param x Indeks wiersza.
     * @param y Indeks kolumny.
     * @param wartosc Wartoœæ do wstawienia.
     * @return Referencja do macierzy.
     */
    matrix& wstaw(int x, int y, int wartosc);

    /**
     * @brief Pobiera wartoœæ z macierzy.
     * @param x Indeks wiersza.
     * @param y Indeks kolumny.
     * @return Wartoœæ na okreœlonej pozycji.
     */
    int pokaz(int x, int y);

    /**
     * @brief Transponuje macierz.
     * @return Referencja do macierzy.
     */
    matrix& odwroc();

    /**
     * @brief Wype³nia macierz losowymi wartoœciami.
     * @return Referencja do macierzy.
     */
    matrix& losuj();

    /**
     * @brief Wype³nia okreœlon¹ liczbê elementów w macierzy losowymi wartoœciami.
     * @param x Liczba elementów do wype³nienia.
     * @return Referencja do macierzy.
     */
    matrix& losuj(int x);

    /**
     * @brief Wype³nia g³ówn¹ przek¹tn¹ macierzy wartoœciami z tablicy.
     * @param t WskaŸnik na tablicê.
     * @return Referencja do macierzy.
     */
    matrix& diagonalna(int* t);

    /**
     * @brief Wype³nia przek¹tn¹ przesuniêt¹ o k wartoœciami z tablicy.
     * @param k Przesuniêcie przek¹tnej.
     * @param t WskaŸnik na tablicê.
     * @return Referencja do macierzy.
     */
    matrix& diagonalna_k(int k, int* t);

    /**
     * @brief Wype³nia kolumnê macierzy wartoœciami z tablicy.
     * @param x Indeks kolumny.
     * @param t WskaŸnik na tablicê.
     * @return Referencja do macierzy.
     */
    matrix& kolumna(int x, int* t);

    /**
     * @brief Wype³nia wiersz macierzy wartoœciami z tablicy.
     * @param y Indeks wiersza.
     * @param t WskaŸnik na tablicê.
     * @return Referencja do macierzy.
     */
    matrix& wiersz(int y, int* t);

    /**
     * @brief Wypisuje g³ówn¹ przek¹tn¹ macierzy.
     * @return Referencja do macierzy.
     */
    matrix& przekatna();

    /**
     * @brief Wypisuje elementy pod g³ówn¹ przek¹tn¹ macierzy.
     * @return Referencja do macierzy.
     */
    matrix& pod_przekatna();

    /**
     * @brief Wypisuje elementy nad g³ówn¹ przek¹tn¹ macierzy.
     * @return Referencja do macierzy.
     */
    matrix& nad_przekatna();

    /**
     * @brief Wypisuje macierz w uk³adzie szachownicy.
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
     * @brief Mno¿y dwie macierze.
     * @param m Macierz do mno¿enia.
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
     * @brief Mno¿y macierz przez skalar.
     * @param a Skalar do mno¿enia.
     * @return Referencja do wynikowej macierzy.
     */
    matrix& operator*(int a);

    /**
     * @brief Odejmuje skalar od macierzy.
     * @param a Skalar do odjêcia.
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
     * @brief Mno¿y macierz przez skalar.
     * @param a Skalar do mno¿enia.
     * @param m Macierz do mno¿enia.
     * @return Wynikowa macierz.
     */
    friend matrix operator*(int a, matrix& m);

    /**
     * @brief Odejmuje skalar od macierzy.
     * @param a Skalar do odjêcia.
     * @param m Macierz do odjêcia.
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
     * @param a Skalar do odjêcia.
     * @return Referencja do macierzy.
     */
    matrix& operator-=(int a);

    /**
     * @brief Mno¿y macierz przez skalar.
     * @param a Skalar do mno¿enia.
     * @return Referencja do macierzy.
     */
    matrix& operator*=(int a);

    /**
     * @brief Porównuje dwie macierze pod k¹tem równoœci.
     * @param m Macierz do porównania.
     * @return True, jeœli macierze s¹ równe, w przeciwnym razie false.
     */
    bool operator==(const matrix& m) const;

    /**
     * @brief Porównuje, czy ta macierz jest wiêksza od innej macierzy.
     * @param m Macierz do porównania.
     * @return True, jeœli ta macierz jest wiêksza, w przeciwnym razie false.
     */
    bool operator>(const matrix& m) const;

    /**
     * @brief Porównuje, czy ta macierz jest mniejsza od innej macierzy.
     * @param m Macierz do porównania.
     * @return True, jeœli ta macierz jest mniejsza, w przeciwnym razie false.
     */
    bool operator<(const matrix& m) const;

    /**
     * @brief Wypisuje macierz do strumienia wyjœciowego.
     * @param o Strumieñ wyjœciowy.
     * @param m Macierz do wypisania.
     * @return Strumieñ wyjœciowy.
     */
    friend ostream& operator<<(ostream& o, const matrix& m);
};

#endif // !MATRIX_H
