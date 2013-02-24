#! /usr/bin/python
# Let A be a MxN matrix with positive integers
# Calculate the minimum cost path from position (0, 0) to
# a position (m,n) in O(mn) time.
# The valid moves are down, left and diagonally left
# C[i][j] = min(C[i - 1][j - 1], C[i - 1][j], C[i][j - 1]) + A[i][j]

def min_cost_path(A, m, n):
  C = []
  for i in range(m + 1):
    l = []
    for j in range(n + 1):
      l.append(float("inf"))
    C.append(l)
  
  C[0][0] = A[0][0]
  for i in range(m + 1):
    for j in range(n + 1):
      if i == 0 and j > 0:
        C[i][j] = C[i][j - 1] + A[i][j]
      elif j == 0 and i > 0:
        C[i][j] = C[i - 1][j] + A[i][j]
      elif i != 0 and j != 0:
        C[i][j] = min(C[i - 1][j], C[i][j - 1], C[i - 1][j - 1]) + A[i][j]
  
  return C[m][n]

if __name__ == "__main__":
  A = [[1, 2, 3], [4, 8, 2], [1, 5, 3]]
  print min_cost_path(A, 2, 2)
