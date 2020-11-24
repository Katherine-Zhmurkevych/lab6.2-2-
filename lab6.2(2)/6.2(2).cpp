//рекурсивний спосіб
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void create(int* a, const int size, const int Low, const int High, int index)
{
	a[index] = Low + rand() % (High - Low + 1);
	if (index < size - 1)
		create(a, size, Low, High, index + 1);
}

void print(int* a, const int size, int index)
{
	cout << setw(4) << a[index];
	if (index < size - 1)
		print(a, size, index + 1);
	else
		cout << endl;
}

int findMaxOddElement(int* a, const int size, int index, int max)
{
	if (index == size)
	{
		return max;
	}
	else
		if (a[index] > max && a[index] % 2 == 1)
		{
			max=a[index];
			index++;
			findMaxOddElement(a, size, index, max);
		}
		else
		{
			index++;
			findMaxOddElement(a, size, index, max);
		}
}

int main()
{
	srand((unsigned)time(NULL)); 
	const int n = 20;
	int a[n];
	int index = 0;
	int low = -100;
	int high = 100;
	int max=low;
	create(a, n, low, high, 0);
	print(a, n, 0);
	cout << "max odd number of this array is" << findMaxOddElement(a, n, index, max);
	return 0;
}