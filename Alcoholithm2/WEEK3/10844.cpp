#include <iostream>

int dp[101][10];

int main()
{
    int N;

    scanf("%d", &N);

    dp[0][0] = 0;
    for (int j = 1; j < 10; j++)
        dp[0][j] = 1;

    int i;
    for (i = 1; i < N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                dp[i][0] = dp[i - 1][j + 1];
            else if (j == 9)
                dp[i][9] = dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];

            dp[i][j] %= 1000000000;
        }
    }

    int res;
    for (int j = 0; j < 10; j++)
        res = (res + dp[i][j]) % 1000000000;

    printf("%d", res);
}