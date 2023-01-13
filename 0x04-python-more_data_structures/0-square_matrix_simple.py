#!/usr/bin/python3

def square_matrix_simple(matrix=[]):
    squared = []

    for line in matrix:
        new_line = []

        for val in line:
            new_line.append(val ** 2)

        squared.append(new_line)

    return squared
