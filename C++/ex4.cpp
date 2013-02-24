/**
 * @author Ionut-Gabriel Radu
 * @date 10 February 2013
 * @task
 * Write a template function 'iota' that sets
 * a[i] = value + i, where 0 <= i < n
 */
#include <iostream>

template<class T>
void iota(const T& value, T* arr, int no_elem)
{
  for (int i = 0; i < no_elem; i++) {
    arr[i] = i + value;
  }
}

int main(int argc, char** argv)
{
  int i;
  int no_elem = 6;
  int value = 4;
  int arr[] = {1, 3, 7, 3, 2, 5};
  std::cout << "Test " << std::endl;
  std::cout << "value = 4" << std::endl;
  std::cout << "arr = {1, 3, 7, 3, 2, 5}" << std::endl;
  std::cout << "no_elem = 6" << std::endl;
  iota<int>(value, arr, no_elem);
  for (i = 0; i < no_elem - 1; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << arr[i] << std::endl;
  return 0;
}
