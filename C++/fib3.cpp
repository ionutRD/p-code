/**
 * @author: Ionut-Gabriel Radu
 * @date: 23 February 2013
 * @task
 * Write a function to compute
 * the nth fibonacci number
 */

#include <iostream>
#include <cmath>

#define PHI 1.6180339887
#define PSI -0.6180339887
#define SQRT5 2.2360679775

long long fib(int n)
{
  if (n == 0) {
    return 0;
  }

  if (n == 1) {
    return 1;
  }
  return (long long) ((pow(PHI, n) - pow(PSI, n)) / SQRT5);
}

int main(int argc, char** argv)
{
  std::cout << "fib(3) = " << fib(3) << std::endl;
  std::cout << "fib(9) = " << fib(9) << std::endl;
  std::cout << "fib(40) = " << fib(40) << std::endl;
  return 0;
}
