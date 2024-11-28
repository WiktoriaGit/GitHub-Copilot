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
	matrix& randomize(); //losowanie wype�nianie macierzy
	matrix& randomize(int x); //losowanie wype�nianie okreslonej liczby elementow
	matrix& diagonal(int* t); // wype�nienie przekatnej
	matrix& diagonal_k(int k, int* t); // wype�nienie przek�tnej przesuni�tej o k
	matrix& column(int x, int* t); // wype�nienie kolumny
	matrix& row(int y, int* t); // wype�nienie wiersza
	matrix& mainDiagonal(); // pobieranie g��wnej przek�tnej
	matrix& belowDiagonal(); // elementy pod przek�tn�
	matrix& aboveDiagonal(); // elementy nad przek�tn�
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
