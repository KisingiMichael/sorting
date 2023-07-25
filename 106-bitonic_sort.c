#include "sort.h"

void swaps(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_seq_sort(int *array, size_t size, size_t start, size_t seq, char flow);

/**
 * swaps - swaps two integers in an array.
 * @a: The first element to swap.
 * @b: The second element to swap.
 */
void swaps(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, flips = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + flips; i++)
		{
			if ((flow == UP && array[i] > array[i + flips]) ||
			    (flow == DOWN && array[i] < array[i + flips]))
				swaps(array + i, array + i + flips);
		}
		bitonic_merge(array, size, start, flips, flow);
		bitonic_merge(array, size, start + flips, flips, flow);
	}
}

/**
 * bitonic_seq_sort - Converts an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq_sort(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cutArr = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq_sort(array, size, start, cutArr, UP);
		bitonic_seq_sort(array, size, start + cutArr, cutArr, DOWN);
		bitonic_merge_sort(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending
 *                order using the bitonic sort algo
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_seq_sort(array, size, 0, size, UP);
}
