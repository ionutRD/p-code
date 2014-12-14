#!/usr/local/bin/python3

def maximize_xor(left, right):
    xorred = left ^ right;
    num_bits = 0;
    while xorred != 0:
        xorred >>= 1
        num_bits += 1
    return (1 << num_bits) - 1

if __name__ == "__main__":
    left = int(input())
    right = int(input())
    print(maximize_xor(left, right))
