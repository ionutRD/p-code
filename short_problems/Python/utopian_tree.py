#!/usr/local/bin/python3

def height(n):
    if n == 0:
        return 1
    elif n & 1:
        return (1 << (((n + 1) >> 1) + 1)) - 2
    return (1 << ((n >> 1) + 1)) - 1

if __name__ == "__main__":
    num_cases = int(input())
    for i in range(num_cases):
        n = int(input())
        print(height(n))

