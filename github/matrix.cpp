/**
 * @file matrix.cpp
 * @brief Implementacja konstruktorów i destruktora klasy matrix.
 */

#include "matrix.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/**
 * @brief Konstruktor domyœlny.
 *
 * Tworzy pust¹ macierz o rozmiarze 0x0. WskaŸnik na dane macierzy jest ustawiony na nullptr.
 */
matrix::matrix() : n(0), data(nullptr) {}

/**
 * @brief Konstruktor parametryczny.
 *
 * Tworzy macierz kwadratow¹ o zadanym rozmiarze. Alokuje pamiêæ dla macierzy, ale jej elementy
 * nie s¹ inicjalizowane.
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
 * @brief Konstruktor kopiuj¹cy.
 *
 * Tworzy now¹ macierz, która jest kopi¹ podanej macierzy. Kopiowane s¹ wszystkie elementy
 * macierzy Ÿród³owej.
 *
 * @param m Macierz, któr¹ nale¿y skopiowaæ.
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
 * @brief Konstruktor inicjalizuj¹cy macierz z tablicy jednowymiarowej.
 *
 * Tworzy macierz kwadratow¹ o zadanym rozmiarze i inicjalizuje j¹ wartoœciami z tablicy.
 * Tablica `t` jest interpretowana jako elementy macierzy w kolejnoœci wiersz po wierszu.
 *
 * @param size Rozmiar macierzy (n x n).
 * @param t Tablica jednowymiarowa przechowuj¹ca elementy macierzy.
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
 * Usuwa pamiêæ zaalokowan¹ dla macierzy, zwalniaj¹c wszystkie wiersze i tablicê wskaŸników.
 */
matrix::~matrix() {
	for (int i = 0; i < n; i++) {
		delete[] data[i];
	}
	delete[] data;
}


/**
 * @brief Alokuje pamiêæ dla macierzy o zadanym rozmiarze.
 *
 * Jeœli macierz ju¿ ma zaalokowan¹ pamiêæ, zostaje ona zwolniona, a nastêpnie
 * alokowana jest nowa pamiêæ dla macierzy o podanym rozmiarze. Wszystkie elementy
 * s¹ inicjalizowane na 0.
 *
 * @param size Rozmiar macierzy (n x n).
 * @return Referencja do bie¿¹cej macierzy.
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
 * @brief Wstawia wartoœæ do okreœlonej pozycji w macierzy.
 *
 * Jeœli podane indeksy mieszcz¹ siê w zakresie macierzy, wartoœæ zostaje wstawiona.
 * W przeciwnym wypadku funkcja nie wykonuje ¿adnych dzia³añ.
 *
 * @param x Indeks wiersza.
 * @param y Indeks kolumny.
 * @param wartosc Wartoœæ do wstawienia.
 * @return Referencja do bie¿¹cej macierzy.
 */
matrix& matrix::wstaw(int x, int y, int wartosc) {
	if (x >= 0 && x < n && y >= 0 && y < n) {
		data[x][y] = wartosc;
	}
	return *this;
}

/**
 * @brief Pobiera wartoœæ z okreœlonej pozycji w macierzy.
 *
 * Jeœli podane indeksy mieszcz¹ siê w zakresie macierzy, zwraca wartoœæ w danej pozycji.
 * W przeciwnym wypadku mo¿e zwróciæ nieokreœlon¹ wartoœæ (nale¿y dodaæ lepsz¹ obs³ugê b³êdów).
 *
 * @param x Indeks wiersza.
 * @param y Indeks kolumny.
 * @return Wartoœæ w pozycji (x, y).
 */
int matrix::pokaz(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) {
		return data[x][y];
	}
	return 0; // Dodatkowa obs³uga dla wartoœci poza zakresem.
}

/**
 * @brief Odwraca macierz wzglêdem g³ównej przek¹tnej (transpozycja).
 *
 * Zmienia macierz w miejscu, zamieniaj¹c elementy powy¿ej i poni¿ej przek¹tnej g³ównej.
 *
 * @return Referencja do bie¿¹cej macierzy.
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
 * @brief Losowe wype³nianie ca³ej macierzy.
 *
 * Wype³nia macierz losowymi liczbami z zakresu 0-9. Ka¿dy element macierzy zostaje nadpisany
 * now¹ losow¹ wartoœci¹.
 *
 * @return Referencja do bie¿¹cej macierzy.
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
 * @brief Losowe wype³nianie wybranej liczby elementów w macierzy.
 *
 * Wype³nia losowo wskazan¹ liczbê elementów macierzy (`x`) liczbami z zakresu 0-9.
 * Pozycje elementów s¹ losowo wybierane, mog¹ siê powtarzaæ.
 *
 * @param x Liczba elementów do wype³nienia losowymi wartoœciami.
 * @return Referencja do bie¿¹cej macierzy.
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
 * @brief Wype³nia g³ówn¹ przek¹tn¹ macierzy wartoœciami z tablicy.
 *
 * Wype³nia przek¹tn¹ macierzy wartoœciami podanymi w tablicy `t`. Indeks `t[i]`
 * zostaje przypisany do pozycji `(i, i)` w macierzy.
 *
 * @param t Tablica wartoœci do wstawienia na g³ówn¹ przek¹tn¹ macierzy.
 * @return Referencja do bie¿¹cej macierzy.
 */
matrix& matrix::diagonalna(int* t) {
	for (int i = 0; i < n; i++) {
		data[i][i] = t[i];
	}
	return *this;
}


/**
 * @brief Wype³nia przek¹tn¹ macierzy przesuniêt¹ o zadan¹ wartoœæ k.
 *
 * Wype³nia wartoœciami z tablicy `t` przek¹tn¹ przesuniêt¹ o wartoœæ `k`.
 * Jeœli przesuniêta pozycja przekracza rozmiar macierzy, wpisanie wartoœci jest pomijane.
 *
 * @param k Przesuniêcie wzglêdem g³ównej przek¹tnej (mo¿e byæ ujemne).
 * @param t Tablica wartoœci do wype³nienia przesuniêtej przek¹tnej.
 * @return Referencja do bie¿¹cej macierzy.
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
 * @brief Wype³nia okreœlon¹ kolumnê macierzy wartoœciami z tablicy.
 *
 * Wype³nia kolumnê o indeksie `x` wartoœciami z tablicy `t`.
 * Wartoœci `t[i]` s¹ przypisane do pozycji `(i, x)` w macierzy.
 *
 * @param x Indeks kolumny do wype³nienia.
 * @param t Tablica wartoœci do wype³nienia kolumny.
 * @return Referencja do bie¿¹cej macierzy.
 */
matrix& matrix::kolumna(int x, int* t) {
	for (int i = 0; i < n; i++) {
		data[i][x] = t[i];
	}
	return *this;
}

/**
 * @brief Wype³nia okreœlony wiersz macierzy wartoœciami z tablicy.
 *
 * Wype³nia wiersz o indeksie `y` wartoœciami z tablicy `t`.
 * Wartoœci `t[i]` s¹ przypisane do pozycji `(y, i)` w macierzy.
 *
 * @param y Indeks wiersza do wype³nienia.
 * @param t Tablica wartoœci do wype³nienia wiersza.
 * @return Referencja do bie¿¹cej macierzy.
 */
matrix& matrix::wiersz(int y, int* t) {
	for (int i = 0; i < n; i++) {
		data[y][i] = t[i];
	}
	return *this;
}

/**
 * @brief Wyœwietla g³ówn¹ przek¹tn¹ macierzy.
 *
 * Wypisuje na standardowe wyjœcie wartoœci znajduj¹ce siê na g³ównej przek¹tnej macierzy.
 * Nie modyfikuje macierzy.
 *
 * @return Referencja do bie¿¹cej macierzy.
 */
matrix& matrix::przekatna() {
	for (int i = 0; i < n; i++) {
		cout << data[i][i] << " ";
	}
	cout << endl;
	return *this;
}

/**
 * @brief Wyœwietla elementy macierzy znajduj¹ce siê pod g³ówn¹ przek¹tn¹.
 *
 * Elementy poni¿ej g³ównej przek¹tnej s¹ wypisywane na standardowe wyjœcie w odpowiednich wierszach.
 * Funkcja nie modyfikuje macierzy.
 *
 * @return Referencja do bie¿¹cej macierzy.
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
 * @brief Wyœwietla elementy macierzy znajduj¹ce siê nad g³ówn¹ przek¹tn¹.
 *
 * Elementy powy¿ej g³ównej przek¹tnej s¹ wypisywane na standardowe wyjœcie w odpowiednich wierszach.
 * Funkcja nie modyfikuje macierzy.
 *
 * @return Referencja do bie¿¹cej macierzy.
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
 * @brief Wyœwietla macierz w formie szachownicy.
 *
 * Elementy macierzy s¹ wypisywane zgodnie z wzorem szachownicy:
 * - Elementy, których suma indeksów `(i + j)` jest parzysta, s¹ wypisywane.
 * - Elementy, których suma indeksów `(i + j)` jest nieparzysta, s¹ zastêpowane `0`.
 * Funkcja nie modyfikuje macierzy.
 *
 * @return Referencja do bie¿¹cej macierzy.
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
 * @brief Dodawanie dwóch macierzy.
 *
 * Tworzy now¹ macierz, która jest wynikiem dodawania bie¿¹cej macierzy i macierzy `m`.
 * Elementy odpowiadaj¹cych sobie pozycji s¹ sumowane.
 *
 * @param m Macierz, któr¹ nale¿y dodaæ do bie¿¹cej macierzy.
 * @return Nowa macierz, bêd¹ca wynikiem operacji dodawania.
 * @throws std::bad_alloc Jeœli alokacja pamiêci dla wyniku siê nie powiedzie.
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
 * @brief Mno¿enie dwóch macierzy element po elemencie.
 *
 * Tworzy now¹ macierz, która jest wynikiem mno¿enia elementów bie¿¹cej macierzy i macierzy `m`.
 * Obie macierze musz¹ mieæ taki sam rozmiar.
 *
 * @param m Macierz, z któr¹ nale¿y wykonaæ mno¿enie.
 * @return Nowa macierz, bêd¹ca wynikiem operacji mno¿enia.
 * @throws std::invalid_argument Jeœli macierze maj¹ ró¿ne rozmiary.
 * @throws std::bad_alloc Jeœli alokacja pamiêci dla wyniku siê nie powiedzie.
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
 * @brief Dodawanie liczby do wszystkich elementów macierzy.
 *
 * Tworzy now¹ macierz, której ka¿dy element jest sum¹ odpowiadaj¹cego elementu bie¿¹cej macierzy
 * i liczby `a`.
 *
 * @param a Liczba do dodania do ka¿dego elementu macierzy.
 * @return Nowa macierz, bêd¹ca wynikiem dodawania.
 * @throws std::bad_alloc Jeœli alokacja pamiêci dla wyniku siê nie powiedzie.
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
 * @brief Mno¿enie wszystkich elementów macierzy przez liczbê.
 *
 * Tworzy now¹ macierz, której ka¿dy element jest wynikiem pomno¿enia odpowiadaj¹cego elementu
 * bie¿¹cej macierzy przez liczbê `a`.
 *
 * @param a Liczba, przez któr¹ mno¿ymy ka¿dy element macierzy.
 * @return Nowa macierz, bêd¹ca wynikiem mno¿enia.
 * @throws std::bad_alloc Jeœli alokacja pamiêci dla wyniku siê nie powiedzie.
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
 * @brief Odejmowanie liczby od wszystkich elementów macierzy.
 *
 * Tworzy now¹ macierz, której ka¿dy element jest ró¿nic¹ odpowiadaj¹cego elementu bie¿¹cej macierzy
 * i liczby `a`.
 *
 * @param a Liczba do odjêcia od ka¿dego elementu macierzy.
 * @return Nowa macierz, bêd¹ca wynikiem odejmowania.
 * @throws std::bad_alloc Jeœli alokacja pamiêci dla wyniku siê nie powiedzie.
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
 * @brief Dodawanie liczby do wszystkich elementów macierzy (operator globalny).
 *
 * Tworzy now¹ macierz, której ka¿dy element jest sum¹ liczby `a` i odpowiadaj¹cego elementu
 * macierzy `m`.
 *
 * @param a Liczba do dodania do ka¿dego elementu macierzy.
 * @param m Macierz, do której elementów dodawana jest liczba `a`.
 * @return Nowa macierz, bêd¹ca wynikiem dodawania.
 * @throws std::bad_alloc Jeœli alokacja pamiêci dla wyniku siê nie powiedzie.
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
 * @brief Mno¿enie wszystkich elementów macierzy przez liczbê (operator globalny).
 *
 * Tworzy now¹ macierz, której ka¿dy element jest wynikiem pomno¿enia liczby `a`
 * przez odpowiadaj¹cy element macierzy `m`.
 *
 * @param a Liczba, przez któr¹ mno¿ymy ka¿dy element macierzy.
 * @param m Macierz, której elementy s¹ mno¿one przez liczbê `a`.
 * @return Nowa macierz, bêd¹ca wynikiem mno¿enia.
 * @throws std::bad_alloc Jeœli alokacja pamiêci dla wyniku siê nie powiedzie.
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
 * @brief Odejmowanie liczby od wszystkich elementów macierzy (operator globalny).
 *
 * Tworzy now¹ macierz, której ka¿dy element jest ró¿nic¹ liczby `a` i odpowiadaj¹cego elementu
 * macierzy `m`.
 *
 * @param a Liczba, od której odejmujemy ka¿dy element macierzy.
 * @param m Macierz, której elementy s¹ odejmowane od liczby `a`.
 * @return Nowa macierz, bêd¹ca wynikiem odejmowania.
 * @throws std::bad_alloc Jeœli alokacja pamiêci dla wyniku siê nie powiedzie.
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
 * @brief Postinkrementacja elementów macierzy.
 *
 * Zwiêksza wszystkie elementy macierzy o 1. Operacja jest wykonywana w miejscu.
 *
 * @return Referencja do bie¿¹cej macierzy po inkrementacji.
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
 * @brief Postdekrementacja elementów macierzy.
 *
 * Zmniejsza wszystkie elementy macierzy o 1. Operacja jest wykonywana w miejscu.
 *
 * @return Referencja do bie¿¹cej macierzy po dekrementacji.
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
 * @brief Dodawanie liczby do wszystkich elementów macierzy (operator `+=`).
 *
 * Zwiêksza ka¿dy element macierzy o wartoœæ `a`. Operacja jest wykonywana w miejscu.
 *
 * @param a Liczba do dodania do ka¿dego elementu macierzy.
 * @return Referencja do bie¿¹cej macierzy po operacji.
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
 * @brief Odejmowanie liczby od wszystkich elementów macierzy (operator `-=`).
 *
 * Zmniejsza ka¿dy element macierzy o wartoœæ `a`. Operacja jest wykonywana w miejscu.
 *
 * @param a Liczba do odjêcia od ka¿dego elementu macierzy.
 * @return Referencja do bie¿¹cej macierzy po operacji.
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
 * @brief Mno¿enie wszystkich elementów macierzy przez liczbê (operator `*=`).
 *
 * Mno¿y ka¿dy element macierzy przez wartoœæ `a`. Operacja jest wykonywana w miejscu.
 *
 * @param a Liczba, przez któr¹ mno¿ymy ka¿dy element macierzy.
 * @return Referencja do bie¿¹cej macierzy po operacji.
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
 * @brief Porównuje dwie macierze na równoœæ.
 *
 * Sprawdza, czy macierze maj¹ ten sam rozmiar i odpowiadaj¹ce sobie elementy s¹ równe.
 *
 * @param m Macierz, z któr¹ bie¿¹ca macierz jest porównywana.
 * @return true Jeœli macierze s¹ równe.
 * @return false Jeœli macierze nie s¹ równe.
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
 * @brief Porównuje sumy elementów dwóch macierzy (operator `>`).
 *
 * Oblicza sumy wszystkich elementów obu macierzy i sprawdza, czy suma elementów
 * bie¿¹cej macierzy jest wiêksza od sumy elementów macierzy `m`.
 *
 * @param m Macierz, z któr¹ porównywana jest bie¿¹ca macierz.
 * @return true Jeœli suma elementów bie¿¹cej macierzy jest wiêksza.
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
 * @brief Porównuje sumy elementów dwóch macierzy (operator `<`).
 *
 * Oblicza sumy wszystkich elementów obu macierzy i sprawdza, czy suma elementów
 * bie¿¹cej macierzy jest mniejsza od sumy elementów macierzy `m`.
 *
 * @param m Macierz, z któr¹ porównywana jest bie¿¹ca macierz.
 * @return true Jeœli suma elementów bie¿¹cej macierzy jest mniejsza.
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
 * @brief Wypisuje macierz na standardowe wyjœcie.
 *
 * Ka¿dy element macierzy jest wypisywany w odpowiedniej pozycji (wiersz po wierszu),
 * oddzielony spacjami. Wiersze s¹ oddzielone znakami nowej linii.
 *
 * @param o Strumieñ wyjœciowy, do którego macierz zostanie wypisana.
 * @param m Macierz do wypisania.
 * @return Referencja do strumienia wyjœciowego.
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
