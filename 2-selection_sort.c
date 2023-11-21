#include "sort.h"

/**
 * swap_ints - This Swap two integers in an array.
 * @a: This is The first integer to swap.
 * @b: This is The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmps;

	tmps = *a;
	*a = *b;
	*b = tmps;
}

/**
 * selection_sort - This functrion Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: This is An array of integers.
 * @size: This is The size of the array.
 * Written by daniel
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *mins;
	size_t m, j;

	if (array == NULL || size < 2)
		return;

	for (m = 0; m < size - 1; m++)
	{
		mins = array + m;
		for (j = m + 1; j < size; j++)
			mins = (array[j] < *mins) ? (array + j) : mins;

		if ((array + m) != mins)
		{
			swap_ints(array + m, mins);
			print_array(array, size);
		}
	}
}
