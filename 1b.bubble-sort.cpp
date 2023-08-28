#include <iostream>
#include <windows.h>
#include <time.h>
#include <iomanip>
#include <chrono>
using namespace std::chrono;
using namespace std;

int main()
{
	int n, key, res;
	cout << "Enter number of elements:";
	cin >> n;
	int arr[n];
	cout << "Enter the elements:";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	double time_spent = 0.0;
	auto start = high_resolution_clock::now();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	auto stop = high_resolution_clock::now();
	cout << "The sorted array is:\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\t';
	}
	auto diff = stop - start;
	// time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	cout << '\n'
		 << setprecision(40) << chrono::duration<double, milli>(diff).count() << " ms" << endl;
}
