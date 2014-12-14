#!/usr/local/bin/python3

def altern_chars(s):
    count = 0
    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            count += 1
    return count

if __name__ == "__main__":
    num_cases = int(input())
    for i in range(num_cases):
        s = str(input())
        print(altern_chars(s))

