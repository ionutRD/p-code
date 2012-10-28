#! /usr/bin/python
# Check for majority element in a given sorted array

def check_for_majority(arr, x):
  i = bsearch(arr, 0, len(arr) - 1, x)
  if i == -1:
    return 0

  if (i + len(arr) / 2 <= len(arr) - 1) and arr[i + len(arr) / 2] == x:
    return 1

def bsearch(arr, inf, sup, x):
  if inf <= sup:
    mid = (inf + sup) / 2
    if arr[mid] == x and mid > 0 and arr[mid - 1] != x:
      return mid
    elif arr[mid] == x and mid > 0 and arr[mid - 1] == x:
      return bsearch(arr, inf, mid - 1, x)
    elif x > arr[mid]:
      return bsearch(arr, mid + 1, sup, x)
    else:
      return bsearch(arr, inf, mid - 1)
  return -1

if __name__ == "__main__":
  print "TEST1: arr = [1, 2, 3, 3, 3, 3, 10]"
  arr = [1, 2, 3, 3, 3, 3, 10]
  print check_for_majority(arr, 3)
