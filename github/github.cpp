/**
 * @file github.cpp
 * @brief Plik zawiera funkcję main, która testuje różne operacje na klasie matrix.
 */

#include "matrix.h"
#include <iostream>

using namespace std;

/**
 * @brief Funkcja główna programu.
 *
 * Testuje różne funkcje i operacje na klasie matrix, takie jak tworzenie macierzy,
 * wstawianie wartości, operacje matematyczne i inne.
 *
 * @return int Zwraca 0, jeśli program zakończył się poprawnie.
 */
int main() {
    /**
     * @brief Test 1: Tworzenie i wyświetlenie macierzy.
     *
     * Tworzy macierz o zadanym rozmiarze, losowo wypełnia ją elementami
     * i wyświetla wynik.
     */
    cout << "------------Test 1: Tworzenie macierzy i losowe wypelnienie------------" << endl;
    matrix m1(3);
    m1.losuj();
    cout << "Macierz:" << endl;
    cout << m1 << endl;

    /**
     * @brief Test 2: Wstawianie i pobieranie wartości.
     *
     * Wstawia wartości do określonych pozycji w macierzy, wyświetla wynik,
     * a następnie pobiera te wartości i wyświetla je.
     */
    cout << "---------------Test 2: Wstawianie i pobieranie wartosci-----------------" << endl;
    m1.wstaw(0, 0, 5).wstaw(1, 1, 10).wstaw(2, 2, 15);
    cout << "Macierz po wstawieniu wartosci:" << endl;
    cout << m1 << endl;
    cout << "Wartosc na (0,0): " << m1.pokaz(0, 0) << endl;
    cout << "Wartosc na (1,1): " << m1.pokaz(1, 1) << endl << endl;

    /**
     * @brief Test 3: Odwracanie macierzy.
     *
     * Wyświetla macierz przed i po odwróceniu wierszy i kolumn.
     */
    cout << "---------------Test 3: Odwracanie macierzy------------------------" << endl;
    cout << "Macierz przed odwroceniem:" << endl;
    cout << m1 << endl;
    m1.odwroc();
    cout << "Macierz po odwroceniu:" << endl;
    cout << m1 << endl;

    /**
     * @brief Test 4: Wypełnianie przekątnej.
     *
     * Wypełnia przekątną macierzy zadanymi wartościami i wyświetla wynik.
     */
    cout << "----------------------Test 4: Wypelnianie przekatnej------------------" << endl;
    int diag[] = { 1, 2, 3 };
    m1.diagonalna(diag);
    cout << "Macierz z przekatna [1, 2, 3]:" << endl;
    cout << m1 << endl;

    /**
     * @brief Test 5: Wypełnianie kolumny i wiersza.
     *
     * Wypełnia określoną kolumnę i wiersz zadanymi wartościami, a następnie wyświetla wynik.
     */
    cout << "-----------------Test 5: Wypelnianie kolumny i wiersza-------------------" << endl;
    int col[] = { 7, 8, 9 };
    int row[] = { 4, 5, 6 };
    m1.kolumna(1, col).wiersz(2, row);
    cout << "Macierz po wypelnieniu kolumny i wiersza:" << endl;
    cout << m1 << endl;

    /**
     * @brief Test 6: Wyświetlanie przekątnej, nad i pod przekątną.
     *
     * Wyświetla przekątną, elementy nad przekątną i pod przekątną macierzy.
     */
    cout << "---------------Test 6: Wyswietlanie przekatnej, nad i pod przekatna---------------" << endl;
    cout << "Macierz m1:" << endl;
    cout << m1 << endl;
    cout << "Przekatna macierzy: ";
    m1.przekatna();
    cout << "\nElementy pod przekatna macierzy:";
    m1.pod_przekatna();
    cout << "\nElementy nad przekatna macierzy:" << endl;
    m1.nad_przekatna();

    /**
     * @brief Test 7: Operacje arytmetyczne na macierzach.
     *
     * Wykonuje operacje dodawania i mnożenia macierzy oraz operacje dodawania i mnożenia macierzy przez skalary.
     */
    cout << "-----------------Test 7: Operacje arytmetyczne na macierzach---------------------" << endl;
    matrix m2(3);
    m2.losuj();
    cout << "Macierz m1:" << endl;
    cout << m1 << endl;

    cout << "Macierz m2:" << endl;
    cout << m2 << endl;

    matrix m3 = m1 + m2;
    cout << "Suma m1 + m2:" << endl;
    cout << m3 << endl;

    matrix m4 = m1 * m2;
    cout << "Iloczyn m1 * m2:" << endl;
    cout << m4 << endl;

    matrix m5 = m1 + 5;
    cout << "Dodanie 5 do kazdego elementu m1:" << endl;
    cout << m5 << endl;

    matrix m6 = 3 * m1;
    cout << "Pomnozenie kazdego elementu m1 przez 3:" << endl;
    cout << m6 << endl;

    /**
     * @brief Test 8: Operatory porównania.
     *
     * Sprawdza równość, większość i mniejszość między macierzami.
     */
    cout << "------------------------Test 8: Operatory porownania------------------------" << endl;
    cout << "Macierz m1:" << endl;
    cout << m1 << endl;

    cout << "Macierz m2:" << endl;
    cout << m2 << endl;

    cout << "Czy m1 == m2? " << (m1 == m2 ? "Tak" : "Nie") << endl;
    cout << "Czy m1 > m2? " << (m1 > m2 ? "Tak" : "Nie") << endl;
    cout << "Czy m1 < m2? " << (m1 < m2 ? "Tak" : "Nie") << endl << endl;

    /**
     * @brief Test 9: Operatory inkrementacji i dekrementacji.
     *
     * Testuje operator zwiększania (++) i zmniejszania (--) na macierzy.
     */
    cout << "----------------Test 9: Operatory inkrementacji i dekrementacji-------------------" << endl;
    m1++;
    cout << "Macierz m1 po operatorze ++:" << endl;
    cout << m1 << endl;

    m1--;
    cout << "Macierz m1 po operatorze --:" << endl;
    m1--;
    cout << m1 << endl;

    /**
     * @brief Test 10: Szachownica.
     *
     * Wyświetla macierz w formie szachownicy, gdzie pola białe mają wartość 0.
     */
    cout << "----------------Test 10: Szachownica----------------------------" << endl;
    m1.szachownica();

    return 0;
}
