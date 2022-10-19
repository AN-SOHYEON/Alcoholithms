#include <iostream>
#include <vector>

using namespace	std;

int	findNumberOfCoin(int n, int k, vector<int> &coin) {

	int count = 0;
	n--;
	while (k && n >= 0) {
		if (coin[n] < k) {
			count += k / coin[n];
			k = k % coin[n];
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

/////////이거는 왜 안되는지 모르겠다ㅏㅏㅏㅏㅏㅏㅏㅏㅏ