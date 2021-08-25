#include <iostream>
#include <cmath>
#define MAX_S 32
#define MAX_L 15

int		g_a[MAX_L];
int		g_slash[MAX_S];
int		g_bslash[MAX_S];
int		g_num = 0;				//경우의 수

int		set(int i, int num)
{
	for (int j = 0; j < num; j++)
	{
		if (g_a[j] == 0 && g_slash[j + i] == 0 && g_bslash[i + (num - 1) - j] == 0)
		{
			if (i == (num - 1))
				g_num++;
			else
			{
				g_a[j] = g_slash[j + i] = g_bslash[i + (num - 1) - j] = 1;
				set(i + 1, num);
				g_a[j] = g_slash[j + i] = g_bslash[i + (num - 1) - j] = 0;
			}
		}
	}
	return (g_num);
}

int		main()
{
	int		n;
    int    num;
    
	std::cin >> num;
	n = set(0, num);
	std::cout << n;
	return (0);
}