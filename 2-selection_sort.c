#include "sort.h"

/**
 * selection_sort - function to sort an array following the selection sort algorithm
 * @array: a given array
 * @size: size of the array;
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min_value;

	register int temp;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min_vale = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_value])
				min_value = j;
		}
		temp = array[i];
		array[i] = array[min_value];
		array[min_value] = temp;
		if (i != min_value)
			print_array(array, size);
	}
}
