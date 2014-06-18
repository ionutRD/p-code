"""
Bubble sort
"""
__author__ = 'Radu Ionut-Gabriel'

def bubble_sort_v1(arr):
    """
    @param arr: an array of comparable elements
    @return: the sorted array
    """
    sorted  = False
    while not sorted:
        sorted = True
        for i, elem in enumerate(arr[:-1]):
            if (elem > arr[i + 1]):
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                sorted = False
    return arr

if __name__ == "__main__":
    print(bubble_sort_v1([1, 4, 3, 2, 0, 7, 5, 12, 17, 8, 9]))
    print(bubble_sort_v1([1]))
    print(bubble_sort_v1([]))
    print(bubble_sort_v1([4, 3, 2, 1]))
