#! /usr/bin/python

def cons_dict(w):
  d = {}
  for ch in w:
    if d.has_key(ch) == True:
      d[ch] += 1
    else:
      d[ch] = 1
  return d

def valid(agr, d):
  newd = d.copy()
  for ch in agr:
    newd[ch] -= 1
    if newd[ch] < 0:
      return False
  return True

def all_anagrams(agr, w, d, n):
  if (len(agr) == n):
    print agr
  else:
    for ch in w:
      newagr = agr[:]
      newagr.append(ch)
      if valid(newagr, d) == True:
        all_anagrams(newagr, w, d, n)

if __name__ == "__main__":
  w = "aabaa"
  d = cons_dict(w)
  agr = []
  all_anagrams(agr, set(w), d, len(w))
