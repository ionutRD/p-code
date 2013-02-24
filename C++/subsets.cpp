/**
 * @author Ionut-Gabriel Radu
 * @date 23 February 2013
 * @task
 * Write a function to compute all
 * subsets of a given set
 */

#include <iostream>

template <class T>
void subsets(T* arr, int k, int m, bool* x)
{
  if (k == m) {
    for (int i = 0; i < m; i++) {
      if (x[i]) {
        std::cout << arr[i] << " ";
      }
    }
    std::cout << std::endl;
  } else {
    x[k] = true;
    subsets(arr, k + 1, m, x);
    x[k] = false;
    subsets(arr, k + 1, m, x);
  }
}

int main(int argc, char** argv)
{
  int arr[] = {1, 2, 3, 4};
  bool x[] = {0, 0, 0, 0};
  subsets<int>(arr, 0, 4, x);
  return 0;
}
