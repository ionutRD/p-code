#! /usr/bin/python
# Maximum subsequence sum in O(n) time in place

def max_subsequence_sum(arr):
  start_index = 0
  crt_sum = 0
  best_sum = float("-inf")
  for i in range(len(arr)):
    crt_sum += arr[i]
    if crt_sum < 0:
      crt_sum = 0
      start_index = i + 1
    if best_sum < crt_sum:
      best_sum = crt_sum

  return (best_sum, start_index)

if __name__ == "__main__":
  print "Test1: arr = [1, 2, -1, -3, 7, 1, -5]"
  arr = [1, 2, -1, -3, 7, 1, -5]
  (max_sum, st_index) = max_subsequence_sum(arr)
  print "Max sum is " + str(max_sum)
  print "Start index is " + str(st_index)
  print "Test1: arr = [1, 8, -1, -3, 7, 1, -5]"
  arr = [1, 8, -1, -3, 7, 1, -5]
  (max_sum, st_index) = max_subsequence_sum(arr)
  print "Max sum is " + str(max_sum)
  print "Start index is " + str(st_index)
