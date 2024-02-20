#include "sort.h"

/**
 * quick_sort - function that sorts an array
 * of integers in ascending order using the
 * quick sort algorithm
 *
 * @array: input array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    _qsort(array, 0, size - 1, size);
}

/**
 * _qsort - auxiliary function for the quick_sort function
 * @array: input array
 * @low: index of the first element
 * @high: index of the last element
 * @size: size of the array
 */
void _qsort(int *array, int low, int high, int size)
{
    if (low < high)
    {
        int pivot = partition(array, low, high, size);
        _qsort(array, low, pivot - 1, size);
        _qsort(array, pivot + 1, high, size);
    }
}

/**
 * partition - function to partition the array
 * @array: input array
 * @low: index of the first element
 * @high: index of the last element
 * @size: size of the array
 * Return: index of the pivot element
 */
int partition(int *array, int low, int high, int size)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }
    if (array[i + 1] != array[high])
    {
        swap(&array[i + 1], &array[high]);
        print_array(array, size);
    }
    return (i + 1);
}

/**
 * swap - function to swap two elements in the array
 * @a: first element
 * @b: second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

