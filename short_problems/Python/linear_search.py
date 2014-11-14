#!/usr/local/bin/python3

def linear_search(collection, key):
    return key in collection

if __name__ == "__main__":
    coll1 = [7, 2, 1, 5, 4, 3, -1]
    key1 = 1
    print(linear_search(coll1, key1))
    key1 = 6
    print(linear_search(coll1, key1))
