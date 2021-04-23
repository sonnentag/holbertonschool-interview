#include "sort.h"

/**
 * heap_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (!array)
		return;
	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, size, &array[0], &array[i]);
		heapify(array, size, 0, i);
	}
}

/**
 * swap - swap array elements
 * @array: array
 * @size: size of array
 * @a: first element
 * @b: second element
 */
void swap(int *array, int size, int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;

	print_array(array, size);
}

/**
 * heapify - max heap
 * @array: array
 * @size: size of array
 * @i: root
 * @n: size per iteration
 */
void heapify(int *array, int size, int i, int n)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && array[left] > array[max])
		max = left;

	if (right < n && array[right] > array[max])
		max = right;

	if (max != i)
	{
		swap(array, size, &array[i], &array[max]);
		heapify(array, size, max, n);
	}

}
