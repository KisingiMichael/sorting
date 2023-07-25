#include "sort.h"

void swaps(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swaps - swaps two integers in an array.
 * @a: The first element to swap.
 * @b: The second element to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - Oders a subset of an array using hoare partition scheme
 * @array: an array to be sorted
 * @size: size of an array
 * @leftIndex: The starting index of the subset to order.
 * @rightIndex: The ending index of the subset to order.
 *
 * Return: final index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int leftIndex, int rightIndex)
{
	int pivotIndex, upperBouund, lowerBound;

	pivotIndex = array[rightIndex];
	for (upperBound = leftIndex - 1, lowerBound = rightIndex + 1; upperBound < lowerBound;)
	{
		do {
			upperBound++;
		} while (array[upperBound] < pivotIndex);
		do {
			lowerBound--;
		} while (array[lowerBound] > pivotIndex);

		if (upperBound < lowerBound)
		{
			swaps(array + upperBound, array + lowerBound);
			print_array(array, size);
		}
	}

	return (upperBound);
}

/**
 * hoare_sort - Implements quicksort through recursion method
 * @array: An array to sort
 * @size: size of an array
 * @leftIndex: first index of the array partition to order
 * @rightIndex: last index of the array partition to order
 *
 * Description: Uses the Hoare partition scheme
 */
void hoare_sort(int *array, size_t size, int leftIndex, int rightIndex)
{
	int part;

	if (rightIndex - leftIndex > 0)
	{
		part = hoare_partition(array, size, leftIndex, rightIndex);
		hoare_sort(array, size, leftIndex, part - 1);
		hoare_sort(array, size, part, rightIndex);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using the quicksort
 * @array: An array to be sorted
 * @size: size of the array
 *
 * Description: Use of Hoare partition scheme
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_sort(array, size, 0, size - 1);
}
