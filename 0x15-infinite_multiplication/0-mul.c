#include "holberton.h"

/**
 * _puts - put string
 * @string: character string
 * Return: void
 */
void _puts(char *string)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
		_putchar(string[i]);
}

/**
 * if_error - check if there's an error
 * @argc: arg count
 * @argv: arg values
 * Return: 0 or 98 on error
 */
int if_error(int argc, char **argv)
{
	int x, y;

	if (argc != 3)
	{
		_puts("Error\n");
		exit(98);
	}
	for (x = 1; x < argc; x++)
	{
		for (y = 0; argv[x][y]; y++)
		{
			if (argv[x][y] > '9' || argv[x][y] < '0')
			{
				_puts("Error\n");
				exit(98);
			}
		}
	}
	return (0);
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: an array consisting arguments
 *
 * Return: 0 or 1
 */

int main(int argc, char **argv)
{
	int len1, len2, carry, a, b, x, y;
	int *product;

	if_error(argc, argv);
	len1 = strlen(argv[1]), len2 = strlen(argv[2]);
	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		_puts("0\n");
		return (EXIT_SUCCESS);
	}

	product = malloc(sizeof(*product) * (len1 + len2));
	if (!product)
		return (EXIT_FAILURE);

	for (x = len1 - 1; x >= 0; x--)
	{
		carry = 0;
		a = argv[1][x] - '0';

		for (y = len2 - 1; y >= 0; y--)
		{
			b = argv[2][y] - '0';
			carry += product[x + y + 1] + (a * b);
			product[y + x + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			product[x + y + 1] += carry;
	}

	a = product[0] == 0 ? 1 : 0;
	for (; a < len1 + len2; a++)
		_putchar((product[a]));

	_puts("\n");
	free(product);

	return (EXIT_SUCCESS);
}


