#include "sort.h"

/**
 * swap_int - function that swaps two elements in an array
 * @a: the first element to be swaped
 * @b: the seconde element to be swaped
 */
void swap_int(int *a, int *b)
{
	int t;

	t = *a;
	*b = t;
}

/**
 * lomuto_partition - function that partitions throught an array of integers
 * @array: array of ints
 * @size: the size of the array
 * @first: first index of an array
 * @last: the last index of the array
 *
 * Description: all values must be accurate
 * Return: the new index
 */
int lomuto_partition(int *array, size_t size, int first, int last)
{
	int pivot = array[last], k = first, m;

	for (m = first; m <= last - 1; m++)
	{
		if (array[m] < pivot)
		{
			if (k != m)
			{
				swap_int(&array[k], &array[m]);
				print_array(array, size);
			}
			k++;
		}
	}
	if (pivot != array[k])
	{
		swap_int(&array[k], &array[last]);
		print_array(array, size);
	}
	return (k);
}

/**
 * lomuto_sort - function that implements the quick sort
 * algorithm using recursion
 * @array: the array
 * @size: the size ofthe array
 * @first: the first index
 * @last: the last index
 * Return: 0
 */
void lomuto_sort(int *array, size_t size, int first, int last)
{
	int k;

	if (first < last)
	{
		k = lomuto_partition(array, size, first, last);
		lomuto_sort(array, size, first, k - 1);
		lomuto_sort(array, size, k + 1, last);
	}
}

/**
 * quick_sort - function that sorts an array of ints in ascending order
 * using quick sort algorithm
 * @array: the array
 * @size: the size of the array
 * Return: 0
 */
void quick_sort(int *array, size_t size)
{
	if (array == 0 || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
