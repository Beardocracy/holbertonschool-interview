#include "menger.h"
#include <math.h>
#include <stdio.h>


/**
 * menger - draws a 2d menger sponge of a given level
 * @level: the number of dimensions
 */
void menger(int level)
{
	int i, j, dim, d;

	dim = pow(3, level);
	for (i = 0; i < dim; i++)
	{
		for (j = 0; j < dim; j++)
		{
			for (d = dim / 3; d; d /= 3)
			{
				if ((i % (d * 3)) / d == 1)
					if ((j % (d * 3)) / d == 1)
						break;
			}
			if (d)
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
