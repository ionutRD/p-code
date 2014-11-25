#!/usr/local/bin/python3

def insertion_sort(coll, comp=lambda x, y: x < y):
    for i, elem in enumerate(coll):
        j = i
        while j > 0 and comp(elem, coll[j - 1]):
            coll[j] = coll[j - 1];
            j -= 1
        coll[j] = elem;

if __name__ == "__main__":
    coll1 = [1, 5, 8, 0, 3]
    insertion_sort(coll1)
    print(coll1)
    coll2 = [1]
    insertion_sort(coll2)
    print(coll2)
    coll3 = []
    insertion_sort(coll3)
    print(coll3)
