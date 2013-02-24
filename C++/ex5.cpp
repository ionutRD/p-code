/**
 * @author Ionut-Gabriel Radu
 * @date 23 February 2013
 * @task
 * Write a recursive function to test
 * if an element is in an array
 */

#include <iostream>

template <class T>
bool contains(const T& key, const T* arr, int n)
{
  if (n == 0) {
    return false;
  }

  if (arr[0] == key) {
    return true;
  }

  return contains(key, arr + 1, n - 1);
}

int main(int argc, char** argv)
{
  int arr[] = {1, 5, 6, 8, -1, 2};
  int n = 6;
  int m = 4;
  std::cout << "6 in {1, 5, 6, 8, -1, 2} ?: "
            << contains<int>(n, arr, 6)
            << std::endl;
  std::cout << "4 in {1, 5, 6, 8, -1, 2} ?: "
            << contains<int>(m, arr, 6)
            << std::endl;
  return 0;
}
