"""
Insertion sort
"""
__author__ = 'Radu Ionut-Gabriel'

def insertion_sort_v1(arr):
    """
    @param arr: an array of comparable elements
    @return: the sorted array
    """
    for i, _ in enumerate(arr):
        j = i
        while j > 0:
            if arr[j] < arr[j - 1]:
                arr[j], arr[j - 1] = arr[j - 1], arr[j]
            j -= 1
    return arr

if __name__ == "__main__":
    print(insertion_sort_v1([1, 4, 3, 2, 0, 7, 5, 12, 17, 8, 9]))
    print(insertion_sort_v1([1]))
    print(insertion_sort_v1([]))
    print(insertion_sort_v1([4, 3, 2, 1]))
