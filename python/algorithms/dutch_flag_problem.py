#! /usr/bin/python
# Dutch flag problem

def dfp(arr):
  q = len(arr)
  p = -1
  i = 0
  while i < q:
    if arr[i] < 1:
      p += 1
      t = arr[i]
      arr[i] = arr[p]
      arr[p] = t
      i += 1
    elif arr[i] > 1:
      q -= 1
      t = arr[i]
      arr[i] = arr[q]
      arr[q] = t
    else:
      i += 1

if __name__ == "__main__":
  print "Test1: [0, 1, 1, 0, 1, 2, 1, 0, 1, 2, 2, 0]"
  arr = [0, 1, 1, 0, 1, 2, 1, 0, 1, 2, 2, 2, 0]
  dfp(arr)
  print arr
