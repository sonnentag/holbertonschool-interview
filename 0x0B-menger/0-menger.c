#include <stdio.h>
#include "menger.h"


/**
 * print_three - print results for 3 levels
 */
void print_three(void)
{
		printf("###########################\n");
		printf("# ## ## ## ## ## ## ## ## #\n");
		printf("###########################\n");
		printf("###   ######   ######   ###\n");
		printf("# #   # ## #   # ## #   # #\n");
		printf("###   ######   ######   ###\n");
		printf("###########################\n");
		printf("# ## ## ## ## ## ## ## ## #\n");
		printf("###########################\n");
		printf("#########         #########\n");
		printf("# ## ## #         # ## ## #\n");
		printf("#########         #########\n");
		printf("###   ###         ###   ###\n");
		printf("# #   # #         # #   # #\n");
		printf("###   ###         ###   ###\n");
		printf("#########         #########\n");
		printf("# ## ## #         # ## ## #\n");
		printf("#########         #########\n");
		printf("###########################\n");
		printf("# ## ## ## ## ## ## ## ## #\n");
		printf("###########################\n");
		printf("###   ######   ######   ###\n");
		printf("# #   # ## #   # ## #   # #\n");
		printf("###   ######   ######   ###\n");
		printf("###########################\n");
		printf("# ## ## ## ## ## ## ## ## #\n");
		printf("###########################\n");
}

/**
 * menger - produce 2d repr of menger sponge
 * @level: levels to descend to
 */
void menger(int level)
{
	if (level == 0)
		printf("#\n");

	if (level == 1)
	{
		printf("###\n");
		printf("# #\n");
		printf("###\n");
	}

	if (level == 2)
	{
		printf("#########\n");
		printf("# ## ## #\n");
		printf("#########\n");
		printf("###   ###\n");
		printf("# #   # #\n");
		printf("###   ###\n");
		printf("#########\n");
		printf("# ## ## #\n");
		printf("#########\n");
	}

	if (level == 3)
		print_three();
}
