#include "sort.h"

/**
 * shell_sort - function that sorts an array of an integer in
 * ascending order using the knuth sequence
 * @array: the array
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t space = 1, k, m;
	int t;

	if (array == NULL || size< 2)
		return;
	while (space < size)
		space = space *3 + 1;
	space = (space - 1) / 3;

	while (space > 0)
	{
		for (k = space; k < size; k++)
		{
			t = array[k];
			m = k;
			while (m >= space && array[m - space] > t)
			{
				array[m] = array[m - space];
				m -= space;
			}
			array[m] = t;
		}
		print_array(array, size);
		space = (space - 1) / 3;
	}
}
