#! /usr/bin/python
# Perform merge sort on an array

def comp(a, b):
  if a == b:
    return 0
  elif a < b:
    return -1
  else:
    return 1

def mergesort(arr, inf, sup, comp):
  if inf < sup:
    mid = (inf + sup) / 2
    mergesort(arr, inf, mid, comp)
    mergesort(arr, mid + 1, sup, comp)
    merge(arr, inf, mid, sup, comp)

def merge(arr, inf, mid, sup, comp):
  a = arr[:mid + 1]
  b = arr[mid + 1:]
  idxa = 0
  idxb = 0
  idx = 0
  while idxa < len(a) and idxb < len(b):
    if comp(a[idxa], b[idxb]) < 0:
      arr[idx] = a[idxa]
      idxa += 1
    else:
      arr[idx] = b[idxb]
      idxb += 1
    idx += 1

  while idxa < len(a):
    arr[idx] = a[idxa]
    idxa += 1
    idx += 1

  while idxb < len(b):
    arr[idx] = b[idxb]
    idxb += 1
    idx += 1

if __name__ == "__main__":
  print "TEST1: arr = [1, 8, 9, 100, 2, 3, 0, 4, 7]"
  arr = [1, 8, 9, 100, 2, 3, 0, 4, 7]
  mergesort(arr, 0, len(arr) - 1, comp)
  print arr
