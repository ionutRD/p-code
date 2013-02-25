#! /usr/bin/python
# Find the longest increasing subsequence of an array
# For example, if arr = [10, 22, 9, 33, 21, 50, 41, 60, 80], then
# the longest increasign subsequence is [10, 22, 33, 50, 60, 80]
# Let L[i] be the length of the longest increasing subsequence
# from 0 to i
# The optimal relation of L[i] is:
# L[i] = {1 + max(L[j]) : j < i and arr[j] < arr[i]} or 1 if
# no such maximum exist
# The time complexity is O(n^2) and the space complexity is O(n)

def longest_incr_subsequence(arr):
  L = []
  L.append(1)

  for i in range(1, len(arr)):
    maxl = float("-inf")
    for j in range(i - 1, -1, -1):
      if arr[j] < arr[i] and maxl < L[j]:
        maxl = L[j]
    if maxl == float("-inf"):
      L.append(1)
    else:
      L.append(1 + maxl)

  return max(L)

if __name__ == "__main__":
  print "Test1: arr = [1, 2, -1, -3, 7, 1, 5]"
  arr = [1, 2, -1, -3, 7, 1, 5]
  print longest_incr_subsequence(arr)
  print "Test2: arr = [10, 22, 9, 33, 21, 50, 41, 60, 80]"
  arr = [10, 22, 9, 33, 21, 50, 41, 60, 80]
  print longest_incr_subsequence(arr)
