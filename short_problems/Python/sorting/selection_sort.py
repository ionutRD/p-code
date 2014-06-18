"""
Selection sort
"""
__author__ = 'Radu Ionut-Gabriel'

def selection_sort_v1(arr):
    """
    @param arr: an array of comparable elements
    @return: the sorted array
    """
    for i, elem in enumerate(arr):
        min_idx = min(enumerate(arr[i:]), key=lambda x : x[1])[0]
        arr[i], arr[i + min_idx] = arr[i + min_idx], arr[i]
    return arr

if __name__ == "__main__":
    print(selection_sort_v1([1, 4, 3, 2, 0, 7, 5, 12, 17, 8, 9]))
    print(selection_sort_v1([1]))
    print(selection_sort_v1([]))
    print(selection_sort_v1([4, 3, 2, 1]))