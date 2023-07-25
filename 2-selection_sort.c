#include "sort.h"

/**
 * swap_int - function that swaps two elements in an array
 * @a: the first element to be waped
 * @b: the second element
 */
void swap_int(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * selection_sort - function that sorts an array of integers in ascending order
 * using selection sort algorithm
 * @array: the array to be sored
 * @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t k, n, m;

	for (k = 0; k < size - 1; k++)
	{
		m = k;
		for (n = k + 1; n < size; n++)
			if (array[n] < array[m])
				m = n;
		if (m != k)
		{
			swap_int(&array[m], &array[k]);
			print_array(array, size);
		}
	}
}
