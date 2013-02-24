/**
 * @author Ionut-Gabriel Radu
 * @date 10 February 2013
 * @task 
 * Write a template function 'count' that returns the number of
 * occurrences of value in the array a[0:n-1]. Test your code.
 */
#include <iostream>

template<class T>
int count(const T& elem, const T* arr, int no_elem)
{
  int occurrences = 0;
  for (int i = 0; i < no_elem; i++) {
    if (elem == arr[i]) {
      occurrences++;
    }
  }
  return occurrences;
}

int main(int argc, char** argv)
{
  int elem = 3;
  int arr[] = {1, 5, 3, -2, 3, 11, 26, 3};
  int no_elem = 8;
  std::cout << "Test:" << std::endl;
  std::cout << "elem = 3" << std::endl;
  std::cout << "arr = {1, 5, 3, -2, 3, 11, 26, 3}" << std::endl;
  std::cout << "occurrences = " << count<int>(elem, arr, no_elem) << std::endl;

  return 0;
}
