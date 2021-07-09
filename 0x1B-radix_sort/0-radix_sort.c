#include "sort.h"


/**
 * radix_sort - sorts an array of integers using LSD radix sort
 * @array: integer array to sort
 * @size: length of array
 */
void radix_sort(int *array, size_t size)
{
	int max;
	size_t i = 1;
	int exp = 1;

	if (!array || size < 2)
		return;

	max = array[0];

	for (; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (; max / exp > 0; exp *= 10)
		radix_count(array, size, exp);
}

/**
 * radix_count - count occurrances of each digit and sort accordingly
 * @array: integer array to sort
 * @size: length of array
 * @exp: exponent of int to compare
 */
void radix_count(int *array, size_t size, int exp)
{
	int *output = NULL;
	int	count[10] = {0};
	int x;
	size_t y;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (y = 0; y < size; y++)
		count[(array[y] / exp) % 10]++;

	for (y = 1; y < 10; y++)
		count[y] += count[y - 1];

	for (x = size - 1; x >= 0; x--)
	{
		output[count[(array[x] / exp) % 10] - 1] = array[x];
		count[(array[x] / exp) % 10]--;
	}

	for (y = 0; y < size; y++)
		array[y] = output[y];

	print_array(array, size);
	free(output);
}
