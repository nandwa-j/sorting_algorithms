#include "sort.h"

/**
 * merge - Merges two subarrays of array[]
 * @array: The array to be sorted
 * @left: Starting index of first subarray
 * @middle: Ending index of first subarray
 * @right: Ending index of second subarray
 */
void merge(int *array, int left, int middle, int right)
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = array[left + i];
	for (j = 0; j < n2; j++)
		R[j] = array[middle + 1 + j];

	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending
 * order using the Merge sort algorithm
 * @array: The array to be sorted
 * @left: Starting index of the array
 * @right: Ending index of the array
 */
void merge_sort(int *array, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;

		merge_sort(array, left, middle);
		merge_sort(array, middle + 1, right);

		merge(array, left, middle, right);
		print_array(array + left, right - left + 1);
	}
}

/**
 * radix_sort - Sorts an array of integers in ascending
 * order using the Radix sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	merge_sort(array, 0, size - 1);
}

