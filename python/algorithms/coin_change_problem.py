#! /usr/bin/python
# Complexity O(mn), m number of coins n is the sum

def count(S, m, n):
  table = []
  for i in range(n + 1):
    l = []
    for j in range(m):
      l.append(0)
    table.append(l)
  
  for i in range(n + 1):
    for j in range(m):
      if i == 0:
        table[i][j] = 1
      else:
        if i - S[j] >= 0:
          x = table[i - S[j]][j]
        else:
          x = 0
        if j > 0:
          y = table[i][j - 1]
        else:
          y = 0
        table[i][j] = x + y
  
  return table[n][m - 1]

if __name__ == "__main__":
  n = 4
  S = [1, 2, 3]
  print count(S, len(S), n)
