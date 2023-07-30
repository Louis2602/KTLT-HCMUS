#include <iostream>
using namespace std;

int main()
{
	int a[] = {3, 5, 2, 6, 7, 1, 10, 9, 4};
	int n = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j] && a[i] % 2 == 0 && a[j] % 2 == 0)
				swap(a[i], a[j]);
			else if (a[i] < a[j] && a[i] % 2 != 0 && a[j] % 2 != 0)
				swap(a[i], a[j]);

	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";

	return 0;
}
