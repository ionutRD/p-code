#! /usr/bin/python
# Generate all subsets of a given set

def all_subsets(arr):
  count = 1 << len(arr)
  while count > 0:
    aux = count
    subset = []
    for i in range(len(arr)):
      if aux & 1 == 1:
        subset.append(arr[i])
      aux >>= 1
    print subset
    count -= 1

if __name__ == "__main__":
  print "arr = [1, 2, 3]"
  arr = [1, 2, 3]
  all_subsets(arr)
