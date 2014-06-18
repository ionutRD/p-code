"""
Merge sort
"""
__author__ = 'Radu Ionut-Gabriel'

def interleave(arr1, arr2):
    """
    @param arr1: a sorted array
    @param arr2: a sorted array
    @return: a sorted array composed by interleaving arr1 and arr2
    """
    if not arr1:
        return arr2
    if not arr2:
        return arr1
    i, j = 0, 0
    result = []
    while i < len(arr1) and j < len(arr2):
        if arr1[i] < arr2[j]:
            result.append(arr1[i])
            i += 1
        else:
            result.append(arr2[j])
            j += 1
    while i < len(arr1):
        result.append(arr1[i])
        i += 1
    while j < len(arr2):
        result.append(arr2[j])
        j += 1
    return result

def merge_sort_v1(arr):
    """
    @param arr: an array of comparable elements
    @return: the array in ascending order
    """
    if not arr or len(arr) == 1:
        return arr
    sorted_left = merge_sort_v1(arr[:len(arr) // 2])
    sorted_right = merge_sort_v1(arr[len(arr) // 2:])
    return interleave(sorted_left, sorted_right)

if __name__ == "__main__":
    print(merge_sort_v1([1, 4, 3, 2, 0, 7, 5, 12, 17, 8, 9]))
    print(merge_sort_v1([1]))
    print(merge_sort_v1([]))
    print(merge_sort_v1([4, 3, 2, 1]))

