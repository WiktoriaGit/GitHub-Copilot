/**
 * @file matrix.cpp
 * @brief Implementacja konstruktor�w i destruktora klasy matrix.
 */

#include "matrix.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/**
 * @brief Konstruktor domy�lny.
 *
 * Tworzy pust� macierz o rozmiarze 0x0. Wska�nik na dane macierzy jest ustawiony na nullptr.
 */
matrix::matrix() : n(0), data(nullptr) {}

/**
 * @brief Konstruktor parametryczny.
 *
 * Tworzy macierz kwadratow� o zadanym rozmiarze. Alokuje pami�� dla macierzy, ale jej elementy
 * nie s� inicjalizowane.
 *
 * @param size Rozmiar macierzy (n x n).
 */
matrix::matrix(int size) : n(size) {
	data = new int* [n];
	for (int i = 0; i < n; i++) {
		data[i] = new int[n];
	}
}

/**
 * @brief Konstruktor kopiuj�cy.
 *
 * Tworzy now� macierz, kt�ra jest kopi� podanej macierzy. Kopiowane s� wszystkie elementy
 * macierzy �r�d�owej.
 *
 * @param m Macierz, kt�r� nale�y skopiowa�.
 */
matrix::matrix(const matrix& m) : n(m.n) {
	data = new int* [n];
	for (int i = 0; i < n; i++) {
		data[i] = new int[n];
		for (int j = 0; j < n; j++) {
			data[i][j] = m.data[i][j];
		}
	}
}

/**
 * @brief Konstruktor inicjalizuj�cy macierz z tablicy jednowymiarowej.
 *
 * Tworzy macierz kwadratow� o zadanym rozmiarze i inicjalizuje j� warto�ciami z tablicy.
 * Tablica `t` jest interpretowana jako elementy macierzy w kolejno�ci wiersz po wierszu.
 *
 * @param size Rozmiar macierzy (n x n).
 * @param t Tablica jednowymiarowa przechowuj�ca elementy macierzy.
 */
matrix::matrix(int size, int* t) : n(size) {
	data = new int* [n];
	for (int i = 0; i < n; i++) {
		data[i] = new int[n];
		for (int j = 0; j < n; j++) {
			data[i][j] = t[i * n + j];
		}
	}
}

/**
 * @brief Destruktor.
 *
 * Usuwa pami�� zaalokowan� dla macierzy, zwalniaj�c wszystkie wiersze i tablic� wska�nik�w.
 */
matrix::~matrix() {
	for (int i = 0; i < n; i++) {
		delete[] data[i];
	}
	delete[] data;
}


/**
 * @brief Alokuje pami�� dla macierzy o zadanym rozmiarze.
 *
 * Je�li macierz ju� ma zaalokowan� pami��, zostaje ona zwolniona, a nast�pnie
 * alokowana jest nowa pami�� dla macierzy o podanym rozmiarze. Wszystkie elementy
 * s� inicjalizowane na 0.
 *
 * @param size Rozmiar macierzy (n x n).
 * @return Referencja do bie��cej macierzy.
 */
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

/**
 * @brief Wstawia warto�� do okre�lonej pozycji w macierzy.
 *
 * Je�li podane indeksy mieszcz� si� w zakresie macierzy, warto�� zostaje wstawiona.
 * W przeciwnym wypadku funkcja nie wykonuje �adnych dzia�a�.
 *
 * @param x Indeks wiersza.
 * @param y Indeks kolumny.
 * @param wartosc Warto�� do wstawienia.
 * @return Referencja do bie��cej macierzy.
 */
matrix& matrix::wstaw(int x, int y, int wartosc) {
	if (x >= 0 && x < n && y >= 0 && y < n) {
		data[x][y] = wartosc;
	}
	return *this;
}

/**
 * @brief Pobiera warto�� z okre�lonej pozycji w macierzy.
 *
 * Je�li podane indeksy mieszcz� si� w zakresie macierzy, zwraca warto�� w danej pozycji.
 * W przeciwnym wypadku mo�e zwr�ci� nieokre�lon� warto�� (nale�y doda� lepsz� obs�ug� b��d�w).
 *
 * @param x Indeks wiersza.
 * @param y Indeks kolumny.
 * @return Warto�� w pozycji (x, y).
 */
int matrix::pokaz(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) {
		return data[x][y];
	}
	return 0; // Dodatkowa obs�uga dla warto�ci poza zakresem.
}

/**
 * @brief Odwraca macierz wzgl�dem g��wnej przek�tnej (transpozycja).
 *
 * Zmienia macierz w miejscu, zamieniaj�c elementy powy�ej i poni�ej przek�tnej g��wnej.
 *
 * @return Referencja do bie��cej macierzy.
 */
matrix& matrix::odwroc() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			swap(data[i][j], data[j][i]);
		}
	}
	return *this;
}


/**
 * @brief Losowe wype�nianie ca�ej macierzy.
 *
 * Wype�nia macierz losowymi liczbami z zakresu 0-9. Ka�dy element macierzy zostaje nadpisany
 * now� losow� warto�ci�.
 *
 * @return Referencja do bie��cej macierzy.
 */
matrix& matrix::losuj() {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			data[i][j] = rand() % 10;
		}
	}
	return *this;
}

/**
 * @brief Losowe wype�nianie wybranej liczby element�w w macierzy.
 *
 * Wype�nia losowo wskazan� liczb� element�w macierzy (`x`) liczbami z zakresu 0-9.
 * Pozycje element�w s� losowo wybierane, mog� si� powtarza�.
 *
 * @param x Liczba element�w do wype�nienia losowymi warto�ciami.
 * @return Referencja do bie��cej macierzy.
 */
matrix& matrix::losuj(int x) {
	srand(time(NULL));
	for (int i = 0; i < x; i++) {
		int a = rand() % n;
		int b = rand() % n;
		data[a][b] = rand() % 10;
	}
	return *this;
}

/**
 * @brief Wype�nia g��wn� przek�tn� macierzy warto�ciami z tablicy.
 *
 * Wype�nia przek�tn� macierzy warto�ciami podanymi w tablicy `t`. Indeks `t[i]`
 * zostaje przypisany do pozycji `(i, i)` w macierzy.
 *
 * @param t Tablica warto�ci do wstawienia na g��wn� przek�tn� macierzy.
 * @return Referencja do bie��cej macierzy.
 */
matrix& matrix::diagonalna(int* t) {
	for (int i = 0; i < n; i++) {
		data[i][i] = t[i];
	}
	return *this;
}


/**
 * @brief Wype�nia przek�tn� macierzy przesuni�t� o zadan� warto�� k.
 *
 * Wype�nia warto�ciami z tablicy `t` przek�tn� przesuni�t� o warto�� `k`.
 * Je�li przesuni�ta pozycja przekracza rozmiar macierzy, wpisanie warto�ci jest pomijane.
 *
 * @param k Przesuni�cie wzgl�dem g��wnej przek�tnej (mo�e by� ujemne).
 * @param t Tablica warto�ci do wype�nienia przesuni�tej przek�tnej.
 * @return Referencja do bie��cej macierzy.
 */
matrix& matrix::diagonalna_k(int k, int* t) {
	for (int i = 0; i < n; i++) {
		if (i + k >= 0 && i + k < n) {
			data[i][i + k] = t[i];
		}
	}
	return *this;
}

/**
 * @brief Wype�nia okre�lon� kolumn� macierzy warto�ciami z tablicy.
 *
 * Wype�nia kolumn� o indeksie `x` warto�ciami z tablicy `t`.
 * Warto�ci `t[i]` s� przypisane do pozycji `(i, x)` w macierzy.
 *
 * @param x Indeks kolumny do wype�nienia.
 * @param t Tablica warto�ci do wype�nienia kolumny.
 * @return Referencja do bie��cej macierzy.
 */
matrix& matrix::kolumna(int x, int* t) {
	for (int i = 0; i < n; i++) {
		data[i][x] = t[i];
	}
	return *this;
}

/**
 * @brief Wype�nia okre�lony wiersz macierzy warto�ciami z tablicy.
 *
 * Wype�nia wiersz o indeksie `y` warto�ciami z tablicy `t`.
 * Warto�ci `t[i]` s� przypisane do pozycji `(y, i)` w macierzy.
 *
 * @param y Indeks wiersza do wype�nienia.
 * @param t Tablica warto�ci do wype�nienia wiersza.
 * @return Referencja do bie��cej macierzy.
 */
matrix& matrix::wiersz(int y, int* t) {
	for (int i = 0; i < n; i++) {
		data[y][i] = t[i];
	}
	return *this;
}

/**
 * @brief Wy�wietla g��wn� przek�tn� macierzy.
 *
 * Wypisuje na standardowe wyj�cie warto�ci znajduj�ce si� na g��wnej przek�tnej macierzy.
 * Nie modyfikuje macierzy.
 *
 * @return Referencja do bie��cej macierzy.
 */
matrix& matrix::przekatna() {
	for (int i = 0; i < n; i++) {
		cout << data[i][i] << " ";
	}
	cout << endl;
	return *this;
}

/**
 * @brief Wy�wietla elementy macierzy znajduj�ce si� pod g��wn� przek�tn�.
 *
 * Elementy poni�ej g��wnej przek�tnej s� wypisywane na standardowe wyj�cie w odpowiednich wierszach.
 * Funkcja nie modyfikuje macierzy.
 *
 * @return Referencja do bie��cej macierzy.
 */
matrix& matrix::pod_przekatna() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
	return *this;
}

/**
 * @brief Wy�wietla elementy macierzy znajduj�ce si� nad g��wn� przek�tn�.
 *
 * Elementy powy�ej g��wnej przek�tnej s� wypisywane na standardowe wyj�cie w odpowiednich wierszach.
 * Funkcja nie modyfikuje macierzy.
 *
 * @return Referencja do bie��cej macierzy.
 */
matrix& matrix::nad_przekatna() {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
	return *this;
}

/**
 * @brief Wy�wietla macierz w formie szachownicy.
 *
 * Elementy macierzy s� wypisywane zgodnie z wzorem szachownicy:
 * - Elementy, kt�rych suma indeks�w `(i + j)` jest parzysta, s� wypisywane.
 * - Elementy, kt�rych suma indeks�w `(i + j)` jest nieparzysta, s� zast�powane `0`.
 * Funkcja nie modyfikuje macierzy.
 *
 * @return Referencja do bie��cej macierzy.
 */
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

/**
 * @brief Dodawanie dw�ch macierzy.
 *
 * Tworzy now� macierz, kt�ra jest wynikiem dodawania bie��cej macierzy i macierzy `m`.
 * Elementy odpowiadaj�cych sobie pozycji s� sumowane.
 *
 * @param m Macierz, kt�r� nale�y doda� do bie��cej macierzy.
 * @return Nowa macierz, b�d�ca wynikiem operacji dodawania.
 * @throws std::bad_alloc Je�li alokacja pami�ci dla wyniku si� nie powiedzie.
 */
matrix& matrix::operator+(matrix& m) {
	matrix* wynik = new matrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			wynik->data[i][j] = data[i][j] + m.data[i][j];
		}
	}
	return *wynik;
}

/**
 * @brief Mno�enie dw�ch macierzy element po elemencie.
 *
 * Tworzy now� macierz, kt�ra jest wynikiem mno�enia element�w bie��cej macierzy i macierzy `m`.
 * Obie macierze musz� mie� taki sam rozmiar.
 *
 * @param m Macierz, z kt�r� nale�y wykona� mno�enie.
 * @return Nowa macierz, b�d�ca wynikiem operacji mno�enia.
 * @throws std::invalid_argument Je�li macierze maj� r�ne rozmiary.
 * @throws std::bad_alloc Je�li alokacja pami�ci dla wyniku si� nie powiedzie.
 */
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


/**
 * @brief Dodawanie liczby do wszystkich element�w macierzy.
 *
 * Tworzy now� macierz, kt�rej ka�dy element jest sum� odpowiadaj�cego elementu bie��cej macierzy
 * i liczby `a`.
 *
 * @param a Liczba do dodania do ka�dego elementu macierzy.
 * @return Nowa macierz, b�d�ca wynikiem dodawania.
 * @throws std::bad_alloc Je�li alokacja pami�ci dla wyniku si� nie powiedzie.
 */
matrix& matrix::operator+(int a) {
	matrix* wynik = new matrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			wynik->data[i][j] = data[i][j] + a;
		}
	}
	return *wynik;
}

/**
 * @brief Mno�enie wszystkich element�w macierzy przez liczb�.
 *
 * Tworzy now� macierz, kt�rej ka�dy element jest wynikiem pomno�enia odpowiadaj�cego elementu
 * bie��cej macierzy przez liczb� `a`.
 *
 * @param a Liczba, przez kt�r� mno�ymy ka�dy element macierzy.
 * @return Nowa macierz, b�d�ca wynikiem mno�enia.
 * @throws std::bad_alloc Je�li alokacja pami�ci dla wyniku si� nie powiedzie.
 */
matrix& matrix::operator*(int a) {
	matrix* wynik = new matrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			wynik->data[i][j] = data[i][j] * a;
		}
	}
	return *wynik;
}

/**
 * @brief Odejmowanie liczby od wszystkich element�w macierzy.
 *
 * Tworzy now� macierz, kt�rej ka�dy element jest r�nic� odpowiadaj�cego elementu bie��cej macierzy
 * i liczby `a`.
 *
 * @param a Liczba do odj�cia od ka�dego elementu macierzy.
 * @return Nowa macierz, b�d�ca wynikiem odejmowania.
 * @throws std::bad_alloc Je�li alokacja pami�ci dla wyniku si� nie powiedzie.
 */
matrix& matrix::operator-(int a) {
	matrix* wynik = new matrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			wynik->data[i][j] = data[i][j] - a;
		}
	}
	return *wynik;
}

/**
 * @brief Dodawanie liczby do wszystkich element�w macierzy (operator globalny).
 *
 * Tworzy now� macierz, kt�rej ka�dy element jest sum� liczby `a` i odpowiadaj�cego elementu
 * macierzy `m`.
 *
 * @param a Liczba do dodania do ka�dego elementu macierzy.
 * @param m Macierz, do kt�rej element�w dodawana jest liczba `a`.
 * @return Nowa macierz, b�d�ca wynikiem dodawania.
 * @throws std::bad_alloc Je�li alokacja pami�ci dla wyniku si� nie powiedzie.
 */
matrix operator+(int a, matrix& m) {
	matrix* wynik = new matrix(m.n);
	for (int i = 0; i < m.n; i++) {
		for (int j = 0; j < m.n; j++) {
			wynik->data[i][j] = m.data[i][j] + a;
		}
	}
	return *wynik;
}

/**
 * @brief Mno�enie wszystkich element�w macierzy przez liczb� (operator globalny).
 *
 * Tworzy now� macierz, kt�rej ka�dy element jest wynikiem pomno�enia liczby `a`
 * przez odpowiadaj�cy element macierzy `m`.
 *
 * @param a Liczba, przez kt�r� mno�ymy ka�dy element macierzy.
 * @param m Macierz, kt�rej elementy s� mno�one przez liczb� `a`.
 * @return Nowa macierz, b�d�ca wynikiem mno�enia.
 * @throws std::bad_alloc Je�li alokacja pami�ci dla wyniku si� nie powiedzie.
 */
matrix operator*(int a, matrix& m) {
	matrix* wynik = new matrix(m.n);
	for (int i = 0; i < m.n; i++) {
		for (int j = 0; j < m.n; j++) {
			wynik->data[i][j] = m.data[i][j] * a;
		}
	}
	return *wynik;
}

/**
 * @brief Odejmowanie liczby od wszystkich element�w macierzy (operator globalny).
 *
 * Tworzy now� macierz, kt�rej ka�dy element jest r�nic� liczby `a` i odpowiadaj�cego elementu
 * macierzy `m`.
 *
 * @param a Liczba, od kt�rej odejmujemy ka�dy element macierzy.
 * @param m Macierz, kt�rej elementy s� odejmowane od liczby `a`.
 * @return Nowa macierz, b�d�ca wynikiem odejmowania.
 * @throws std::bad_alloc Je�li alokacja pami�ci dla wyniku si� nie powiedzie.
 */
matrix operator-(int a, matrix& m) {
	matrix* wynik = new matrix(m.n);
	for (int i = 0; i < m.n; i++) {
		for (int j = 0; j < m.n; j++) {
			wynik->data[i][j] = m.data[i][j] - a;
		}
	}
	return *wynik;
}

/**
 * @brief Postinkrementacja element�w macierzy.
 *
 * Zwi�ksza wszystkie elementy macierzy o 1. Operacja jest wykonywana w miejscu.
 *
 * @return Referencja do bie��cej macierzy po inkrementacji.
 */
matrix& matrix::operator++(int) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			data[i][j]++;
		}
	}
	return *this;
}

/**
 * @brief Postdekrementacja element�w macierzy.
 *
 * Zmniejsza wszystkie elementy macierzy o 1. Operacja jest wykonywana w miejscu.
 *
 * @return Referencja do bie��cej macierzy po dekrementacji.
 */
matrix& matrix::operator--(int) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			data[i][j]--;
		}
	}
	return *this;
}

/**
 * @brief Dodawanie liczby do wszystkich element�w macierzy (operator `+=`).
 *
 * Zwi�ksza ka�dy element macierzy o warto�� `a`. Operacja jest wykonywana w miejscu.
 *
 * @param a Liczba do dodania do ka�dego elementu macierzy.
 * @return Referencja do bie��cej macierzy po operacji.
 */
matrix& matrix::operator+=(int a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			data[i][j] += a;
		}
	}
	return *this;
}

/**
 * @brief Odejmowanie liczby od wszystkich element�w macierzy (operator `-=`).
 *
 * Zmniejsza ka�dy element macierzy o warto�� `a`. Operacja jest wykonywana w miejscu.
 *
 * @param a Liczba do odj�cia od ka�dego elementu macierzy.
 * @return Referencja do bie��cej macierzy po operacji.
 */
matrix& matrix::operator-=(int a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			data[i][j] -= a;
		}
	}
	return *this;
}

/**
 * @brief Mno�enie wszystkich element�w macierzy przez liczb� (operator `*=`).
 *
 * Mno�y ka�dy element macierzy przez warto�� `a`. Operacja jest wykonywana w miejscu.
 *
 * @param a Liczba, przez kt�r� mno�ymy ka�dy element macierzy.
 * @return Referencja do bie��cej macierzy po operacji.
 */
matrix& matrix::operator*=(int a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			data[i][j] *= a;
		}
	}
	return *this;
}


/**
 * @brief Por�wnuje dwie macierze na r�wno��.
 *
 * Sprawdza, czy macierze maj� ten sam rozmiar i odpowiadaj�ce sobie elementy s� r�wne.
 *
 * @param m Macierz, z kt�r� bie��ca macierz jest por�wnywana.
 * @return true Je�li macierze s� r�wne.
 * @return false Je�li macierze nie s� r�wne.
 */
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

/**
 * @brief Por�wnuje sumy element�w dw�ch macierzy (operator `>`).
 *
 * Oblicza sumy wszystkich element�w obu macierzy i sprawdza, czy suma element�w
 * bie��cej macierzy jest wi�ksza od sumy element�w macierzy `m`.
 *
 * @param m Macierz, z kt�r� por�wnywana jest bie��ca macierz.
 * @return true Je�li suma element�w bie��cej macierzy jest wi�ksza.
 * @return false W przeciwnym przypadku.
 */
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

/**
 * @brief Por�wnuje sumy element�w dw�ch macierzy (operator `<`).
 *
 * Oblicza sumy wszystkich element�w obu macierzy i sprawdza, czy suma element�w
 * bie��cej macierzy jest mniejsza od sumy element�w macierzy `m`.
 *
 * @param m Macierz, z kt�r� por�wnywana jest bie��ca macierz.
 * @return true Je�li suma element�w bie��cej macierzy jest mniejsza.
 * @return false W przeciwnym przypadku.
 */
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

/**
 * @brief Wypisuje macierz na standardowe wyj�cie.
 *
 * Ka�dy element macierzy jest wypisywany w odpowiedniej pozycji (wiersz po wierszu),
 * oddzielony spacjami. Wiersze s� oddzielone znakami nowej linii.
 *
 * @param o Strumie� wyj�ciowy, do kt�rego macierz zostanie wypisana.
 * @param m Macierz do wypisania.
 * @return Referencja do strumienia wyj�ciowego.
 */
ostream& operator<<(ostream& o, const matrix& m) {
	for (int i = 0; i < m.n; i++) {
		for (int j = 0; j < m.n; j++) {
			o << m.data[i][j] << " ";
		}
		o << endl;
	}
	return o;
}
