#!/usr/bin/python3
''' island_perimeter '''


def island_perimeter(grid):
    ''' Returns the `perimeter` haha of an `island` in a grid'''
    south_boundary = len(grid)
    east_boundary = len(grid[0])
    perimeter = 0
    row = 0
    cell = 0

    for row in range(south_boundary):
        for cell in range(east_boundary):
            if grid[row][cell]:
                ''' Check north '''
                if row == 0:
                    perimeter += 1
                elif grid[row - 1][cell] == 0:
                    perimeter += 1
                ''' Check south '''
                if (row + 1) == south_boundary:
                    perimeter += 1
                elif grid[row + 1][cell] == 0:
                    perimeter += 1
                ''' Check west '''
                if cell == 0:
                    perimeter += 1
                elif grid[row][cell - 1] == 0:
                    perimeter += 1
                ''' Check east '''
                if cell + 1 == east_boundary:
                    perimeter += 1
                elif grid[row][cell + 1] == 0:
                    perimeter += 1

    return perimeter
