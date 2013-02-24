/**
 * @author Ionut-Gabriel Radu
 * @date 10 February 2013
 * @task
 * Write a template function fill that sets a[start:end-1] to value
 * Test your code.
 */
#include <iostream>

template<class T>
void fill(const T& value, T* arr, int start, int end)
{
  if (start < 0) {
    start = 0;
  }
  for (int i = start; i < end; i++) {
    arr[i] = value;
  }
}

int main(int argc, char** argv)
{
  int i;
  int start = 2;
  int end = 6;
  int value = 5;
  int arr[] = {1, 2, 8, 3, 2, 7, 4, 11, 18, 26};
  std::cout << "Test " << std::endl;
  std::cout << "start = 2" << std::endl;
  std::cout << "end = 6" << std::endl;
  std::cout << "arr = {1, 2, 8, 3, 2, 7, 4, 11, 18, 26}" << std::endl;
  fill<int>(value, arr, start, end);
  for (i = 0; i < 9; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << arr[i] << std::endl;
  return 0;
}
