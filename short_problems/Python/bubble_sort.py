#!/usr/local/bin/python3

def bubble_sort(collection, comp=lambda x, y: x < y):
    sorted = False
    while not sorted:
        sorted = True
        for i, elem in enumerate(collection[:-1]):
            if not comp(elem, collection[i + 1]):
                collection[i], collection[i + 1] = collection[i + 1], collection[i]
                sorted = False

if __name__ == "__main__":
    coll1 = [1, 5, 8, 0, 3]
    bubble_sort(coll1)
    print(coll1)
    coll2 = [1]
    bubble_sort(coll2)
    print(coll2)
    coll3 = []
    bubble_sort(coll3)
    print(coll3)
