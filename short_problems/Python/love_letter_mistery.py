#!/usr/local/bin/python

def find_min_operations(s):
    if len(s) == 0 or len(s) == 1:
        return 0
    inf, sup, count = 0, len(s) - 1, 0
    while inf < sup:
        count += abs(ord(s[inf]) - ord(s[sup]))
        inf += 1
        sup -= 1
    return count

if __name__ == "__main__":
    num_cases = int(input())
    for i in range(num_cases):
        s = str(input())
        print(find_min_operations(s))
