#include "sort.h"

void swaps(int *a, int *b);
void max_heap(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swaps - function to swap two elements in an array
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
 * max_heap - Turns a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: size of the array/tree.
 * @base: An index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heap(int *array, size_t size, size_t base, size_t root)
{
	size_t left_node, right_node, large_node;

	left_node = 2 * root + 1;
	right_node = 2 * root + 2;
	large_node = root;

	if (left_node < base && array[left_node] > array[large_node])
		large = left;
	if (right_node < base && array[right_node] > array[large_node])
		large_node = right_node;

	if (large_node != root)
	{
		swaps(array + root, array + large_node);
		print_array(array, size);
		max_heap(array, size, base, large_node);
	}
}

/**
 * heap_sort - function to sort an array of integers in ascending
 *             order using the heap sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heaparray, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swaps(array, array + i);
		print_array(array, size);
		max_heap(array, size, i, 0);
	}
}
