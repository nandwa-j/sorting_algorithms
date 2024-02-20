#include "sort.h"
/**
 * bubble_sort - a function that sorts an array of integers in asscending order
 * @array: array of integers
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int tmp;
	int swap;

	for (b = size, swap = 1; b > 0 && swap; b--)
	{
		swap = 0;
		for (a = 0; (a + 1) < b; a++)
		{
			if (array[a] > array[a + 1])
			{
				tmp = array[a + 1];
				array[a + 1] = array[a];
				array[a] = tmp;
				print_array(array, size);
				swap = 1;
			}
		}
	}
}

