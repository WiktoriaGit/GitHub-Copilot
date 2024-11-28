#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

class matrix {
private:
	int n; //rozmiar macierzy (n x n)
	int** data; //wskaznik na dane macierzy
public:
	matrix(); //konstruktor
	matrix(int size); //konstruktor z parametrem
	matrix(const matrix& m); //konstruktor kopiujacy
	matrix(int size, int* t); //konstruktor z tablica
	~matrix(); //destruktor
	
	//metody
	matrix& alokuj(int size); //alokacja pamieci
	matrix& wstaw(int x, int y, int wartosc); //wstawianie wartosci
	int pokaz(int x, int y); //pobieranie wartosci
	matrix& odwroc(); //odracanie macierzy
	matrix& randomize(); //losowanie wypełnianie macierzy
	matrix& randomize(int x); //losowanie wypełnianie okreslonej liczby elementow
	matrix& diagonal(int* t); // wypełnienie przekatnej
	matrix& diagonal_k(int k, int* t); // wypełnienie przekątnej przesuniętej o k
	matrix& column(int x, int* t); // wypełnienie kolumny
	matrix& row(int y, int* t); // wypełnienie wiersza
	matrix& mainDiagonal(); // pobieranie głównej przekątnej
	matrix& belowDiagonal(); // elementy pod przekątną
	matrix& aboveDiagonal(); // elementy nad przekątną
	matrix& checkerboard(); // szachownica

	//operatory
	matrix& operator+(matrix& m);
	matrix& operator*(matrix& m);
	matrix& operator+(int a);
	matrix& operator*(int a);
	matrix& operator-(int a);
	friend matrix operator+(int a, matrix& m);
	friend matrix operator*(int a, matrix& m);
	friend matrix operator-(int a, matrix& m);
	matrix& operator++(int);
	matrix& operator--(int);
	matrix& operator+=(int a);
	matrix& operator-=(int a);
	matrix& operator*=(int a);
	bool operator==(const matrix& m) const;
	bool operator>(const matrix& m) const;
	bool operator<(const matrix& m) const;

	// Wypisywanie
	friend ostream& operator<<(ostream& o, const matrix& m);
};
#endif // !MATRIX_H
