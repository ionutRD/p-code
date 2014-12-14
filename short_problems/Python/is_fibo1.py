#!/usr/local/bin/python3

def is_fibo(num):
    if num == 0 or num == 1:
        return True
    prev, crt = 0, 1
    while crt < num:
        tmp = crt
        crt = crt + prev
        prev = tmp

    return num == crt

if __name__ == "__main__":
    num_cases = int(input())
    for i in range(num_cases):
        num = int(input())
        if is_fibo(num):
            print("IsFibo")
        else:
            print("IsNotFibo")
