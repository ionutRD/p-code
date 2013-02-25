#! /usr/bin/python

def valid(p):
  x = p[len(p) - 1]
  for i in range(len(p) - 1):
    if x == p[i]:
      return False
  return True

def permut(p, n):
  if len(p) == n and valid(p):
    print p
  else:
    for i in range(n):
      newp = p[:]
      newp.append(i)
      if valid(newp):
        permut(newp, n)

if __name__ == "__main__":
  newp = []
  permut(newp, 3)

