#include <iostream>
#include <cstring>


int		main()
{
	int	N, S, R;
	int	team[12] = {1,1,1,1,1,1,1,1,1,1,1,1};

	scanf("%d %d %d", &N, &S, &R);
	int	b;
	for (int i = 0; i < S; i++)
	{
		scanf("%d", &b);
		team[b]--;
	}
	for (int i = 0; i < R; i++)
	{
		scanf("%d", &b);
		team[b]++;
	}

	for (int i = 1; i < N + 1; i++)
	{
		if (team[i] == 0)
		{
			if (team[i + 1] == 2)
			{	
				team[i]++;
				team[i + 1]--;
			}
			else if (team[i - 1] == 2)
			{
				team[i]++;
				team[i - 1]--;
			}
		}
	}
	
	int fail = 0;
	for (int i = 1; i < N + 1; i++)
	{
		if (team[i] == 0)	fail++;
	}

	std::cout << fail;
}
