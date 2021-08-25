#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int		main()
{
	int k;
	pair<int,int> rank[100000];		// int,int 형 배열을 100,000만큼 만듬.
	int res[20];					// 각 테스트케이스당 결과값을 저장할 배열

	cin >> k;

	for (int case_num = 0; case_num < k; case_num++) // testcase만큼 반복
	{
		int	n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> rank[i].first >> rank[i].second;
		sort(rank, rank + n);						// 서류심사 순위를 기준으로 오름차순 정렬

		// 순위는 숫자가 작을 수록 좋으며 앞의 지원자들보다 높은 면접 순위를 가져야함 
		int count = rank[0].second;		
		// 서류심사 순위 1등은 무조건 합격이며 
		// 이 사람의 면접 순위가 N이면 1(서류심사 1등) + (N - 1)(면접 순위 비교로 합격한 사람명 수)
		res[case_num] = count;	
	}

	for (int i = 0; i < k; i++)
		cout << res[i] << endl;
}

//다른 c++코드에 비해 느림 ..
