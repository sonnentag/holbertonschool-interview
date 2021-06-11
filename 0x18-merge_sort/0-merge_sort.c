#include "sort.h"


/**
 * merge_sort - called by main for top down merge sort
 * @array: array to sort
 * @size: size/length of array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp = NULL;

	if (array && size >= 2)
		tmp = malloc(sizeof(int) * size);

	if (tmp)
	{
		mergeSort(array, size, tmp);
		free(tmp);
	}
}

/**
 * mergeSort - recurse left, then right, then merge together
 * @arr: array to sort
 * @size: size/length of array
 * @tmp: tmp array
 */
void mergeSort(int *arr, int size, int *tmp)
{
	int m = size / 2;

	if (m >= 1)
	{
		mergeSort(arr, m, tmp);
		mergeSort(arr + m, size - m, tmp);

		printf("Merging...\n[left]: ");
		print_array(arr, m);
		printf("[right]: ");
		print_array(arr + m, size - m);

		merge(arr, size, m, tmp);
	}
}

/**
 * merge - merge left and right sections
 * @arr: array to sort
 * @size: size/length of array
 * @m: middle index
 * @tmp: tmp array
 */
void merge(int *arr, int size, int m, int *tmp)
{
	int l = 0, r = 0, c = m;

	while (r < size)
	{
		if (c == size)
		{
			tmp[r] = arr[l];
			l++;
		}
		else if ((l == m) || (arr[c] < arr[l]))
		{
			tmp[r] = arr[c];
			c++;
		}
		else
		{
			tmp[r] = arr[l];
			l++;
		}
		r++;
	}

	for (l = 0; l < size; l++)
		arr[l] = tmp[l];

	printf("[Done]: ");
	print_array(tmp, size);
}
