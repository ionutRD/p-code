/**
 * @author Ionut-Gabriel Radu
 * @date 23 February 2013
 * @task
 * Write a function that recursively
 * computes the permutation of a list
 */

#include <iostream>

template <class T>
int swap(T& a, T& b)
{
  T aux = a;
  a = b;
  b = aux;
}

template <class T>
void permutations(T* arr, int k, int m)
{
  if (k == m) {
    for (int i = 0; i < m; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  } else {
    for (int i = k; i < m; i++) {
      swap<T>(arr[k], arr[i]);
      permutations(arr, k + 1, m);
      swap<T>(arr[k], arr[i]);
    }
  }
}

int main(int argc, char** argv)
{
  int arr[] = {1, 2, 3, 4};
  permutations<int>(arr, 0, 4);
  return 0;
}
