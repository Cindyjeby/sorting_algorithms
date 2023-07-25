#include "sort.h"

/**
 * bubble_sort - fucntion that sorts an array of integers in ascending order
 * @array: the array tobe sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int k;
	int swap;

	if (array == NULL || size < 2)
		return;

	/*num of passes required to sort the arry*/
	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		/*checks if any swap occured in this pass*/

		/*compare and swap adjacent elements*/
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				k = array[j];
				array[j] = array[j + 1];
				array[j + 1] = k;
				swap = 1;
				print_array(array, size);
			}
		}
		if (swap == 0)
		{
			return;
		}
	}
}
