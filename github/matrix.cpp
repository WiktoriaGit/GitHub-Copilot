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
	if (data) {
		for (int i = 0; i < n; i++) {
			delete[] data[i];
		}
		delete[] data;
	}
	n = size;
	data = new int* [n];
	for (int i = 0; i < n; i++) {
		data[i] = new int[n]();
	}
	return *this;
}

//wstawianie wartosci
matrix& matrix::wstaw(int x, int y, int wartosc) {
	if (x >= 0 && x < n && y >= 0 && y < n){
		data[x][y] = wartosc;
}
return *this;
	}

//pobieranie wartosci
int matrix::pokaz(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) {
		return data[x][y];
	}
}

//odracanie macierzy
	matrix& matrix::odwroc() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				swap(data[i][j], data[j][i]);
			}
		}
		return *this;
	}

	//losowanie wartoœci do macierzy
	matrix& matrix::losuj() {
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				data[i][j] = rand() % 10;
			}
		}
		return *this;
	}

	//losowanie wartoœci do macierzy
	matrix& matrix::losuj(int x) {
		srand(time(NULL));
		for (int i = 0; i < x; i++) {
			int a = rand() % n;
			int b = rand() % n;
			data[a][b] = rand() % 10;
		}
		return *this;
	}

	//wype³nienie przek¹tnej
	matrix& matrix::diagonalna(int* t) {
		for (int i = 0; i < n; i++) {
			data[i][i] = t[i];
		}
		return *this;
	}

	//wype³nienie przek¹tnej przesuniêtej o k
	matrix& matrix::diagonalna_k(int k, int* t) {
		for (int i = 0; i < n; i++) {
			if (i + k >= 0 && i + k < n) {
				data[i][i + k] = t[i];
			}
		}
		return *this;
	}

	//wype³nienie kolumny
	matrix& matrix::kolumna(int x, int* t) {
		for (int i = 0; i < n; i++) {
			data[i][x] = t[i];
		}
		return *this;
	}

	//wype³nienie wiersza
	matrix& matrix::wiersz(int y, int* t) {
		for (int i = 0; i < n; i++) {
			data[y][i] = t[i];
		}
		return *this;
	}

	//pobieranie g³ównej przek¹tnej
	matrix& matrix::przekatna() {
		for (int i = 0; i < n; i++) {
			cout << data[i][i] << " ";
		}
		cout << endl;
		return *this;
	}

	//elementy pod przek¹tna
	matrix& matrix::pod_przekatna() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
		return *this;
	}

	//elementy nad przek¹tna
	matrix& matrix::nad_przekatna() {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
		return *this;
	}

	//szachownica
	matrix& matrix::szachownica() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((i + j) % 2 == 0) {
					cout << data[i][j] << " ";
				}
				else {
					cout << "0 ";
				}
			}
			cout << endl;
		}
		return *this;
	}
	//operatorzy
	//dodawanie macierzy
	matrix& matrix::operator+(matrix& m) {
		matrix* wynik = new matrix(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				wynik->data[i][j] = data[i][j] + m.data[i][j];
			}
		}
		return *wynik;
	}

    //mno¿enie macierzy
	matrix& matrix::operator*(matrix& m) {
		if (n != m.n) {
			cerr << "Matrix dimensions must match for multiplication!" << endl;
			throw invalid_argument("Matrix dimensions mismatch");
		}

		matrix* result = new matrix(n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				result->data[i][j] = data[i][j] * m.data[i][j];
			}
		}

		return *result;
	}

	//dodawanie liczby
	matrix& matrix::operator+(int a) {
		matrix* wynik = new matrix(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				wynik->data[i][j] = data[i][j] + a;
			}
		}
		return *wynik;
	}

	//mno¿enie przez liczbê
	matrix& matrix::operator*(int a) {
		matrix* wynik = new matrix(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				wynik->data[i][j] = data[i][j] * a;
			}
		}
		return *wynik;
	}

	//odejmowanie liczby
	matrix& matrix::operator-(int a) {
		matrix* wynik = new matrix(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				wynik->data[i][j] = data[i][j] - a;
			}
		}
		return *wynik;
	}

	//dodawanie liczby
	matrix operator+(int a, matrix& m) {
		matrix* wynik = new matrix(m.n);
		for (int i = 0; i < m.n; i++) {
			for (int j = 0; j < m.n; j++) {
				wynik->data[i][j] = m.data[i][j] + a;
			}
		}
		return *wynik;
	}
		
	//mno¿enie przez liczbê
	matrix operator*(int a, matrix& m) {
		matrix* wynik = new matrix(m.n);
		for (int i = 0; i < m.n; i++) {
			for (int j = 0; j < m.n; j++) {
				wynik->data[i][j] = m.data[i][j] * a;
			}
		}
		return *wynik;
	}

	//odejmowanie liczby
	matrix operator-(int a, matrix& m) {
		matrix* wynik = new matrix(m.n);
		for (int i = 0; i < m.n; i++) {
			for (int j = 0; j < m.n; j++) {
				wynik->data[i][j] = m.data[i][j] - a;
			}
		}
		return *wynik;
	}

	//inkrementacja
	matrix& matrix::operator++(int) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				data[i][j]++;
			}
		}
		return *this;
	}

	//dekrementacja
	matrix& matrix::operator--(int) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				data[i][j]--;
			}
		}
		return *this;
	}

	//dodawanie liczby
	matrix& matrix::operator+=(int a) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				data[i][j] += a;
			}
		}
		return *this;
	}

	//odejmowanie liczby
	matrix& matrix::operator-=(int a) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				data[i][j] -= a;
			}
		}
		return *this;
	}

	//mno¿enie przez liczbê
	matrix& matrix::operator*=(int a) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				data[i][j] *= a;
			}
		}
		return *this;
	}
    
	//porównywanie macierzy
	bool matrix::operator==(const matrix& m) const {
		if (n != m.n) {
			return false;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (data[i][j] != m.data[i][j]) {
					return false;
				}
			}
		}
		return true;
	}

	//porównywanie macierzy2
	bool matrix::operator>(const matrix& m) const {
		int suma1 = 0;
		int suma2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				suma1 += data[i][j];
				suma2 += m.data[i][j];
			}
		}
		return suma1 > suma2;
	}

	//porównywanie macierzy3
	bool matrix::operator<(const matrix& m) const {
		int suma1 = 0;
		int suma2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				suma1 += data[i][j];
				suma2 += m.data[i][j];
			}
		}
		return suma1 < suma2;
	}

	//wypisywanie
	ostream& operator<<(ostream& o, const matrix& m) {
		for (int i = 0; i < m.n; i++) {
			for (int j = 0; j < m.n; j++) {
				o << m.data[i][j] << " ";
			}
			o << endl;
		}
		return o;
	}

