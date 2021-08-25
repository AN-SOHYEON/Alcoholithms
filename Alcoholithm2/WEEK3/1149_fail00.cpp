
#include <iostream>
using namespace std;

int	color[1010][3];
int	dp[1010];


int	find_min (int index, int front_color)
{
	if (front_color == 0)
	{	
		if (color[index][1] < color[index][2])
			return 1;
		else if (color[index][1] > color[index][2])
			return 2;
		else
		{
			if (color[index + 1][1] <= color[index + 1][2])
				return 2;
			else
				return 1;
		}
	}
	else if (front_color == 1)
	{
		if (color[index][0] < color[index][2])
 	        return 0;
		else if (color[index][0] > color[index][2])
 			return 2;
 		else
 		{
 			if (color[index + 1][0] <= color[index + 1][2])
 				return 2;
 			else
				return 0;
 		}
	}
	else 
	{
 		if (color[index][1] < color[index][0])
 			return 1;
 		else if (color[index][1] > color[index][0])
 			return 0;
 		else
 		{
 			if (color[index + 1][1] <= color[index + 1][0])
 				return 0;
 			else
 				return 1;
 		}
	}
}

int	main()
{
	int n, fc;

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &color[i][0], &color[i][1], &color[i][2]);

	dp[0] = min(color[0][0], min(color[0][1], color[0][2]));
	for (int i = 0; i < 3; i++)
	{
		if (color[0][i] == dp[0])
		{
			fc = i;
			break;
		}
	}

    int i;
	for (i = 1; i < n - 1; i++)
	{
		fc = find_min(i, fc);
		dp[i] = dp[i - 1] + color[i][fc];
	}

	if (fc == 0)
		dp[i] = dp[i - 1] + min(color[i][1], color[i][2]);
	else if (fc == 1)
		dp[i] = dp[i - 1] + min(color[i][0], color[i][2]);
	else if (fc == 2)
		dp[i] = dp[i - 1] + min(color[i][0], color[i][1]);

	
	cout << dp[i];
}
