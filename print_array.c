#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - This function Prints an array of integers
 *
 * @array: Tjhis is The array to be printed
 * @size: This is the Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t g;

	g = 0;
	while (array && g < size)
	{
		if (g > 0)
			printf(", ");
		printf("%d", array[g]);
		++g;
	}
	printf("\n");
}
