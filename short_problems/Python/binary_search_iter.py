#!/usr/local/bin/python3

def binary_search_iter(collection, key, comp=lambda x, y : x < y):
    inf, sup = 0, len(collection) - 1
    while inf <= sup:
        mid = (inf + sup) // 2;
        mid_elem = collection[mid];
        if key == mid_elem:
            return True
        elif comp(key, mid_elem):
            sup = mid - 1
        else:
            inf = mid + 1
    return False

if __name__ == "__main__":
    coll1 = [1, 5, 7, 9, 13]
    key1 = 5
    print(binary_search_iter(coll1, key1))
    key1 = 4
    print(binary_search_iter(coll1, key1))
    key1 = 12
    print(binary_search_iter(coll1, key1))
    key1 = 13
    print(binary_search_iter(coll1, key1))
    coll1 = []
    print(binary_search_iter(coll1, key1))
    coll1 = [1, 5, 7, 9, 13, 15]
    key1 = 7
    print(binary_search_iter(coll1, key1))
