#include <iostream>
#include <chrono>

#include "main.h"

int main()
{
  size_t num = 0;
  size_t add = 1;
  size_t temp = 0;
  auto duration = std::chrono::seconds(1);

  auto fibonacci_lambda = [&num, &add, &temp]()
  {
    temp = num;
    num = num + add;
    add = temp;
  };

  run_for_time(fibonacci_lambda, duration);

  size_t fib = num;

  print_results(fib);
}

void fibonacci(size_t &num, size_t &add, size_t &temp)
{
  temp = num;
  num = num + add;
  add = temp;
}

int find_fibonacci_number(const size_t fib)
{
  size_t num = 0;
  size_t add = 1;
  size_t temp = 0;
  size_t fib_counter = 1; // 0 is the first Fibonacci number

  while (num != fib)
  {
    fibonacci(num, add, temp);
    fib_counter++;
  }

  return fib_counter;
}

void print_results(const size_t fib)
{
  size_t fib_num = find_fibonacci_number(fib);
  std::cout << "Calulated up to Fibonacci number " << fib_num << ", which is " << fib << ".\n";
}