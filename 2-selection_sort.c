#include "sort.h"

/**
 * selection_sort - sorts an array of integers in
 * ascending order using the Selection sort
 * algorithm
 *
 * @array: input array of integers
 * @size: size of the array
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t a, b, c;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size; a++)
	{
		c = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[c] > array[b])
				c = b;
		}

		if (a != c)
		{
			tmp = array[a];
			array[a] = array[c];
			array[c] = tmp;
			print_array(array, size);
		}
	}
}
