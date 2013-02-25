#! /usr/bin/python

def perm(lst):
  """ Calculate all permutations of a list """
  if lst == []:
    return [[]]
  if len(lst) == 1:
    return [[lst[0]]]
  res = perm(lst[1:])
  x = lst[0]
  new_res = []
  for l in res:
    for i in range(len(l) + 1):
      new_res.append(l[:i] + [x] + l[i:])
  return new_res

if __name__ == "__main__":
  print "Test1: All permutations of string [1,2,3] are"
  print perm([1,2,3])
  print "Test2: All permutations of string [] are"
  print perm([])
  print "Test3: All permutations of string [1] are"
  print perm([1])

