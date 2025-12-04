#include <iostream>
#include <chrono>
#include <functional>

const int fib(int n);
constexpr int fib_c(int n);

template <typename Func, typename... Args>
void stamp_fn(Func fn, Args... args);

int main()
{
    std::cout << "FIB C: " << std::endl;
    stamp_fn([](int v) { fib_c(v); }, 50);

    std::cout << "FIB: " << std::endl;
    stamp_fn([](int v) { fib(v); }, 50);

    return 0;
}

const int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) - fib(n - 2);
}

constexpr int fib_c(int n) {
    if (n <= 1) return n;
    return fib_c(n - 1) - fib_c(n - 2);
}

template <typename Func, typename... Args>
void stamp_fn(Func fn, Args... args)
{
    std::chrono::high_resolution_clock::time_point begin =
        std::chrono::high_resolution_clock::now();

    fn(args...);

    std::chrono::high_resolution_clock::time_point end =
        std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed =
        std::chrono::duration<double>(end - begin);

    std::cout << "Time: " << elapsed.count() << " seconds\n";
}
