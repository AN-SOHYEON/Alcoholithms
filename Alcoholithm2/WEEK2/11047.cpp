#include <iostream>

int		main()
{
	int	n;
	int res; 			// 총금액
	int kind[10]; 		// 동전의 종류를 넣을 배열
	int num_res = 0; 	// 동전 개수

	std::cin >> n >> res;
	for (int i = 0; i < n; i++)
		std::cin >> kind[i];

	int i = n - 1;		// 큰 단위부터 확인
	while (res > 0)		// 총금액에서 단위금액만큼 빼면서 num_res를 세고 res가 0이 될때까지 반복
	{
		if (res < kind[i])	// res가 현재 확인중인 단위금액보다 작으면 다음 단위금액으로 넘어감
			i--;
		else				// 아니면
		{
			res = res - kind[i];	// 단위금액만큼 빼고
			num_res++;				// 필요한 동전 개수 증가
		}
	}

	std::cout << num_res;
}
