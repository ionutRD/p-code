#! /usr/bin/python
# Given an array where A[i + 1] = A[i] + 1 or A[i] - 1
# Find an element k in the array O(n/k)

def find_elem(arr, k):
  diff = 0
  i = 0
  while i < len(arr):
    if (arr[i] == k):
      return True
    diff = abs(arr[i] - k)
    i += diff
  return False

if __name__ == "__main__":
  arr = [3, 4, 3, 2, 1, 2, 3]
  print find_elem(arr, 6)

