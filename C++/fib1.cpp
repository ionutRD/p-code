/**
 * @author Ionut-Gabriel Radu
 * @date 23 February 2013
 * @task
 * Write a function that computes the nth fibonacci
 * number
 */

#include <iostream>

long long fib(int n)
{
  if (n == 0) {
    return 0;
  }

  if (n == 1) {
    return 1;
  }

  long long crt = 1;
  long long prev = 0;
  for (int i = 2; i <= n; i++) {
    int aux = crt;
    crt += prev;
    prev = aux;
  }

  return crt;
}

int main(int argc, char** argv)
{
  std::cout << "fib(3) = " << fib(3) << std::endl;
  std::cout << "fib(9) = " << fib(9) << std::endl;
  std::cout << "fib(40) = " << fib(40) << std::endl;
  return 0;
}
