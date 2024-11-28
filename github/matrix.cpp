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

