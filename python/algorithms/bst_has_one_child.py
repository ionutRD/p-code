#! /usr/bin/python
# Check if a binary tree has exactly one child given the preorder traversal

def has_one_child(arr):
  min = float("-inf")
  max = float("inf")
  for i in range(len(arr)):
    if arr[i] <= min or arr[i] >= max:
      return False
    if i < len(arr) - 1 and arr[i] < arr[i + 1]:
      min = arr[i]
    elif i < len(arr) - 1 and arr[i] > arr[i + 1]:
      max = arr[i]
  return True

if __name__ == "__main__":
  print "Test for arr = [5, 10, 7, 8, 9]"
  arr = [5, 10, 7, 8, 9]
  print has_one_child(arr)
  print "Test for arr = [5, 3, 2, 4, 10, 7, 11]"
  arr = [5, 3, 2, 4, 10, 7, 11]
  print has_one_child(arr)
