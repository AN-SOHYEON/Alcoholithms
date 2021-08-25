#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int		main()
{
	int 		N;
	int 		M; 
	int 		want[100000];
	long long	sum = 0;
	int			i;

	scanf("%d %d", &M, &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &want[i]);
		sum = sum + want[i];	// 친구들이 원하는 개수 저장
	}

	sum = sum - M;		// 원하지만 못받는 개수 총합
	
	int  angry[100000];
	memset(angry, 0, N);
	i = 0;
	while (sum > 0)
	{
		if (want[i] > 0)
		{
			angry[i]++;
			sum--;
			want[i]--;
		}
		if (i == N - 1)
			i = 0;
		else
			i++;
	}

	sum = 0;
	for (int i = 0; i < N; i++)
		sum = sum + pow(angry[i], 2);

	cout << sum;
}

