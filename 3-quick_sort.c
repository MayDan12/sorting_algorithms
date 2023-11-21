#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - This function Swap two integers in an array.
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
 * lomuto_partition - This function Order a subset of an array of integers according to
 *   the lomuto partition scheme (last element as pivot).
 * @array: This is The array of integers.
 * @size: size of the array.
 * @left: starting index of the subset to order.
 * @right: ending index of the subset to order.
 *
 * Return: always return The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivots, above, below;

	pivots = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivots)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivots)
	{
		swap_ints(array + above, pivots);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - This function Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: size of the array.
 * @left: starting index of the array partition to order.
 * @right: ending index of the array partition to order.
 *
 * Description: This Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int parts;

	if (right - left > 0)
	{
		parts = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, parts - 1);
		lomuto_sort(array, size, parts + 1, right);
	}
}

/**
 * quick_sort - This function Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: array of integers.
 * @size: This is The size of the array.
 *
 * Description: This is the Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
