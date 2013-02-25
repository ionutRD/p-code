#! /usr/bin/python

def find_fix(arr, inf, sup):
  if sup >= inf:
    mid = (inf + sup) / 2
    if mid == arr[mid]:
      return mid
    elif mid < arr[mid]:
      return find_fix(arr, inf, mid - 1)
    elif mid > arr[mid]:
      return find_fix(arr, mid + 1, sup)
  return -1

if __name__ == "__main__":
  print "TEST1 arr = [-10, -5, 0, 3, 7]"
  arr = [-10, -5, 0, 3, 7]
  print find_fix(arr, 0, len(arr))
