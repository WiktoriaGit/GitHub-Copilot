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
	matrix& wstaw(int i, int j, int value); //wstawianie wartosci
	int getValue(int i, int j); //pobieranie wartosci
	matrix& transpose(); //transponowanie macierzy
	matrix& randomize(); //losowanie wype³nianie macierzy
	matrix& randomize(int x); //losowanie wype³nianie okreslonej liczby elementow
	matrix& diagonal(int* t); // wype³nienie przekatnej
	matrix& diagonal_k(int k, int* t); // wype³nienie przek¹tnej przesuniêtej o k
	matrix& column(int x, int* t); // wype³nienie kolumny
	matrix& row(int y, int* t); // wype³nienie wiersza
	matrix& mainDiagonal(); // pobieranie g³ównej przek¹tnej
	matrix& belowDiagonal(); // elementy pod przek¹tn¹
	matrix& aboveDiagonal(); // elementy nad przek¹tn¹
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
