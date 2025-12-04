# Recursive Fibonacci: C vs C++

This repository compares the performance of C and C++ implementations of a naïve recursive Fibonacci function. The goal is to observe differences in recursion performance, compiler optimizations, and how features like const and constexpr influence execution in C++.

The recursive algorithm used here is intentionally expensive and grows exponentially with input size. This makes it suitable for stress-testing compilers and evaluating how C and C++ behave under heavy recursive workloads.

## Overview

The Fibonacci function is implemented in both C and C++ without memoization or iterative logic. This allows a direct comparison of how each language and compiler handles raw recursive calls.

The tests also examine:

- const vs constexpr in C++
- Lambda-based invocation in C++
- Differences in inlining and optimization
- Effects of high optimization flags

## Input Values

The recursion depth differs between languages due to performance constraints:

- C++ tests use `fib(50)`
- C tests use `fib(40)`

The C version is significantly slower at equivalent depths, so a higher input is used to create a comparable stress load.

## Performance Observations
### C++
Example output:

FIB C:
Time: 27.3913 seconds

FIB:
Time: 37.9183 seconds

### C
FIB C: 40

Time: 0.159000

FIB: 40

Time: 0.165000

These results show that optimized C++ recursion may outperform the C implementation, especially when constexpr rules or aggressive compiler optimizations are applied.

Actual performance varies based on:

- CPU architecture  
- Compiler version  
- Optimization flags  
- Inlining behavior  
- constexpr depth and evaluation limits  

## const vs constexpr in C++

- `const` ensures a variable cannot change at runtime but does not guarantee compile-time evaluation.
- `constexpr` attempts compile-time evaluation. If the expression cannot be fully resolved at compile time, it still runs at runtime.

The recursive Fibonacci in this project cannot always fully satisfy constexpr constraints for large values, but constexpr still affects optimization decisions.

C does not have constexpr, so all evaluation occurs at runtime.

## C vs C++ Differences

Key behavioral differences include:

1. C++ compilers often optimize small recursive functions more aggressively than C.
2. C lacks constexpr and template mechanisms that influence optimization.
3. Lambdas in C++ introduce no measurable overhead under -O3.
4. Inline expansion and link-time optimization behave differently across compilers.
5. The C++ version benefits from better constant-folding logic and deeper inlining heuristics.

## Compilation

### C++ build

```g++ test.cpp -o test.exe -std=c++20 -O3 -march=native -flto -ffast-math -static -static-libgcc -static-libstdc++```

### C build
```gcc main.c -o main.exe -O3 -march=native -flto -ffast-math -static -static-libgcc```

Both commands produce statically linked executables that run without external DLLs.

## Notes

This project does not aim to show the best way to compute Fibonacci numbers. The recursive implementation is intentionally inefficient to create a meaningful stress test.

The focus is on:

- compiler optimization behavior  
- constexpr limits  
- recursion depth performance  
- language-level differences in execution  

Additional benchmarks and extended tests may be added in future updates.
