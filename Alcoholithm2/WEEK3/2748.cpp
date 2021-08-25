//https://www.acmicpc.net/problem/2748

#include <iostream>

long long     ft_fibo(int index)
{
    long long trace[91];

    trace[0] = 0;
    trace[1] = 1;
    for (int i = 2; i <= index; i++)
        trace[i] = trace[i - 1] + trace[i - 2];
    return trace[index];
}

int     main()
{
    int index;

    std::cin >> index;
    std::cout << ft_fibo(index);
}