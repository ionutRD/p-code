#! /usr/bin/python
# Calculate the median of two sorted arrays in O(log n)

def median_sorted(arr1, arr2):
  if len(arr1) == 2 and len(arr2) == 2:
    return (max(min(arr1),min(arr2)) + min(max(arr1), max(arr2))) / 2
  m1 = len(arr1) / 2
  m2 = len(arr2) / 2
  if arr1[m1] == arr2[m2]:
    return arr1[m1]
  elif arr1[m1] < arr2[m2]:
    return median_sorted(arr1[m1:], arr2[:m2 + 1])
  elif arr1[m1] > arr2[m2]:
    return median_sorted(arr1[:m1 + 1], arr2[m2:])

if __name__ == "__main__":
  print "TEST1 arr1 = [1, 12, 15, 26, 38], arr2 = [2, 13, 17, 30, 45]"
  arr1 = [1, 12, 15, 26, 38]
  arr2 = [2, 13, 17, 30, 45]
  print median_sorted(arr1, arr2)
