


int     fibo(int n, int a, int b)
{
    if (n == 0)
        return (a);
    if (n == 1)
        return (b);
    return (fibo(n - 1, b, a + b));    
}

int     ft_fibo(int index)
{
    if (index < 0)
        return (-1);
    return (fibo(index, 0, 1));
}
