#! /usr/bin/python
# Convert a roman number into the arab equivalent

symtab = {'I' : 1, 'V' : 5, 'X' : 10, 'L' : 50, 'C' : 100, 'D' : 500, 'M' : 1000, 'O' : 0}

def roman_to_arab(num):
  n = len(num)
  res = 0
  pre = 'O'
  for i in range(n - 1, -1, -1):
    if (symtab[num[i]] < symtab[pre]):
      res -= symtab[num[i]]
    else:
      res += symtab[num[i]]
    pre = num[i]
  return res

if __name__ == "__main__":
  print "Test for n = I"
  print roman_to_arab('I')
  print "Test for n = XXIV"
  print roman_to_arab('XXIV')
  print "Test for n = MMMCDXLIV"
  print roman_to_arab('MMMCDXLIV')
