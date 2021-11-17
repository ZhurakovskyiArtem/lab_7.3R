// Lab_7_3.cpp
// < прізвище, ім’я автора >
// Лабораторна робота № 7.3.
// Опрацювання динамічних багатовимірних масивів. Рекурсивний спосіб.
// Варіант 0
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void PrintRow(int** a, const int rowNo, const int n, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < n - 1)
		PrintRow(a, rowNo, n, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int k, const int n, int rowNo)
{
	PrintRow(a, rowNo, n, 0);
	if (rowNo < k - 1)
		PrintRows(a, k, n, rowNo + 1);
	else
		cout << endl;
}
void InputRow(int** a, const int rowNo, const int n, int colNo)
{
	cout << "a[" << rowNo << "][" << colNo << "] = ";
	cin >> a[rowNo][colNo];
	if (colNo < n - 1)
		InputRow(a, rowNo, n, colNo + 1);
	else
		cout << endl;
}
void InputRows(int** a, const int k, const int n, int rowNo)
{
	InputRow(a, rowNo, n, 0);
	if (rowNo < k - 1)
		InputRows(a, k, n, rowNo + 1);
	else
		cout << endl;
}
int Sum(int** a, const int k, const int n, int& S, int count, int i, int j, int l)
{
	if (a[i][j] < 0)
	{
		count++;
	}
	else
		if (i < k - 1)
			return Sum(a, k, n, S, count, i + 1, j, l);
			if(l == 0)
			i = 0;
	if (count == 0)
	{
		if (a[i][j] >= 0)
		{
			S += a[i][j];
			l++;
			if(l < n - 1)
			return  Sum(a, k, n, S, count, i + 1, j, l);
		}
	}
	if (j < n - 1)
	{
		count = 0;
		return Sum(a, k, n, S, count, 0, j + 1, 0);
	}
	else 
		return S;
}
int main()
{
	srand((unsigned)time(NULL));
	int k, n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;
	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
		InputRows(a, k, n, 0);
	PrintRows(a, k, n, 0);
	int count = 0;
    int S = 0;
	cout << Sum(a, k, n, S, 0, 0, 0, 0);
	return 0;
}