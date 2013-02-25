#! /usr/bin/python

def find_longest_pal(string):
  """ Find the longest palidrome substring in O(n^2) time and O(1) space """
  max_pal = ''
  # Find all possible odd length palindromic substrings
  for i in range(len(string)):
    pal = string[i]
    for j in range(i - 1, -1, -1):
      k = (i << 1) - j
      if k >= len(string) or string[j] != string[k]:
        pal = string[j + 1 : k]
        break
      if string[j] == string[k]:
        pal = string[j : k + 1]
    if len(max_pal) < len(pal):
      max_pal = pal

  # Find all possible even length palindromic substrings
  for i in range(len(string) - 1):
    if string[i] == string[i + 1]:
      for j in range(i - 1, -1, -1):
        k = (i << 1) - j + 1
        if k > len(string) or string[j] != string[k]:
          pal = string[j + 1 : k]
          break
        if string[j] == string[k]:
          pal = string[j : k + 1]
      if len(max_pal) < len(pal):
        max_pal = pal
  return max_pal



if __name__ == "__main__":
  print "Test1: Longest palindrom subsequence of \'abadabu\'"
  print find_longest_pal('abadabu')
  print "Test2: Longest palindrom subsequence of \'eabbaccb\'"
  print find_longest_pal('eabbaccb')

