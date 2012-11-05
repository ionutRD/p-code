#! /usr/bin/python
# Given an array of n elements arr[start:end]
# Compute the minimum number of steps from start to end
# Ex: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
# Output is 3 (1 -> 3 -> 8 -> 9)

def min_no_of_jumps(arr):
  n = len(arr)
  A = []
  for i in range(n):
    A.append(0)

  for i in range(n - 1, -1, -1):
    if arr[i] == 0:
      A[i] = float("inf")
    elif arr[i] >= n - i - 1:
      A[i] = 1
    else:
      A[i] = 1 + min([A[k] for k in range(i + 1, n) if arr[i] >= k - i])
  return A[0]

if __name__ == "__main__":
  arr = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
  print min_no_of_jumps(arr)
