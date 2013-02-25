#! /usr/bin/python
# Givent two strings and 3 equal cost operations:
# R(eplace)
# D(elete)
# I(nsert)
# Find out the minimum number of operations to convert a given string
# into another

def edit_distance(arr1, arr2):
  m = len(arr1)
  n = len(arr2)
  E = []
  # Create the table
  for i in range(m):
    l = []
    for j in range(n):
      l.append(float("inf"))
    E.append(l)
  
  for i in range(m):
    for j in range(n):
      if j == 0:
        E[i][j] = i
      elif i == 0:
        E[i][j] = j
      else:
        E[i][j] = min(E[i][j - 1] + 1, \
                      E[i - 1][j] + 1, \
                      E[i - 1][j - 1] + int(arr1[i] != arr2[j]))

  return E[m - 1][n - 1]

if __name__ == "__main__":
  print "Test1: s1=sitin s2=seting"
  s1 = "sitin"
  s2 = "seting"
  print edit_distance(s1, s2)
