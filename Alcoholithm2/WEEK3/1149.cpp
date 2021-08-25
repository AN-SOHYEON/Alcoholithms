#include <iostream>
#include <algorithm>
using namespace std;

int dp[3][1010];
int color[3][1010];

int main() 
{
	int	n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &color[0][i], color[1][i], color[2][i]);
	}

	dp[0][0] = color[0][0];
	dp[1][0] = color[1][0];
	dp[2][0] = color[2][0];
	for (int i = 1; i < n; i++) 
	{
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + color[0][i]; 
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + color[1][i]; 
		dp[2][i] = min(dp[1][i - 1], dp[0][i - 1]) + color[2][i]; 
	}

	printf("%d", min(dp[0][n - 1], min(dp[1][n - 1], dp[2][n - 1])));
}
