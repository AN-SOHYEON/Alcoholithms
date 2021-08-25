//https://www.acmicpc.net/problem/2156

//XXX

#include <iostream>

using namespace std;
int arr[10001];
int dp[10001];	//n번째까지 마신 포도주의 최대 양
int main()
{
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &arr[i]);    // 1번

    dp[0] = 0;   // 우리가 점화식에서 dp[n-3]까지 계산해야하니 0부터 시작해 2까지 채운다.
	dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];    // 2번
	
    for(int i=3; i<=n; i++)
    	dp[i] = max(dp[i-2]+arr[i], max(dp[i-3]+arr[i-1]+arr[i], dp[i-1]));   
		//               1.                     2.                   3.
		/* 3번 : 1. 지금 포도주를 마시고 이전 포도주를 안마신다.
				2. 지금 포도주를 마시고 이전 포도주도 먹지만 그 전전 포도주는 마시지 않는다.
				3. 지금 포도주를 안마시고, 이전 포도주와 전전 포도주를 마신다. 
		*/

	printf("%d",dp[n]);  // 4번
	return 0;
}