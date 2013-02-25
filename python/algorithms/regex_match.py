#! /usr/bin/python
# given a regex with ., *, .* and a string
# decide whether the string matches or not

def match(s, p):
  if len(s) == 0 and len(p) == 0:
    return True
  if len(s) == 0 and p[1] == '*':
    return match(s, p[2:])
  if len(p) == 0:
    return False

  if len(p) > 1 and p[1] == '*':
    if p[0] == '.' or s[0] == p[0]:
      return match(s[1:], p) or match(s, p[2:])
    return match(s, p[2:])

  if (p[0] == '.'):
    if (len(s) == 0):
      return False
    return match(s[1:], p[1:])

  if (s[0] != p[0]):
    return False

  return match(s[1:], p[1:])

if __name__ == "__main__":
  print match("abbcd", 'abbd')
