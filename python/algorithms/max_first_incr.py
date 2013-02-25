#! /usr/bin/python
# Find the maximum element in an array which is first increasing and then decreasing

def find_max_incr_decr(arr, inf, sup):
  if inf == sup:
    return arr[inf]
  if sup == inf + 1 and arr[inf] <= arr[sup]:
    return arr[sup]
  if sup == inf + 1 and arr[inf] > arr[sup]:
    return arr[inf]
  mid = (inf + sup) / 2
  if arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1]:
    return arr[mid]
  elif arr[mid] > arr[mid - 1] and arr[mid] < arr[mid + 1]:
    return find_max_incr_decr(arr, mid + 1, sup)
  elif arr[mid] < arr[mid - 1] and arr[mid] > arr[mid + 1]:
    return find_max_incr_decr(arr, inf, mid - 1)

if __name__ == "__main__":
  print "TEST1: arr = [8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1]"
  arr = [8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1]
  print find_max_incr_decr(arr, 0, len(arr) - 1)
  print "TEST2: arr = [1, 3, 50, 10, 9, 7, 6]"
  arr = [1, 3, 50, 10, 9, 7, 6]
  print find_max_incr_decr(arr, 0, len(arr) - 1)
  print "TEST3: arr = [10, 20, 30, 40, 50]"
  arr = [10, 20, 30, 40, 50]
  print find_max_incr_decr(arr, 0, len(arr) - 1)
  print "TEST3: arr = [10, 9, 8, 7, 6]"
  arr = [10, 9, 8, 7, 6]
  print find_max_incr_decr(arr, 0, len(arr) - 1)
