#! /usr/bin/python

d = {0 : ['a','b'],
     1 : ['b','c','d'],
     2 : ['e','f','g'],
     3 : ['h','i','j'],
     4 : ['k','l','m'],
     5 : ['n', 'o', 'p'],
     6 : ['q','r','s'],
     7 : ['t','u'],
     8 : ['v','w'],
     9 : ['x','y','z']}

def initialize(phone_num, idx) :
  for cif in phone_num:
    idx.append(0)

def bkt(phone_num):
  idx = []
  initialize(phone_num, idx)
  st = []
  st.append(d[int(phone_num[0])][idx[0]])
  idx[0] += 1
  i = 1
  n = len(phone_num)
  while i >= 0:
    if (i == n):
      print st
      st.pop()
      i -= 1
    elif idx[i] == len(d[int(phone_num[i])]):
      idx[i] = 0
      if (len(st) > 0):
        st.pop()
      i -= 1
    else:
      st.append(d[int(phone_num[i])][idx[i]])
      idx[i] += 1
      i += 1

def bkt_rec(st, phone_num):
  if (len(st) == len(phone_num)):
    print st
  else:
    i = len(st);
    for ch in d[int(phone_num[i])]:
      newst = st[:]
      newst.append(ch)
      bkt_rec(newst, phone_num)

if __name__ == "__main__":
  pn = '0724432336'
  st = []
  bkt_rec(st,pn)



