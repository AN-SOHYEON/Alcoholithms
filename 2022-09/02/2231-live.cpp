#include <iostream>

using namespace std;

int	findNum(int n) {

	int num;	// 생성자 
	int sum;	// num을 통해서 n이 될 수 있는지 확인하기 위한 합
	int i;

	for (i = 0; i < n; i++) {
		num = i;
		sum = i;
		while (num) {
			sum += (num % 10);
			num /= 10;
		}
		// cout << sum << "\n";
		if (sum == n)
			break ;
		if (i == n-1) // if theres no Constructor, return 0
			return (0);
	}

	return (i);
}

int	main () {

	int n;
	cin >> n;

	cout << findNum(n);

	return 0;
}