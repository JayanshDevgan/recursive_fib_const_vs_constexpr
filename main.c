#include <stdio.h>
#include <time.h>

clock_t begin, end;
double e_t;

const int fib(int n);

static inline int fib_c(int n);

void call_fib();

void call_fib_c();

void stamp_fn(void (*fn)());

int main() {
    stamp_fn(call_fib_c);
    stamp_fn(call_fib);
    return 0;
}

void stamp_fn(void (*fn)())
{
    begin = clock();
    fn();
    end = clock();
    e_t = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time: %f\n", e_t);
    return;
}

const int fib(int n)
{
    if (n <= 1) return n;
    return fib(n - 1) - fib(n - 2);
}

static inline int fib_c(int n)
{
    if (n <= 1) return n;
    return fib(n - 1) - fib(n - 2);
}

void call_fib()
{
    int v = 40;
    printf("FIB: %d\n", v);
    fib(v);
}

void call_fib_c()
{
    int v = 40;
    printf("FIB C: %d\n", v);
    fib_c(v);
}