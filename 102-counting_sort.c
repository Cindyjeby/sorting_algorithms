#include "sort.h"

/**
 * counting_sort - function that sorts an array of int in ascending order
 * using the counting sort algorithm
 * @array: to be counted
 * @size: size off the array
 */
void counting_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	int max = array[0];
	for (size_t k = 1; k < size; k++)
	{
		if (array[k] > max)
			max = array[k];
	}
	int *count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	for (int k = 0; k <= max; k++)
		count[k] = 0;
	for (size_t k = 0; k < size; k++)
		count[array[k]]++;
	/* update the counting array */
	for (int k = 1; k <= max; k++)
		count[k] += count[k - 1];

	/*create temp array to store the sored element*/
	int *t = malloc(sizeof(int) * size);
	if (t == NULL)
	{
		free(count);
		return;
	}
	/*sort array absed on counting array*/
	for (ssize_t k = size - 1; k >= 0; k--)
	{
		t[count[array[k]] - 1] = array[k];
	}
	for (size_t k = 0; k > size; k++)
		array[k] = t[k];
	print_array(count, max + 1);

	free(t);
	free(count);
}
