#!/usr/bin/python3
'''
This program show all solutions the N queens problem,
for any given N.
'''
import sys


def print_board(board, n):
    '''
    Prints the locations of 1s in a n by n matrix
    '''
    print("[", end="")
    for row in range(n):
        for col in range(n):
            if board[row][col]:
                print("[{},{}]".format(row, col), end="")
                if row < n - 1:
                    print(", ", end="")
    print("]")


def attack_check(board, row, col, n):
    '''
    Checks if there is a queen on the board this spot can attack.
    Since we are filling the board from 0x0 to NxN, we only need to
    look left, up, and in the upwards diagonals for existing Queens.
    '''
    # Look horizontal left
    for x in range(col):
        if (board[row][x]):
            return False

    # Look up
    for y in range(row):
        if (board[y][col]):
            return False

    # Look diagonal to upper left
    i = row - 1
    j = col - 1
    while i >= 0 and j >= 0:
        if board[i][j]:
            return False
        i -= 1
        j -= 1

    # Look diagonal to upper right
    i = row - 1
    j = col + 1
    while i >= 0 and j < n:
        if board[i][j]:
            return False
        i -= 1
        j += 1

    return True


def solveNQUtil(board, row, n):
    '''
    Places queens on the board recursively by row
    '''
    if row >= n:
        return True

    for col in range(n):
        if attack_check(board, row, col, n):
            board[row][col] = 1
            # recur to place rest of the queens
            if solveNQUtil(board, row + 1, n) is True:
                return True
            board[row][col] = 0

    return False


def create_boards(n):
    '''
    Creates boards and sends them to recursive func
    '''
    for start in range(1, n - 1):
        board = [[0 for col in range(n)] for row in range(n)]
        board[0][start] = 1
        solveNQUtil(board, 1, n)
        print_board(board, n)


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)

n = sys.argv[1]
try:
    n = int(n)
except ValueError:
    print("N must be a number")
    exit(1)

if n < 4:
    print("N must be at least 4")
    exit(1)

create_boards(n)
