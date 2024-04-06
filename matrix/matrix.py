import numpy as np

matrix = np.array([[1, 2, 3],
                   [4, 5, 6],
                   [7, 8, 9]])

print(matrix)


class Matrix:
    def __init__(self, rows, cols):
        self.rows = rows
        self.cols = cols
        self.data = [[0] * cols for _ in range(rows)]

    def __getitem__(self, index):
        return self.data[index]

    def __setitem__(self, index, value):
        self.data[index] = value

    def __str__(self):
        return '\n'.join([' '.join(map(str, row)) for row in self.data])


# Example usage:
matrix = Matrix(3, 3)
matrix[0] = [1, 2, 3]
matrix[1] = [4, 5, 6]
matrix[2] = [7, 8, 9]
print(matrix)

