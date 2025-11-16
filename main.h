#pragma once

template <typename Function, typename Duration>
void run_for_time(Function f, Duration d)
{
  auto now = std::chrono::steady_clock::now;
  auto stop_time = now() + d;

  while (now() < stop_time)
  {
    f();
  };
}

void print_results(size_t fib);

void fibonacci(size_t &num, size_t &add, size_t &temp);

int find_fibonacci_number(size_t fib);