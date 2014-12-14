#!/usr/local/bin/python3

def find_digits(num):
    count = 0
    tmp = num
    while tmp != 0:
        digit = tmp % 10
        if digit != 0:
            count += int(num % digit == 0)
        tmp = tmp // 10

    return count

if __name__ == "__main__":
    num_cases = int(input())
    for i in range(num_cases):
        num = int(input())
        print(find_digits(num))
