#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

/**
 * lefty_doubler - Doubles the value at an index in an array if the next
 * non-zero value index has the same value.
 *
 * @line: points to an array of integers
 * @size: the size of the array
 *
 * Return: 1 on success, 0 on failure
 */
int lefty_doubler(int *line, size_t size)
{
	size_t tort = 0;
	size_t hare;

	while (tort < size - 1)
	{
		hare = tort + 1;
		while (hare < size)
		{
			if (line[tort] == line[hare])
			{
				line[tort] *= 2;
				line[hare] = 0;
				hare = size;
			}
			hare += 1;
		}
		tort += 1;
	}
	return (1);
}

/**
 * lefty_shifter - Shifts all non-zero ints to the extreme left.
 *
 * @line: points to an array of integers
 * @size: the size of the array
 *
 * Return: 1 on success, 0 on failure
 */
int lefty_shifter(int *line, size_t size)
{
	size_t tort = 0;
	size_t hare = 1;

	while (tort < size)
	{
		if (line[tort] == 0)
		{
			while (line[hare] == 0)
				hare += 1;

			if (hare >= size)
				return (1);

			line[tort] = line[hare];
			line[hare] = 0;
		}
		tort += 1;
		hare = tort + 1;
	}

	return (1);
}

/**
 * righty_doubler - Doubles the value at an index in an array if the previous
 * non-zero value index has the same value.
 *
 * @line: points to an array of integers
 * @size: the size of the array
 *
 * Return: 1 on success, 0 on failure
 */
int righty_doubler(int *line, size_t size)
{
	size_t tort = size - 1;
	size_t hare;

	while (tort != 0 && tort < size)
	{
		hare = tort - 1;
		/* This loop stops when hare overflows to max int */
		while (hare < size)
		{
			if (line[tort] == line[hare])
			{
				line[tort] *= 2;
				line[hare] = 0;
				hare = 0;
			}
			hare -= 1;
		}
		tort -= 1;
	}
	return (1);
}

/**
 * righty_shifter - Shifts all non-zero ints to the extreme right.
 *
 * @line: points to an array of integers
 * @size: the size of the array
 *
 * Return: 1 on success, 0 on failure
 */
int righty_shifter(int *line, size_t size)
{
	size_t tort = size - 1;
	size_t hare = tort - 1;

	while (tort > 0)
	{
		if (line[tort] == 0)
		{
			while (line[hare] == 0)
			{
				if (hare == 0)
					return (1);
				hare -= 1;
			}
			if (hare > size)
				return (1);

			line[tort] = line[hare];
			line[hare] = 0;
		}
		tort -= 1;
		hare = tort - 1;
	}

	return (1);
}


/**
 * slide_line - Slides and merges an array of integers
 *
 * @line: points to an array of integers
 * @size: The number of elements in array line
 * @direction: the direction of the slide
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (size < 2)
		return (1);

	if (direction == SLIDE_LEFT)
	{
		lefty_doubler(line, size);
		lefty_shifter(line, size);
		return (1);
	}
	if (direction == SLIDE_RIGHT)
	{
		righty_doubler(line, size);
		righty_shifter(line, size);
		return (1);
	}

	return (0);
}
