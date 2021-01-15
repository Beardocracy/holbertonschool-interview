#include "sandpiles.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_grid - prints a 3x3 int matrix
 * @grid: the grid to be printed
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: a 3x3 matrix of integers
 * @grid2: a 3x3 matrix of integers
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, value;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}
	while (pile_not_sifted(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		zero_out(grid2);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				value = grid1[i][j];
				if (value < 4)
					grid2[i][j] += value;
				else
				{
					grid2[i][j] += value - 4;
					if ((i - 1) >= 0 && (i - 1) <= 2)
						grid2[i - 1][j] += 1;
					if ((i + 1) >= 0 && (i + 1) <= 2)
						grid2[i + 1][j] += 1;
					if ((j - 1) >= 0 && (j - 1) <= 2)
						grid2[i][j - 1] += 1;
					if ((j + 1) >= 0 && (j + 1) <= 2)
						grid2[i][j + 1] += 1;
				}
			}
		}
		copy_over(grid1, grid2);
	}
}

/**
 * zero_out - changes a 3x3 matrix to all zeroes
 * @grid: the matrix to be zeroed
 */
void zero_out(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] = 0;
		}
	}
}

/**
 * copy_over - overwrites a grid with values from another grid
 * @grid1: the grid to be overwritten
 * @grid2: the grid to be copied
 */
void copy_over(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid2[i][j];
		}
	}
}

/**
 * pile_not_sifted - checks if sandpile is sifted
 * @grid: 3x3 matrix
 * Return: true if matrix contains int greater than 3
 */
int pile_not_sifted(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	}
	return (0);
}
