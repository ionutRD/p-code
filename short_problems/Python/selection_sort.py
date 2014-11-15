#!/usr/local/bin/python3

def selection_sort(coll):
    for i, _ in enumerate(coll):
        arg_min = min(enumerate(coll[i:]), key=lambda x : x[1])[0] + i
        coll[i], coll[arg_min] = coll[arg_min], coll[i]

if __name__ == "__main__":
    coll1 = [1, 5, 8, 0, 3]
    selection_sort(coll1)
    print(coll1)
    coll1 = [1]
    selection_sort(coll1)
    print(coll1)
    coll1 = []
    selection_sort(coll1)
    print(coll1)
