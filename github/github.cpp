// github.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
#include "matrix.h"
#include <iostream>
using namespace std;

    int main() {
        // Test 1: Tworzenie i wyświetlenie macierzy
        cout << "------------Test 1: Tworzenie macierzy i losowe wypelnienie------------" << endl;
        matrix m1(3);
        m1.losuj();
        cout << "Macierz:" << endl;
        cout << m1 << endl;

        // Test 2: Wstawianie i pobieranie wartości
        cout << "---------------Test 2: Wstawianie i pobieranie wartosci???????????-----------------" << endl;
        m1.wstaw(0, 0, 5).wstaw(1, 1, 10).wstaw(2, 2, 15);
        cout << "Macierz po wstawieniu wartosci:" << endl;
        cout << m1 << endl;
        cout << "Wartosc na (0,0): " << m1.pokaz(0, 0) << endl;
        cout << "Wartosc na (1,1): " << m1.pokaz(1, 1) << endl << endl;

        // Test 3: Odwracanie macierzy
        cout << "---------------Test 3: Odwracanie macierzy------------------------" << endl;
        cout << "Macierz przed odwroceniem:" << endl;
        cout << m1 << endl;
        m1.odwroc();
        cout << "Macierz po odwroceniu:" << endl;
        cout << m1 << endl;

        // Test 4: Wypełnianie przekątnej
        cout << "----------------------Test 4: Wypelnianie przekatnej------------------" << endl;
        int diag[] = { 1, 2, 3 };
        m1.diagonalna(diag);
        cout << "Macierz z przekatna [1, 2, 3]:" << endl;
        cout << m1 << endl;

        // Test 5: Wypełnianie kolumny i wiersza
        cout << "-----------------Test 5: Wypelnianie kolumny i wiersza-------------------" << endl;
        int col[] = { 7, 8, 9 };
        int row[] = { 4, 5, 6 };
        m1.kolumna(1, col).wiersz(2, row);
        cout << "Macierz po wypelnieniu kolumny i wiersza:" << endl;
        cout << m1 << endl;

        // Test 6: Wyświetlanie przekątnej, nad i pod przekątną
        cout << "---------------Test 6: Wyswietlanie przekatnej, nad i pod przekatna---------------" << endl;
        cout << "Macierz m1:" << endl;
        cout << m1 << endl;
        cout << "Przekatna macierzy: ";
        m1.przekatna();
        cout << "\nElementy pod przekatna macierzy:";
        m1.pod_przekatna();
        cout << "\nElementy nad przekatna macierzy:" << endl;
        m1.nad_przekatna();

        // Test 7: Operacje arytmetyczne na macierzach
        cout << "-----------------Test 7: Operacje arytmetyczne na macierzach---------------------" << endl;
        matrix m2(3);
        m2.losuj();
        cout << "Macierz m1:" << endl;
        cout << m1 << endl;

        cout << "Macierz m2:" << endl;
        cout << m2 << endl;
        cout << "-----------------------------------" << endl;

        matrix m3 = m1 + m2;
        cout << "Suma m1 + m2:" << endl;
        cout << m3 << endl;
        cout << "-----------------------------------" << endl;

        matrix m4 = m1 * m2;
        cout << "Iloczyn m1 * m2:" << endl;
        cout << m4 << endl;
		cout << "-----------------------------------" << endl;

        matrix m5 = m1 + 5;
        cout << "Dodanie 5 do kazdego elementu m1:" << endl;
        cout << m5 << endl;
        cout << "-----------------------------------" << endl;

        matrix m6 = 3 * m1;
        cout << "Pomnozenie kazdego elementu m1 przez 3:" << endl;
        cout << m6 << endl;

        // Test 8: Operatory porównania
        cout << "------------------------Test 8: Operatory porownania------------------------" << endl;
        cout << "Macierz m1:" << endl;
        cout << m1 << endl;

        cout << "Macierz m2:" << endl;
        cout << m2 << endl;

        cout << "Czy m1 == m2? " << (m1 == m2 ? "Tak" : "Nie") << endl;
        cout << "Czy m1 > m2? " << (m1 > m2 ? "Tak" : "Nie") << endl;
        cout << "Czy m1 < m2? " << (m1 < m2 ? "Tak" : "Nie") << endl << endl;

        // Test 9: Operatory inkrementacji i dekrementacji
        cout << "----------------Test 9: Operatory inkrementacji i dekrementacji-------------------" << endl;
        cout << "Macierz m1:" << endl;
        cout << m1 << endl;
        cout << "-----------------------------------" << endl;

        m1++;
        cout << "Macierz m1 po operatorze ++:" << endl;
        cout << m1 << endl;
        cout << "-----------------------------------" << endl;
        m1--;

        m1--;
        cout << "Macierz m1 po operatorze --:" << endl;
        cout << m1 << endl;
        m1++;

        // Test 10: Szachownica
        cout << "----------------Test 10: Szachownica----------------------------" << endl;
        cout << "Macierz w postaci szachownicy:" << endl;
        m1.szachownica();

        return 0;
    }