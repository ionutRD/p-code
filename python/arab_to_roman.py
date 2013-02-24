#! /usr/bin/python
# Convert an arab number into its roman equivalent

units = {1 : 'I',\
         2 : 'II',\
         3 : 'III',\
         4 : 'IV',\
         5 : 'V',\
         6 : 'VI',\
         7 : 'VII',\
         8 : 'VIII',\
         9 : 'IX'}

tens =  {1 : 'X',\
         2 : 'XX',\
         3 : 'XXX',\
         4 : 'LC',\
         5 : 'L',\
         6 : 'LX',\
         7 : 'LXX',\
         8 : 'LXXX',\
         9 : 'XC'}

hundreds = {1 : 'C',\
            2 : 'CC',\
            3 : 'CCC',\
            4 : 'CD',\
            5 : 'D',\
            6 : 'DC',\
            7 : 'DCC',\
            8 : 'DCCC',\
            9 : 'CM'}

def arab_to_roman(num):
  i = 0
  roman_list = []
  if num == 0:
    return 'O'
  
  while num != 0:
    cif = num % 10
    if cif != 0 and i < 3:
      if i == 0:
        roman_list.append(units[cif])
      elif i == 1:
        roman_list.append(tens[cif])
      elif i == 2:
        roman_list.append(hundreds[cif])
    elif i >= 3:
      roman_list.append(num * 'M')
    num = num / 10
    i += 1
  roman_list.reverse()
  return ''.join(roman_list)

if __name__ == "__main__":
  print "Test1: n = 1"
  print arab_to_roman(1)
  print "Test1: n = 66"
  print arab_to_roman(66)
  print "Test1: n = 749"
  print arab_to_roman(749)
  print "Test1: n = 1480"
  print arab_to_roman(1480)
  print "Test1: n = 10020"
  print arab_to_roman(10020)

