#! /usr/bin/python
# print all subsets of a set

def print_subsets(arr):
  n = 1 << len(arr)
  i = 0
  aux = []
  for i in range(len(arr)):
    aux.append(0)
  subset = []
  print subset
  while i < n:
    subset = []
    for j in range(len(arr)):
      if (aux[j] == 0):
        aux[j] = 1;
        break
      aux[j] = 0
    for j in range(len(arr)):
      if aux[j] == 1:
        subset.append(arr[j])
    print subset
    i += 1

if __name__ == "__main__":
  arr = [1,2,3,4,5,6]
  print_subsets(arr)

