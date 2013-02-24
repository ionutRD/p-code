/**
 * @author Ionut-Gabriel Radu
 * @date 10 February 2013
 * @task
 * Write a template function that performs the inner product
 * of two vectors
 */
#include <iostream>

template<class T>
int inner_product(const T* a, const T* b, int no_elem)
{
  int sum = 0;
  for (int i = 0; i < no_elem; i++) {
    sum += a[i] * b[i];
  }
  return sum;
}

int main(int argc, char** argv)
{
  int no_elem = 3;
  int a[] = {2, 1, -3};
  int b[] = {4, -1, 2};
  std::cout << "Test" << std::endl;
  std::cout << "a = {2, 1, -3}" << std::endl;
  std::cout << "b = {4, -1, 2}" << std::endl;
  std::cout << "The inner product is : "
            << inner_product<int>(a, b, no_elem)
            << std::endl;
  return 0;
}
