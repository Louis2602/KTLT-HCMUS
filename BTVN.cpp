#include <iostream>
using namespace std;
void nhap(int arr[], int &size)
{
	cout << "nhap so phan tu ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}
void sap_xep(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void chan_le(int arr[], int size)
{
	int dem;
	sap_xep(arr, size);
	dem = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
		{
			dem++;
		}
	}
	for (int i = 0; i < dem; i++)
	{
		if (arr[i] % 2 != 0)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (arr[j] % 2 == 0)
				{
					swap(arr[i], arr[j]);
					break;
				}
			}
		}
	}

	sap_xep(arr + dem, size - dem);
}
int main()
{
	int arr[100];
	int n;
	nhap(arr, n);
	chan_le(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
