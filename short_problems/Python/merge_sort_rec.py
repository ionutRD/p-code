#!/usr/local/bin/python3

def merge(left_coll, right_coll, comp=lambda x, y: x < y):
    if not left_coll:
        return right_coll
    if not right_coll:
        return left_coll
    n = len(left_coll) + len(right_coll)
    merged_coll = [None] * n
    i, j, k = 0, 0, 0
    while i < len(left_coll) and j < len(right_coll):
        if (comp(left_coll[i], right_coll[j])):
            merged_coll[k] = left_coll[i]
            i += 1
        else:
            merged_coll[k] = right_coll[j]
            j += 1
        k += 1
    while i < len(left_coll):
        merged_coll[k] = left_coll[i]
        i, k = i + 1, k + 1
    while j < len(right_coll):
        merged_coll[k] = right_coll[j]
        j, k = j + 1, k + 1
    return merged_coll


def merge_sort(coll, comp=lambda x, y: x < y):
    if not coll or len(coll) <= 1:
        return coll
    left_coll = merge_sort(coll[:len(coll) >> 1], comp)
    right_coll = merge_sort(coll[len(coll) >> 1:], comp)
    return merge(left_coll, right_coll, comp)


if __name__ == "__main__":
    coll1 = [1, 5, 8, 0, 3]
    coll1 = merge_sort(coll1)
    print(coll1)
    coll2 = [1]
    coll2 = merge_sort(coll2)
    print(coll2)
    coll3 = []
    coll3 = merge_sort(coll3)
    print(coll3)
    coll4 = [3, 2, 1]
    coll4 = merge_sort(coll4)
    print(coll4)
    coll5 = [2, 1]
    coll5 = merge_sort(coll5)
    print(coll5)

