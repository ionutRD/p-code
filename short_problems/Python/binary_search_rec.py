#!/usr/local/bin/python3

def binary_search_rec_aux(collection, inf, sup, key, comp):
    if inf == sup or inf + 1 == sup:
        return False;
    mid = inf + (sup - inf) // 2
    if key == collection[mid]:
        return True
    elif comp(key, collection[mid]):
        return binary_search_rec_aux(collection, inf, mid, key, comp)
    else:
        return binary_search_rec_aux(collection, mid, sup, key, comp)

def binary_search_rec(collection, key, comp = lambda x, y : x < y):
    return binary_search_rec_aux(collection, 0, len(collection), key, comp)

if __name__ == "__main__":
    coll1 = [1, 5, 7, 9, 13]
    key1 = 5
    print(binary_search_rec(coll1, key1))
    key1 = 4
    print(binary_search_rec(coll1, key1))
    key1 = 12
    print(binary_search_rec(coll1, key1))
    key1 = 13
    print(binary_search_rec(coll1, key1))
    coll1 = []
    print(binary_search_rec(coll1, key1))
    coll1 = [1, 5, 7, 9, 13, 15]
    key1 = 7
    print(binary_search_rec(coll1, key1))

