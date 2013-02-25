#! /usr/bin/python
# List all possible conversions of a number into the following
# system 1 <- 'a', 2 <- 'b', 3 <- 'c', ...

def az_translate(symtab, num):
  num = str(num)
  d = [[symtab[int(num[0])]]]
  n = len(num)

  for i in range(n)[1:]:
    aux = []
    for tr in d[i - 1]:
      aux.append(tr + symtab[int(num[i])])
    if (num[i - 1] == '1' or (int(num[i]) < 7 and num[i - 1] == '2')) \
        and i > 1:
      for tr in d[i - 2]:
        aux.append(tr + symtab[int(num[(i - 1):(i + 1)])])
    elif (num[i - 1] == '1' or (int(num[i]) < 7 and num[i - 1] == '2')) \
        and i == 1:
      aux.append(symtab[int(num[(i - 1):(i + 1)])])
    d.append(aux)

  return d[n - 1]
      

if __name__ == "__main__":
  symtab = {}
  for i in range(ord('z') - 95)[1:]:
    symtab[i] = chr(i + 96)
  print "Test1: n = 125"
  d = az_translate(symtab, 125)
  print d
  print "Test1: n = 125732"
  d = az_translate(symtab, 125732)
  print d
  print "Test1: n = 125521"
  d = az_translate(symtab, 125521)
  print d
