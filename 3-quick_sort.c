#include "sort.h"

void swap(int *a, int *b);
void lomuto_sort(int *arr, size_t size, int low, int high);
void quick_sort(int *array, size_t size);
/**
 * swap - function to swap elements in an array.
 * @a: pointer to the first element.
 * @b: pointer to the second element.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_sort - function to sort an array using the lumuto
 * partitioning scheme
 *
 * @arr: pointer to the array
 * @size: size of the array
 * @low: starting index of the partition.
 * @high: ending index of the partition.
 */
void lomuto_sort(int *arr, size_t size, int low, int high)
{
	int *pivot, i, j;

	if (high <= low)
		return;

	pivot = arr + high;
	for (i = j = low; j < high; j++)
	{
		if (arr[j] < *pivot)
		{
			if (i < j)
			{
				swap(arr + j, arr + i);
				print_array(arr, size);
			}
			i++;
		}
	}

	if (arr[i] > *pivot)
	{
		swap(arr + i, pivot);
		print_array(arr, size);
	}

	lomuto_sort(arr, size, low, i - 1);
	lomuto_sort(arr, size, i + 1, high);
}

/**
 * quick_sort - function to sort an array using the quick sort algorithm
 * @array: pointer to the array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto(array, size, 0, size - 1);
}
