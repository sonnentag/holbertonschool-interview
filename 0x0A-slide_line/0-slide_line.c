#include <stdlib.h>
#include "slide_line.h"

void slide_l(int *line, size_t size);
void slide_r(int *line, size_t size);
void merge_l(int *line, size_t size);
void merge_r(int *line, size_t size);

/**
 * slide_line - merge an array of integers
 * @line: series of 0 and non-0 ints
 * @size: length
 * @direction: direction to shift values
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == 0)
	{
		slide_l(line, size);
		merge_l(line, size);
		slide_l(line, size);
	}
	else if (direction == 1)
	{
		slide_r(line, size);
		merge_r(line, size);
		slide_r(line, size);
	}
	else
		return (0);

	return (1);
}

/**
 * slide_l - slide numbered positions to the left
 * @line: series of 0 and non-0 ints
 * @size: length
 */
void slide_l(int *line, size_t size)
{
	int position, z, more, move, temp, next = 0, siz = size;

	do {
		z = 0, more = 0;
		for (position = next; position < siz; position++)
			if (line[position] == 0)
				z++;
			else
			{
				more = 1;
				break;
			}

		temp = z + next;
		if (temp < siz)
		{
			move = line[next];
			line[next] = line[temp];
			line[temp] = move;
		}

		next++;

	} while (more);
}

/**
 * slide_r - slide numbered positions to the right
 * @line: series of 0 and non-0 ints
 * @size: length
 */
void slide_r(int *line, size_t size)
{
	int position, z, more, move, temp, siz = size, next = siz - 1;

	do {
		z = 0, more = 0;
		for (position = next; position >= 0; position--)
			if (line[position] == 0)
				z++;
			else
			{
				more = 1;
				break;
			}

		temp = next - z;
		if (temp >= 0)
		{
			move = line[next];
			line[next] = line[temp];
			line[temp] = move;
		}

		next--;

	} while (more);
}

/**
 * merge_l - merge 2 positions while shifting left
 * @line: series of 0 and non-0 ints
 * @size: length
 */
void merge_l(int *line, size_t size)
{
	size_t next;
	int temp;

	for (next = 0; next < size - 1; next++)
	{
		temp = next + 1;
		if (line[next] == line[temp])
		{
			line[next] += line[temp];
			line[temp] = 0;
		}
	}
}

/**
 * merge_r - merge 2 positions while shifting right
 * @line: series of 0 and non-0 ints
 * @size: length
 */
void merge_r(int *line, size_t size)
{
	size_t next;
	int temp;

	for (next = size - 1; next > 0; next--)
	{
		temp = next - 1;
		if (line[next] == line[temp])
		{
			line[next] += line[temp];
			line[temp] = 0;
		}
	}
}
