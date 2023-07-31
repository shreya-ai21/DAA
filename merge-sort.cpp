// C++ program for Merge Sort
#include <bits/stdc++.h>
#include<cstdlib>
using namespace std;
int cnt=0;
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
		   int const right)
{
	int const n1 = mid - left + 1;
	int const n2 = right - mid;

	// Create temp arrays
	auto *a = new int[n1],
		 *b = new int[n2];

	// Copy data to temp arrays a[] and b[]
	for (auto i = 0; i < n1; i++)
		a[i] = array[left + i];
	for (auto j = 0; j < n2; j++)
		b[j] = array[mid + 1 + j];

	auto i = 0, j = 0;
	int k = left;

	// Merge the temp arrays back into array[left..right]
	while (i < n1 && j < n2)
	{
		cnt++;
		if (a[i] <= b[j])
		{
			array[k] = a[i];
			i++;
		}
		else
		{
			array[k] = b[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of
	// left[], if there are any
	while (i < n1)
	{
		array[k] = a[i];
		i++;
		k++;
	}

	// Copy the remaining elements of
	// right[], if there are any
	while (j < n2)
	{
		array[k] = b[j];
		j++;
		k++;
	}
	delete[] a;
	delete[] b;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
	int n;
	cout << "Enter number of elements:";
	cin >> n;
	int arr[n];
	int l = 0;
	// cout << "Enter the elements:";
	for (int i = 0; i < n; i++)
	{
		arr[i]=rand()%1000;
	}

	mergeSort(arr, 0, n - 1);

	// cout << "\nSorted array is \n";
	// printArray(arr, n);

	cout<<"Number of times basic operation is run: "<<cnt;
	return 0;
}
