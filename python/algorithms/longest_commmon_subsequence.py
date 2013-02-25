#! /usr/bin/python
# Find the longest common subsequence of two strings
# For instance if a1 = abcdf and a2 = ecupdif, then
# the longest common subsequence is cdf
# Let L[i][j] be the longest common subsequence of strings
# a1[0..i] and a2[0..j] then L is defined as follows
# L[i][j] = 1 + L[i - 1][j - 1] if a1[i] = a2[j] or
# L[i][j] = max(L[i][j - 1], L[i - 1][j])
# The time complexity is O(mn) and the space complexity is
# O(mn)

def lcs(arr1, arr2):
  m = len(arr1)
  n = len(arr2)
  L = []
  for i in range(m):
    l = []
    for i in range(n):
      l.append(0)  
    L.append(l)

  for i in range(m):
    for j in range(n):
      if i == 0 or j == 0:
        L[i][j] = 0
      elif arr1[i] == arr2[j]:
        L[i][j] = 1 + L[i - 1][j - 1]
      else:
        L[i][j] = max(L[i - 1][j], L[i][j - 1])
  return L[m - 1][n - 1]

if __name__ == "__main__":
  print "Test1: arr1 = ['a', 'b', 'c', 'd', 'f']\narr2 = ['e', 'c', 'u', 'p', 'd', 'i', 'f']"
  arr1 = ['a', 'b', 'c', 'd', 'f']
  arr2 = ['e', 'c', 'u', 'p', 'd', 'i', 'f']
  print lcs(arr1, arr2)
