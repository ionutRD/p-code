#! /usr/bin/python
# Find the longest substring without repeating characters
# Ex: s = geeksforgeeks => eksforg or ksforge
# Time complexity is O(n + d), d = number of chars in the alphabet
# Space complexity O(d)

def longest_substring_without_rep(s):
  crt_start_index = 0
  start_index = 0
  best_length = float("-inf")
  trials = 0
  crt_length = 0
  n = len(s)
  chars = []
  for i in range(255):
    chars.append(0)
  for i in range(n):
    if chars[ord(s[i])] <= trials:
      crt_length += 1
      if best_length < crt_length:
        best_length = crt_length
        start_index = crt_start_index
    else:
      crt_length = 1
      crt_start_index = i
      trials += 1
    chars[ord(s[i])] += 1

  return s[start_index:start_index + best_length]

if __name__ == "__main__":
  s = "geeksforgeeks"
  print longest_substring_without_rep(s)
