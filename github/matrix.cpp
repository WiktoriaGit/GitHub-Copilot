#include "matrix.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//Konstruktor domyslny
matrix::matrix() : n(0), data(nullptr) {}

//konstruktor parametryczny
matrix::matrix(int size) : n(size) {
	data = new int* [n];
	for (int i = 0; i < n; i++) {
		data[i] = new int[n];
	}
}

//konstruktor kopiujacy
matrix::matrix(const matrix& m) : n(m.n) {
	data = new int* [n];
	for (int i = 0; i < n; i++) {
		data[i] = new int[n];
		for (int j = 0; j < n; j++) {
			data[i][j] = m.data[i][j];
		}
	}
}

//konstruktor z tablica
matrix::matrix(int size, int* t) : n(size) {
	data = new int* [n];
	for (int i = 0; i < n; i++) {
		data[i] = new int[n];
		for (int j = 0; j < n; j++) {
			data[i][j] = t[i * n + j];
		}
	}
}

//destruktor
matrix::~matrix() {
	for (int i = 0; i < n; i++) {
		delete[] data[i];
	}
	delete[] data;
}

//alokacja pamieci
matrix& matrix::alokuj(int size) {
	n = size;
	data = new int* [n];
	for (int i = 0; i < n; i++) {
		data[i] = new int[n];
	}
	return *this;
}



