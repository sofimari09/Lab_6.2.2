#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
int Max(int* a, const int size, int i, int max, int indexMax)
{
	if (a[i] > max)
	{
		max = a[i];
		indexMax = i;
	}
	if (i < size - 1)
		return Max(a, size, i + 1, max, indexMax);
	else
		return indexMax;
	
}
int Min(int* a, const int size, int k, int min, int indexMin)
{
		if (a[k] < min)
		{
			min = a[k];
			indexMin = k;
		}
		if (k < size - 1)
			return Min(a, size, k + 1, min, indexMin);
		else
	return indexMin;
}
int sum(int x, int y)
{
	return x + y;
}

int main()
{
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	const int n = 10;
	int a[n];

	int Low;
	cout << "Low="; cin >> Low;
	int High;
	cout << "High="; cin >> High;
	Create(a, n, Low, High,0);
	Print(a, n,0);
	int c = sum(Max(a, n, 1 ,a[0], 0), Min(a, n, 1, a[1], 0));
	cout << "indexMax = " << Max(a, n, 1, a[0], 0) << endl;
	cout << "indexMin = " << Min(a, n, 1, a[1], 0) << endl;
	cout << "ave:" << 1. * (c) / 2 << endl;
	return 0;
}