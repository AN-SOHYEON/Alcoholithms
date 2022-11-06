// 라이브 코딩

#include <iostream>
#include <vector>

using namespace	std;

int	findNumberOfCoin(int n, int k, vector<int> &coin) {

	int count = 0;
	n--; // 배열 인덱스 맞추기 
	while (k && n >= 0) {
		if (coin[n] <= k) {
			count += k / coin[n];	// 지금 coin의 값이 k보다 작으면 coin으로 수를 나타낼 수 있음.
			k = k % coin[n];		// 지금 coin으로 나타내고 남은 k값
		}
		n--;
	}
	return count;
}

int main () {

	int n, k;
	cin >> n >> k;

	vector <int> coin(n);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	cout <<	findNumberOfCoin(n, k, coin) << "\n";
	return 0;
}
